#include "../../structure.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
contact_profil * init_contact_profil(){
    contact_profil * contactProfil = malloc(sizeof(contact_profil));
    contactProfil->list= malloc(100*sizeof(char));
    contactProfil->ip= malloc(100*sizeof(char));
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

profil_utilisateur * init_profil_utilisateur(){
    profil_utilisateur * nouveau_profil= malloc(sizeof(profil_utilisateur));
    nouveau_profil->pseudo= malloc(100*sizeof(char));
    nouveau_profil->nom_profil= malloc(100*sizeof(char));
    nouveau_profil->port=0;
    return nouveau_profil;
}

list_profil_utilisateur * init_list_profil_utilisateur(){
    list_profil_utilisateur * nouvelle_liste= malloc(sizeof(list_profil_utilisateur*));
    nouvelle_liste->list= malloc(100* sizeof(profil_utilisateur));
    for(int i=0;i<100;i++){
        nouvelle_liste->list[i]=init_profil_utilisateur();
    }
    nouvelle_liste->size=0;
    return nouvelle_liste;
}