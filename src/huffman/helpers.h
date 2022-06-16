#ifndef helper_h
#define helper_h

#include <stdio.h>
#include "hufftree.h"


#define MAX_BYTES_TO_READ 100000000 //100 mb


// @param frequency: long long int array to store bytes frequencies
// @param f: file to count bytes from
void get_bytes_frequency(long long int *frequency, FILE *f);

//@param input: file to be compressed
//@param path: output path
void *compress(FILE *input, char *path);

//@param input: file to be decompressed
//@param output: output file stream
void *decompress(FILE *input, FILE *output);

//======================================

//HASH TABLE

typedef struct hashnode
{
    unsigned char byte;
    long long int frequency;
    unsigned int code;
    int level;
} hashnode;

typedef struct hashtable
{
    hashnode *table[256];
} hashtable;

//@param h: hashtable to print
void print_hashtable(hashtable *h);

//@param h: hashtable
//@param byte: key to the hashtable
//@param frequency: frequency of the byte
//@param code: huffman code to be assigned
//@param level: depth in the tree
void put_hashtable(hashtable *h, unsigned char byte, long long int frequency, unsigned int code, int level);

//@return new hashtable
hashtable *newhashtable();

//@return new hashnode
hashnode *newhashnode();

/*
@param tb: hashtable
@param key: byte/key
@return hashnode
*/
hashnode* get_hashtable(hashtable *tb, unsigned char key);

#endif