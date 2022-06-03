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

void enqueue_sh(priorityQueue *fila, int v, int p)
{
    queueItem *item = (queueItem *)malloc(sizeof(queueItem));
    item->value = v;
    item->priority = p;

    if(fila->head == NULL)
    {
        fila->head = item;
        return;
    }

    if (fila->head != NULL || (p > fila->head->priority))
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

