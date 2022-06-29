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
    typedef struct contact_profil contact_profil;

    struct contact_profil{
        char *list;
        int ip[4];
    };

    typedef struct list_contact list_contact;
    struct list_contact{
        int size;
        contact_profil ** contact;
    };
#endif