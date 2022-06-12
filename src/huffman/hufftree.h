#ifndef hufftree_h
#define hufftree_h

#include "priorityQ.h"
#include <stdio.h>
#include <stdbool.h>

// typedef struct hufftree_node
// {
//     long long int frequency;
//     unsigned char value;
//     struct hufftree_node *left;
//     structhufftree_node *right;

// } hufftree_node;

//Creates a new huffman tree node
hufftree_node *new_hufftree_node(long long int frequency, unsigned char value, hufftree_node *left, hufftree_node *right);

//Builds the huffman tree from a priority queue
hufftree_node *parse_to_tree(huffheapQueue *heap);

void write_hufftree(hufftree_node *root, FILE *f);

void find_hufftree_size(hufftree_node *root, long long int *size);

bool is_leaf(hufftree_node *node);

#endif