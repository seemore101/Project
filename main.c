// This file calls the functions

#include <stdio.h>
#include <stdlib.h>

int* logical_addresses;
int* page;
int* offset;

int main(int argc, char *argv[]){

    if (argc < 2){
        fprintf(stderr,"SYNOPSIS: %s <file name>\n",argv[0]);
        return 1;
    }

    int *addresses = read_address(argv[1]);

    if (addresses == NULL){
        fprintf(stderr,"Address file could not be read.\n");
        return 2;
    }

    for(int i = 0; i < 1000; i++){

        int logical = addresses[i];

        int page = find_page(logical);
        int offset = find_offset(logical);

        printf("Logical: %d Page: %d Offset: %d\n",
               logical, page, offset);
    }

    free(addresses);

    return 0;
}
