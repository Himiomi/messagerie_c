#include "../../structure.h"

void add_contact(contact_profil *contactProfil){
    FILE * liste_contact_disponibles=NULL;
    liste_contact_disponibles=fopen("data/contacts.txt","a");
    fprintf(liste_contact_disponibles,
            "\n%s %s %d",
            contactProfil->list,
            contactProfil->ip,
            contactProfil->port);
    fclose(liste_contact_disponibles);
}
void supp_contact(){
    fclose(fopen("data/contacts.txt", "w"));
}