#include "hufftree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

hufftree_node *new_hufftree_node(long long int frequency, unsigned char value, hufftree_node *left, hufftree_node *right)
{
    hufftree_node *node = (hufftree_node*)malloc(sizeof(hufftree_node));
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    node->value = value;
    return node;
}

hufftree_node *parse_to_tree(huffheapQueue *heap)
{
    unsigned char rootchar = '*';
    hufftree_node *root;
    while(heap->size != 1)
    {
        hufftree_node *left = huff_dequeue(heap);
        hufftree_node *right = huff_dequeue(heap);
        //printf("pop l %c r %c\n",left->value,right->value);
        long long int soma = left->frequency+right->frequency;

        if(right->value == '*' && left->value != '*' && left->frequency == right->frequency)
        {
            root = new_hufftree_node(soma,rootchar,right,left);
        }
        else if(right->value != '*' && left->value != '*' && left->frequency == right->frequency)
        {
            root = new_hufftree_node(soma,rootchar,right,left);
        }
        else
        {
            root = new_hufftree_node(soma,rootchar,left,right);
        }

        huff_enqueue_from_node(heap,root);
    }
    return root;
}

// hufftree_node *parse_to_tree(huffheapQueue *heap)
// {
//     unsigned char rootchar = '*';
//     hufftree_node *root;
//     while(heap->size != 1)
//     {
//         hufftree_node *left = huff_dequeue(heap);
//         hufftree_node *right = huff_dequeue(heap);
//         //printf("pop l %c r %c\n",left->value,right->value);
//         long long int soma = left->frequency+right->frequency;

//         root = new_hufftree_node(soma,rootchar,left,right);

//         huff_enqueue_from_node(heap,root);
//     }
//     return root;
    
// }

bool is_leaf(hufftree_node *node)
{
    return node->left == NULL && node->right == NULL;
}

void find_hufftree_size(hufftree_node *root, long long int *size)
{
    if(root != NULL)
    {
        if(is_leaf(root))
        {
            if(root->value == '*' || root->value == '\\'){
                *size+=1;
            }
        }
        *size+=1;
        find_hufftree_size(root->left,size);
        find_hufftree_size(root->right,size);
    }
}

void write_hufftree(hufftree_node *root, FILE *f)
{
    if(root != NULL)
    {
        if(is_leaf(root))
        {
            if(root->value == '*' || root->value == '\\')
            {
                fprintf(f,"\\%c",root->value); //precisamos colocar o char de escape
            }
            else
            {
                fprintf(f,"%c",root->value);
            }
        } 
        else
        {
            fprintf(f,"%c",root->value);
            write_hufftree(root->left,f);
            write_hufftree(root->right,f);

        }
    }
}