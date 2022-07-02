#ifndef STRUCTURE
    #define STRUCTURE
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>
    #include <string.h>
    #include <netinet/in.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <pthread.h>

    #define CONTACT "data/contacts.txt"
    #define PROFIL "data/profil.txt"
    #define PSEUDO "data/pseudo.txt"

    typedef struct contact_profil contact_profil;

    struct contact_profil{
        char *list;
        char *ip;
        int port;
    };

    typedef struct list_contact list_contact;
    struct list_contact{
        int size;
        contact_profil ** contact;
    };

    typedef struct profil_utilisateur profil_utilisateur;
    struct profil_utilisateur{
        char * nom_profil;
        char * pseudo;
        int port;
    };

    typedef struct list_profil_utilisateur list_profil_utilisateur;
    struct list_profil_utilisateur{
        profil_utilisateur ** list;
        int size;
    };
#endif