#include "../../structure.h"

void add_contact(contact_profil *contactProfil){
    FILE * liste_contact_disponibles=NULL;
    liste_contact_disponibles=fopen("data/contacts.txt","a");
    fprintf(liste_contact_disponibles,
            "\n%s %d.%d.%d.%d",
            contactProfil->list,
            contactProfil->ip[0],
            contactProfil->ip[1],
            contactProfil->ip[2],
            contactProfil->ip[3]);
    fclose(liste_contact_disponibles);
}
void supp_contact(){
    fclose(fopen("data/contacts.txt", "w"));
}