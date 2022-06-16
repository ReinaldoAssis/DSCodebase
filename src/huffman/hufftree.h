#ifndef hufftree_h
#define hufftree_h

#include "priorityQ.h"
#include <stdio.h>
#include <stdbool.h>


//Creates a new huffman tree node
//@param frequency: byte frequency/priority
//@param value: byte value
//@param left: left branch
//@param right: right branch
//@return hufftree_node root
hufftree_node *new_hufftree_node(long long int frequency, unsigned char value, hufftree_node *left, hufftree_node *right);

//Builds the huffman tree from a priority queue
//@param heap: priority queue
//@return hufftree_node root
hufftree_node *parse_to_tree(huffheapQueue *heap);

//writes huffman tree to file
//@param root: huffman tree
//@param f: output file
void write_hufftree(hufftree_node *root, FILE *f);

//finds huffman tree size
//@param root: huffman tree
//@param size: pointer to long long int
void find_hufftree_size(hufftree_node *root, long long int *size);

//checks if node is a leaf
//@param node: huffman tree node
//@return bool
bool is_leaf(hufftree_node *node);

#endif