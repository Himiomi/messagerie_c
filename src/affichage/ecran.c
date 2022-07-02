#include "../../Includes/affichage/ecran.h"
#include "../../Includes/affichage/color.h"
#include "../../Includes/file_manipulation/reading_file.h"
#include "../../Includes/initializer/init_struct.h"
#include "../../Includes/file_manipulation/add_in_file.h"
#include "../../Includes/file_manipulation/read_pseudo.h"
#include "../../Includes/reseau/communication.h"
#include "../../Includes/affichage/to_string.h"
#include "../../Includes/thread/service.h"

void clear_buffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
        printf("lu:%c\n",c);
    }
}

void liste_possibilite(){
    printf(CYAN1"Que souhaitez faire ?\n"DEFAULT);
    printf("1. Charger ses contacts\n");
    printf("2. Ajouter un contact\n");
    printf("3. Supprimer un contact\n");
    printf("4. Modifier un contact\n");
    printf("5. Envoyer un message\n");
    printf("6. Consulter les messages recu\n");
    printf("7. Quitter cette super app ? ;-;\n");
    printf("8. Afficher les profils\n");
    printf("9. Activer un profil\n");
    printf("10. Envoyer un message\n");
}

void accueil(){

    int choix_menu=0;
    pthread_t thread_id[10];
    printf("Lecture contact...\n");
    list_contact *liste_contact_content=liste_contact_reading();
    printf("Vos contacts sont désormais:\n");
    display_list_contact(liste_contact_content);
    printf("Lecture profils...\n");
    list_profil_utilisateur *listProfilUtilisateur=lecture_profil_utilisateur();
    printf("Vos profils sont:\n");
    display_list_profil(listProfilUtilisateur);
    printf(RED1"Bienvenu dans votre messagerie pour terminal :D\n"DEFAULT);
    do{
        choix_menu=0;
        printf("%d\n",choix_menu);
        liste_possibilite();
        scanf("%d", &choix_menu);
        printf("passage\n");
        switch (choix_menu) {
            case 1:
                printf("=======================\n");
                printf("CHARGEMENT DES CONTACTS\n");
                liste_contact_content=liste_contact_reading();
                printf("    CONTACTS CHARGES :)\n");
                printf("=======================\n");
                printf("VOS CONTACTS SONT:\n");
                display_list_contact(liste_contact_content);
                break;
            case 2:
                printf("Ajout d'un nouveau contact\n");
                contact_profil * nouveau_contact = init_contact_profil();
                printf("Veillez entrer le nom de votre contact\n");
                scanf("%s",nouveau_contact->list);
                printf("Veillez entrer l'ip de votre nouveau contact\n");
                scanf("%s",nouveau_contact->ip);
                printf("Veillez entrer le port de votre nouveau contact\n");
                scanf("%d",&(nouveau_contact->port));
                printf("Ajout de %s %s %d\n",nouveau_contact->list,nouveau_contact->ip,nouveau_contact->port);
                add_contact(nouveau_contact);
                liste_contact_content=liste_contact_reading();
                printf("Vos contacts sont désormais:\n");
                display_list_contact(liste_contact_content);
                break;
            case 3:
                printf("Entrez le nom du contact que vous souhaitez supprimer parmis:");
                char * supp_contact_name=malloc(100* sizeof(char));
                for(int i=0;i<liste_contact_content->size;i++){
                    printf("\t-[%s]\n",
                           liste_contact_content->contact[i]->list);
                }
                scanf("%s",supp_contact_name);
                supp_contact();
                for(int i=0;i<liste_contact_content->size;i++){
                    if(!strcmp(liste_contact_content->contact[i]->list,supp_contact_name)){
                        printf("Le contact existe, il va maintenant être supprimé\n");
                    }else{
                        printf("Contact conservé: %s\n",liste_contact_content->contact[i]->list);
                        add_contact(liste_contact_content->contact[i]);
                    }
                }
                liste_contact_content=liste_contact_reading();
                printf("Vos contacts sont désormais:\n");
                for(int i=0;i<liste_contact_content->size;i++){
                    printf("\t-[%s]->[%s:%d]\n",
                           liste_contact_content->contact[i]->list,
                           liste_contact_content->contact[i]->ip,
                           liste_contact_content->contact[i]->port);
                }
                break;
            case 4:
                printf("Changement d'ip pour un contact\n");
                printf("Veillez choisir le contact dont vous voulez modifier l'ip parmis:\n");
                char * select_contact=malloc(100* sizeof(char));
                contact_profil *nouveau_contacte=init_contact_profil();
                display_list_contact(liste_contact_content);
                scanf("%s",select_contact);
                printf("Quelle est sa nouvelle ip ?\n");
                scanf("%s",nouveau_contacte->ip);
                strcpy(nouveau_contacte->list,select_contact);
                supp_contact();
                for(int i=0;i<liste_contact_content->size;i++){
                    if (strcmp(liste_contact_content->contact[i]->list, select_contact)) {
                        add_contact(liste_contact_content->contact[i]);
                    }
                }
                add_contact(nouveau_contacte);
                break;
            case 5:
                break;
            case 6:
                break;
            case 8:
                printf("La liste des profils disponibles:\n");
                display_list_profil(listProfilUtilisateur);
                break;
            case 9:
                printf("Liste des profils disponibles:\n");
                display_list_profil(listProfilUtilisateur);
                printf("Quel numéro de profil voulez-vous ?\n");
                int numero_choisi=-1;
                scanf("%d",&numero_choisi);
                if(numero_choisi>listProfilUtilisateur->size||numero_choisi<0){
                    printf("Ce numero n'existe pas\n");
                }else{
                    printf("Le profil %s %s %d va s'activer\n",
                            listProfilUtilisateur->list[numero_choisi]->nom_profil,
                            listProfilUtilisateur->list[numero_choisi]->pseudo,
                            listProfilUtilisateur->list[numero_choisi]->port);
                    pthread_create(&thread_id[0], NULL, ecoute,(void*)&listProfilUtilisateur->list[numero_choisi]->port);
                }
                break;
            case 10:
                printf("Liste des contacts disponibles:\n");
                display_list_contact(liste_contact_content);
                printf("Quel numéro de contact voulez-vous ?\n");
                int numero_contact;
                scanf("%d",&numero_contact);

                if(numero_contact>liste_contact_content->size||numero_contact<0){
                    printf("Ce numero n'existe pas\n");
                }else {
                    printf("Le message à %s va être envoyé\n",liste_contact_content->contact[numero_contact]->list);
                    int retour=client(liste_contact_content->contact[numero_contact]->ip,
                           liste_contact_content->contact[numero_contact]->port,
                           "coucou");
                    printf("retour=%d\n",retour);

                }
                break;
            case 0:
                choix_menu=1;
                clear_buffer();
                break;
            default:
                printf("Désolé mais le choix %d n'est pas encore disponible, créez le alors :p\n",choix_menu);
                break;
        }

    }while(choix_menu!=7);
}