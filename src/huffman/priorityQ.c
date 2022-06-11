#include "priorityQ.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(heapq_node **x, heapq_node **y) {
    heapq_node *aux = *x;
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

heapq_node* newHeapNode(char value, int priority)
{
    heapq_node *node = (heapq_node*)malloc(sizeof(heapq_node));
    node->value = value;
    node->priority = priority;
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

heapq_node* huff_item_of(huffheapQueue *heap, int i)
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

        while(parent_index >= 1 && heap->items[key_index]->priority < heap->items[parent_index]->priority)
        {
            // printf("atual %d parent %d\n",heap->items[key_index]->priority,heap->items[parent_index]->priority);
            // printf("swap\n");
            swap(&heap->items[key_index],&heap->items[parent_index]);
            key_index = parent_index;
            parent_index = key_index >> 1;
        }

        
    }

}

heapq_node* huff_dequeue(huffheapQueue *heap)
{
    if(heap->size <= 0)
    {
        printf("Huffman heap underflow!\n");
        return NULL;
    }
    heapq_node *item = heap->items[1];
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

    if(left <= heap->size && heap->items[left]->priority < heap->items[i]->priority){
        max = left;
    }
    else
    {
        max = i;
    }

    if(right <= heap->size && heap->items[right]->priority < heap->items[max]->priority)
    {
        max = right;
    }

    if(heap->items[i]->priority != heap->items[max]->priority)
    {
        swap(&heap->items[i],&heap->items[max]);
        min_heapify_huff(heap,max);
    }
}
