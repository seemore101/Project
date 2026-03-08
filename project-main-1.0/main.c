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

    logical_addresses = read_address(argv[1]);
    
    if (logical_addresses == NULL){
        fprintf(stderr,"Address Unavailable. File %s is empty or unreadable.\n",argv[1]);
        return 2;
    }

    find_page(logical_addresses);
    find_offset(logical_addresses);



    /** check_TLB - If function yields 0, initialize page table, else initate translate() 
     * and PhysicalStorage
     */
    
    return 0;
}

