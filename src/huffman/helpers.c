#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "helpers.h"
#include "priorityQ.h"
#include "hufftree.h"

//HASH TABLE

hashnode *newhashnode()
{
    hashnode *node = (hashnode*)malloc(sizeof(hashnode));
    node->code = NULL;
    node->node = NULL;
    node->size = -1;
    return node;
}

hashtable *newhashtable()
{
    hashtable *h = (hashtable*)malloc(sizeof(hashtable));
    for(int i=0; i<256; i++)
        h->table[i] = NULL;
    return h;
}

void put_hashtable(hashtable *h, hufftree_node *node, unsigned char code, int size)
{
    hashnode *nd = (hashnode*)malloc(sizeof(hashnode));
    nd->code = code;
    nd->node = node;
    nd->size = size;
    h->table[code] = nd;
}

hashnode* get_hashtable(hashtable *tb, unsigned char key)
{
    return tb->table[key];
}

void print_hashtable(hashtable *h)
{
    for(int i=0; i<256; i++)
    {
        if(h->table[i] != NULL)
            printf("%d|%02X\n",i,h->table[i]);
    }
}

//====================================

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
        printf("%c ", huff_dequeue(heap)->value);
    printf("\n");
}

char* generate_huffcodes(hufftree_node *root, char **code)
{
    if(root != NULL){
        printf("node %c\n",root->value);
        if(is_leaf(root))
        {
            if(root->value == '*' || root->value == '\\')
            {
                sprintf(*code,"\\%c",root->value);
            }else
            {
                sprintf(*code,"%c",root->value);
            }
            printf("ERA PRA RETORNAR\n");
            return;
        }
        
        if(root->left != NULL){
            *code += sprintf(*code,"%s0",*code);
            generate_huffcodes(root->left,code);
        }
        if(root->right != NULL)
        {
            *code += sprintf(*code,"%s1",*code);
            generate_huffcodes(root->right,code);
        }

    }
}

void *compress(FILE *f, char *path)
{
    long long int frequency[256] = {0};
    get_bytes_frequency(frequency,f);

    huffheapQueue *heap = newHuffQueue();
    
    unsigned char value;
    for(int i=0; i<256; i++)
    {
        value = (unsigned char)i;
        if(frequency[i] > 0)
        {
            //printf("enqueue %c\n",value);
            huff_enqueue(heap,value,frequency[i]);
        }
    }

    //DEBUG
    //print_huffqueue(heap);

    printf("Finished bytes heap queue.\n");

    hufftree_node *root = parse_to_tree(heap);
    
    FILE *output = fopen("hufftreeoutput.txt","w");
    write_hufftree(root,output);
    fclose(output);

    printf("Finished parsing the huffman tree.\n");

    long long int tree_size = 0;
    find_hufftree_size(root,&tree_size);

    free(heap);

    //TODO: habilitar modificacao da extensao
    //usar .fzip - apenas como demonstracao
    char extension[5] = ".huff";

    strcat(path, extension);

    //resultado da compresssao
    FILE *result = fopen(path,"w");
    int trashlen = 0;

    // char code[100000];
    // generate_huffcodes(root,&code);
    // printf("codesx %s\n",code);
}

