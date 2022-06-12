#ifndef helper_h
#define helper_h

#include <stdio.h>
#include "hufftree.h"


#define MAX_BYTES_TO_READ 100000000 //100 mb


// @param frequency: long long int array to store bytes frequencies
// @param f: file to count bytes from
void get_bytes_frequency(long long int *frequency, FILE *f);

//@param f: file to be compressed
//@param path: output path
void *compress(FILE *f, char *path);

//======================================

//HASH TABLE

typedef struct hashnode
{
    hufftree_node *node;
    unsigned char code;
    int size;
} hashnode;

typedef struct hashtable
{
    hashnode *table[256];
} hashtable;

void print_hashtable(hashtable *h);

void put_hashtable(hashtable *h, hufftree_node *node, unsigned char code, int size);

hashtable *newhashtable();

hashnode *newhashnode();

hashnode* get_hashtable(hashtable *tb, unsigned char key);

#endif