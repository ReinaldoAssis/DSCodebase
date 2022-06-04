#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./logger.h"

priorityQueue *newPriorityQueue()
{
    priorityQueue *fila = (priorityQueue *) malloc(sizeof(priorityQueue));
    fila->head = NULL;
    return fila;
}

void enqueue_sh(priorityQueue **filapt, int v, int p)
{
    priorityQueue *fila = *filapt;

    queueItem *item = (queueItem *)malloc(sizeof(queueItem));
    item->value = v;
    item->priority = p;

    printf("adding %d\n",v);

    if(fila->head == NULL)
    {
        fila->head = item;
        return;
    }

    if (fila->head != NULL && (p > fila->head->priority))
    {
        item->next = fila->head;
        fila->head = item;
    }
    else
    {
        queueItem *current = fila->head;
        while(current->next != NULL && current->next->priority > p)
            current = current->next;

        item->next = current->next;
        current->next = item;
    }
    
}

queueItem* dequeue_sh(priorityQueue *fila)
{
    if(fila->head == NULL)
    {
        printf("Priority queue underflow\n");
        return NULL;
    }
    queueItem *item = fila->head;
    fila->head = fila->head->next;
    item->next = NULL;
    return item;
}

//=================== Fila com heap ========================

heapQueue* newHeapQueue()
{
    heapQueue *heap = (heapQueue *) malloc(sizeof(heapQueue));
    heap->size = 0;
    return heap;
}

int get_parent_index(heapQueue *heap, int i)
{
    return i/2;
}

int get_left_index(heapQueue *heap, int i)
{
    return 2*i;
}

int get_right_index(heapQueue *heap, int i)
{
    return 2*i+1;
}

int item_of(heapQueue *heap, int i)
{
    return heap->data[i];
}

