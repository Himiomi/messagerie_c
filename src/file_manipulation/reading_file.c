#include "../../Includes/file_manipulation/reading_file.h"
#include "../../Includes/initializer/init_struct.h"
list_contact * liste_contact_reading(){
    list_contact *liste_contact_content= init_list_contact();
    FILE * liste_contact_file=NULL;
    int retour=0;

    liste_contact_file= fopen("data/contacts.txt","r");
    if(liste_contact_file!=NULL){
        while ((retour = fscanf(liste_contact_file,
                                "%s %d.%d.%d.%d",
                                liste_contact_content->contact[liste_contact_content->size]->list,
                                &(liste_contact_content->contact[liste_contact_content->size]->ip[0]),
                                &(liste_contact_content->contact[liste_contact_content->size]->ip[1]),
                                &(liste_contact_content->contact[liste_contact_content->size]->ip[2]),
                                &(liste_contact_content->contact[liste_contact_content->size]->ip[3])
                                ))&& (retour > 0)) {
            liste_contact_content->size++;
        }
    }else{
        printf("ERROR OPEN FILE");
    }
    printf("Il y a eu %d contact de lu\n",liste_contact_content->size);
    fclose(liste_contact_file);
    return liste_contact_content;
}