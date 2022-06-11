#include "hufftree.h"
#include <stdio.h>

hufftree_node *new_hufftree_node(long long int frequency, unsigned char value, hufftree_node *left, hufftree_node *right)
{
    hufftree_node *node = (hufftree_node*)malloc(sizeof(hufftree_node));
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    node->value = value;
    return node;
}

// hufftree_node *hufftree_node_from_q(heapq_node *heapnode)
// {
//     hufftree_node *node = (hufftree_node*)malloc(sizeof(hufftree_node));
//     node->frequency = heapnode->priority;
//     node->left = NULL;
//     node->right = NULL;
//     node->value = heapnode->value;
//     return node;
// }

hufftree_node *parse_to_tree(huffheapQueue *heap)
{
    unsigned char rootchar = '*';
    hufftree_node *root;
    while(heap->size != 1)
    {
        hufftree_node *left = huff_dequeue(heap);
        hufftree_node *right = huff_dequeue(heap);
        long long int soma = left->frequency+right->frequency;
        root = new_hufftree_node(soma,rootchar,left,right);
        huff_enqueue(heap,root);
    }
    return root;
}