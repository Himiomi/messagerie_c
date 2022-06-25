#include "../../structure.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
contact_profil * init_contact_profil(){
    contact_profil * contactProfil = malloc(sizeof(contact_profil));
    contactProfil->list= malloc(100*sizeof(char));
    return contactProfil;
}

list_contact * init_list_contact(){
    list_contact * listContact = malloc(100*sizeof(list_contact));
    listContact->contact= malloc(100*sizeof(contact_profil*));
    for(int i=0;i<100;i++){
        listContact->contact[i]=init_contact_profil();
    }
    listContact->size=0;
    return listContact;
}
