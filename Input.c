
}#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>


int* read_address(char* filename){

    FILE *file = fopen(filename, "r");

    if (file == NULL){
        return NULL;
    }

    int *addresses = malloc(sizeof(int) * 1000);

    for (int i = 0; i < 1000; i++){
        fscanf(file, "%d", &addresses[i]);
    }

    fclose(file);

    return addresses;
}

int * find_page(int* address){
    int pageNumber;

    // casts pointer to an integer
    uintptr_t add = (uintptr_t)address;

    pageNumber = (add >> 8) & 0x00FF;

    return pageNumber;
    
}

int * find_offset(int* address){

    int offset;

    uintptr_t add = (uintptr_t)address;

    offset = (logical_addresses & 0x00FF);
 
    return offset
}



