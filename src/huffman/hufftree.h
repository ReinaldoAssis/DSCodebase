#ifndef hufftree_h
#define hufftree_h

#include "priorityQ.h"

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

#endif