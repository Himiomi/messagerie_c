#include "../../Includes/file_manipulation/read_pseudo.h"

char * read_pseudo(){
    FILE * file_pseudo=NULL;
    file_pseudo=fopen("data/pseudo.txt","r");
    char * pseudo=malloc(100* sizeof(char));
    fprintf(file_pseudo,"%s",pseudo);
    return pseudo;
}