#include "priorityQ.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(hufftree_node **x, hufftree_node **y) {
    hufftree_node *aux = *x;
    *x = *y;
    *y = aux;
}

huffheapQueue* newHuffQueue()
{
    huffheapQueue *heap = (huffheapQueue *) malloc(sizeof(huffheapQueue));
    heap->size = 0;
    
    for(int i=0; i<MAX_HUFF_Q; i++)
        heap->items[i] = NULL;

    //heap->items[0] = newHeapNode('0',INT_MIN);

    return heap;
}

hufftree_node* newHeapNode(char value, int priority)
{
    hufftree_node *node = (hufftree_node*)malloc(sizeof(hufftree_node));
    node->value = value;
    node->frequency = priority;
    return node;
}

int huff_get_parent_index(huffheapQueue *heap, int i)
{
    //return i/2;
    return i >> 1; //int div
}

int huff_get_left_index(huffheapQueue *heap, int i)
{
    return i << 1;
}

int huff_get_right_index(huffheapQueue *heap, int i)
{
    return (i << 1)+1;
}

hufftree_node* huff_item_of(huffheapQueue *heap, int i)
{
    return heap->items[i];
}

void huff_enqueue(huffheapQueue *heap, char value, int priority)
{
    if(heap->size >= MAX_HUFF_Q)
    {
        printf("Huffman Queue Overflow.\n");
        return;
    }
    else
    {
        heap->items[++heap->size] = newHeapNode(value,priority);
        int key_index = heap->size;
        int parent_index = heap->size >> 1;

        while(parent_index >= 1 && heap->items[key_index]->frequency < heap->items[parent_index]->frequency)
        {
            // printf("atual %d parent %d\n",heap->items[key_index]->priority,heap->items[parent_index]->priority);
            // printf("swap\n");
            swap(&heap->items[key_index],&heap->items[parent_index]);
            key_index = parent_index;
            parent_index = key_index >> 1;
        }

        
    }

}

void huff_enqueue_from_node(huffheapQueue *heap, hufftree_node *node)
{
    if(heap->size >= MAX_HUFF_Q)
    {
        printf("Huffman Queue Overflow.\n");
        return;
    }
    else
    {
        heap->items[++heap->size] = node;
        int key_index = heap->size;
        int parent_index = heap->size >> 1;

        while(parent_index >= 1 && heap->items[key_index]->frequency < heap->items[parent_index]->frequency)
        {
            // printf("atual %d parent %d\n",heap->items[key_index]->priority,heap->items[parent_index]->priority);
            // printf("swap\n");
            swap(&heap->items[key_index],&heap->items[parent_index]);
            key_index = parent_index;
            parent_index = key_index >> 1;
        }

        
    }
}

hufftree_node* huff_dequeue(huffheapQueue *heap)
{
    if(heap->size <= 0)
    {
        printf("Huffman heap underflow!\n");
        return NULL;
    }
    hufftree_node *item = heap->items[1];
    heap->items[1] = heap->items[heap->size];
    --heap->size;
    min_heapify_huff(heap,1);
    return item;
}

void min_heapify_huff(huffheapQueue *heap, int i)
{
    int max;
    int left = i << 1;
    int right = (i << 1) +1;

    if(left <= heap->size && heap->items[left]->frequency < heap->items[i]->frequency){
        max = left;
    }
    else max = i;   
        
    
    if(right <= heap->size && heap->items[right]->frequency < heap->items[max]->frequency)
    {
        max = right;
    }


    if(heap->items[i]->frequency != heap->items[max]->frequency)
    {
        swap(&heap->items[i],&heap->items[max]);
        min_heapify_huff(heap,max);
    }
}

//ÁREA DE TESTE

//implementação de fila de prioridade com linked list
//fila sem heap
// typedef struct huffpriorityQueue
// {
//     hufftree_node *head;
// } huffpriorityQueue;

// void huff_enqueue_sh(huffpriorityQueue *q, char value, int priority)
// {

//     huffpriorityQueue *fila = q;

//     hufftree_node *item = (hufftree_node *)malloc(sizeof(hufftree_node));
//     item->value = value;
//     item->frequency = priority;

//     if(fila->head == NULL)
//     {
//         fila->head = item;
//         return;
//     }

//     if (fila->head != NULL && (priority > fila->head->frequency))
//     {
//         item->next = fila->head;
//         fila->head = item;
//     }
//     else
//     {
//         queueItem *current = fila->head;
//         while(current->next != NULL && current->next->priority > p)
//         {
//             current = current->next;
//         }

//         item->next = current->next;
//         current->next = item;
//     }
// }