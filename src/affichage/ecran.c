#include "../../Includes/affichage/ecran.h"
#include "../../Includes/affichage/color.h"
#include "../../Includes/file_manipulation/reading_file.h"
#include "../../Includes/initializer/init_struct.h"
#include "../../Includes/file_manipulation/add_in_file.h"
void liste_possibilite(){
    printf(CYAN1"Que souhaitez faire ?\n"DEFAULT);
    printf("1. Charger ses contacts\n");
    printf("2. Ajouter un contact\n");
    printf("3. Supprimer un contact\n");
    printf("4. Modifier un contact\n");
    printf("5. Envoyer un message\n");
    printf("6. Consulter les messages recu\n");
    printf("7. Quitter cette super app ? ;-;\n");
}

void accueil(){
    int choix_menu=0;
    list_contact *liste_contact_content= init_list_contact();
    printf(RED1"Bienvenu dans votre messagerie pour terminal :D\n"DEFAULT);
    do{
        choix_menu=0;
        while(choix_menu<1||choix_menu>7) {
            liste_possibilite();
            scanf("%d", &choix_menu);
            switch (choix_menu) {
                case 1:
                    printf("=======================\n");
                    printf("CHARGEMENT DES CONTACTS\n");
                    liste_contact_content=liste_contact_reading();
                    printf("    CONTACTS CHARGES :)\n");
                    printf("=======================\n");
                    printf("VOS CONTACTS SONT:\n");
                    for(int i=0;i<liste_contact_content->size;i++){
                        printf("\t-[%s]->[%d.%d.%d.%d]\n",
                               liste_contact_content->contact[i]->list,
                               liste_contact_content->contact[i]->ip[0],
                               liste_contact_content->contact[i]->ip[1],
                               liste_contact_content->contact[i]->ip[2],
                               liste_contact_content->contact[i]->ip[3]);
                    }
                    break;
                case 2:
                    printf("Ajout d'un nouveau contact\n");
                    contact_profil * nouveau_contact = init_contact_profil();
                    char * nouvel_ip= malloc(100* sizeof(char));
                    printf("Veillez entrer le nom de votre contact\n");
                    scanf("%s",nouveau_contact->list);
                    printf("Veillez entrer l'ip de votre nouveau contact\n");
                    scanf("%s",nouvel_ip);
                    int retour_sscanf=sscanf(nouvel_ip,
                           "%d.%d.%d.%d",
                           &(nouveau_contact->ip[0]),
                           &(nouveau_contact->ip[1]),
                           &(nouveau_contact->ip[2]),
                           &(nouveau_contact->ip[3]));
                    printf("retour_sscanf=%d\nnom=%s\nip=%d.%d.%d.%d\n",
                           retour_sscanf,
                           nouveau_contact->list,
                           nouveau_contact->ip[0],
                           nouveau_contact->ip[1],
                           nouveau_contact->ip[2],
                           nouveau_contact->ip[3]);
                    add_contact(nouveau_contact);
                    liste_contact_content=liste_contact_reading();
                    printf("Vos contacts sont désormais:\n");
                    for(int i=0;i<liste_contact_content->size;i++){
                        printf("\t-[%s]->[%d.%d.%d.%d]\n",
                               liste_contact_content->contact[i]->list,
                               liste_contact_content->contact[i]->ip[0],
                               liste_contact_content->contact[i]->ip[1],
                               liste_contact_content->contact[i]->ip[2],
                               liste_contact_content->contact[i]->ip[3]);
                    }
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
                        printf("\t-[%s]->[%d.%d.%d.%d]\n",
                               liste_contact_content->contact[i]->list,
                               liste_contact_content->contact[i]->ip[0],
                               liste_contact_content->contact[i]->ip[1],
                               liste_contact_content->contact[i]->ip[2],
                               liste_contact_content->contact[i]->ip[3]);
                    }
                    break;
                case 4:
                    printf("Changement d'ip pour un contact\n");
                    printf("Veillez choisir le contact dont vous voulez modifier l'ip parmis:\n");
                    char * select_contact=malloc(100* sizeof(char));
                    char * nouvelle_ip= malloc(100* sizeof(char));
                    contact_profil *nouveau_contacte=init_contact_profil();
                    for(int i=0;i<liste_contact_content->size;i++){
                        printf("\t-[%s]->[%d.%d.%d.%d]\n",
                               liste_contact_content->contact[i]->list,
                               liste_contact_content->contact[i]->ip[0],
                               liste_contact_content->contact[i]->ip[1],
                               liste_contact_content->contact[i]->ip[2],
                               liste_contact_content->contact[i]->ip[3]);
                    }
                    scanf("%s",select_contact);
                    printf("Quelle est sa nouvelle ip ?\n");
                    scanf("%s",nouvelle_ip);
                    sscanf(nouvelle_ip,
                           "%d.%d.%d.%d",
                           &(nouveau_contacte->ip[0]),
                           &(nouveau_contacte->ip[1]),
                           &(nouveau_contacte->ip[2]),
                           &(nouveau_contacte->ip[3]));
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
                    printf("quit okay\n");
                case 6:
                    break;
                default:
                    printf("Désolé mais votre choix n'est pas encore disponible, créez le alors :p\n");
                    break;
            }
        }
    }while(choix_menu!=7);
}