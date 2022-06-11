#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "helpers.h"
#include "priorityQ.h"

void print_bytes()
{
    FILE *f = fopen("./huffman.txt","r");
    
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

void print_bytes_frequency()
{
    FILE *f = fopen("./huffman.txt","r");

    long long int frequency[256] = {0};
    get_bytes_frequency(frequency,f);

    for(int i=0; i<256; i++)
    {
        printf("%d %ld\n",i,frequency[i]);
    }
}

void get_bytes_frequency(long long int *frequency, FILE *f)
{
    unsigned char byte;
    while(fscanf(f,"%c",&byte) != EOF)
        frequency[byte]++;
}

void print_huffqueue(huffheapQueue *heap)
{
    printf("Estado da heap\n");
    for(int i=1; i<=heap->size; i++)
        printf("%c ",huff_dequeue(heap)->value);
    printf("\n");
}

void *compress(FILE *f)
{
    long long int frequency[256] = {0};
    get_bytes_frequency(frequency,f);

    huffheapQueue *heap = newHuffQueue();
    
    unsigned char value;
    for(int i=0; i<256; i++)
    {
        value = (unsigned char)i;
        if(frequency[i] > 0)
            huff_enqueue(heap,value,frequency[i]);
    }

    //DEBUG
    //print_huffqueue(heap);

    printf("Finished bytes heap queue.\n");

}

