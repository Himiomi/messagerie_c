#include "../../Includes/file_manipulation/reading_file.h"
#include "../../Includes/initializer/init_struct.h"
list_contact * liste_contact_reading(){
    list_contact *liste_contact_content= init_list_contact();
    FILE * liste_contact_file=NULL;
    int retour=0;

    liste_contact_file= fopen("data/contacts.txt","r");
    if(liste_contact_file!=NULL){
        while ((retour = fscanf(liste_contact_file,
                                "%s %s %d",
                                liste_contact_content->contact[liste_contact_content->size]->list,
                                (liste_contact_content->contact[liste_contact_content->size]->ip),
                                &(liste_contact_content->contact[liste_contact_content->size]->port)
                                )
                )&& (retour > 0)) {
            liste_contact_content->size++;
        }
    }else{
        printf("ERROR OPEN FILE");
    }
    fclose(liste_contact_file);
    return liste_contact_content;
}

list_profil_utilisateur * lecture_profil_utilisateur(){
    list_profil_utilisateur * nouvelle_list_profil=init_list_profil_utilisateur();
    FILE * liste_profil=NULL;
    liste_profil= fopen(PROFIL,"r");
    int retour=0;
    if(liste_profil!=NULL){
        while ((retour = fscanf(liste_profil,
                                "%s %s %d",
                                nouvelle_list_profil->list[nouvelle_list_profil->size]->nom_profil,
                                nouvelle_list_profil->list[nouvelle_list_profil->size]->pseudo,
                                &(nouvelle_list_profil->list[nouvelle_list_profil->size]->port)
        ))&& (retour > 0)) {
            nouvelle_list_profil->size++;
        }
    }else{
        printf("ERROR OPEN FILE");
    }
    return nouvelle_list_profil;
}