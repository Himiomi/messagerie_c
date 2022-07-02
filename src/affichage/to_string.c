#include "../../Includes/affichage/to_string.h"

void display_list_contact(list_contact * listContact){
    for(int i=0;i<listContact->size;i++){
        printf("\t%d: %s->[%s:%d]\n",
               i,
               listContact->contact[i]->list,
               listContact->contact[i]->ip,
               listContact->contact[i]->port
               );
    }
}
void display_list_profil(list_profil_utilisateur * listProfilUtilisateur){
    for(int i=0;i<listProfilUtilisateur->size;i++) {
        printf("\t%d: %s %s %d\n",
               i,
               listProfilUtilisateur->list[i]->nom_profil,
               listProfilUtilisateur->list[i]->pseudo,
               listProfilUtilisateur->list[i]->port);
    }
}