#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "helpers.h"

void get_bytes_frequency()
{
    FILE *f = fopen("./test.txt","r");
    
    if(f != NULL)
    {
        unsigned char buffer[4096];
        size_t sz;
        while((sz = fread(buffer, 1, sizeof(buffer), f)) > 0)
        {
            for(int i = 0; i < sz; i++)
                //printf("%d", buffer[i]);
                //or use "%02X" instead, for printing the byte values:
                printf("%02X ", buffer[i]);
        }
        printf("\n");

    }else
    {
        printf("Algo de errado aconteceu ao tentar abrir o arquivo :(\n");
    }

}