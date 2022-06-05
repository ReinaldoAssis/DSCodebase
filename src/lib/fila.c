#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include "./logger.h"

#include <time.h>

priorityQueue *newPriorityQueue()
{
    priorityQueue *fila = (priorityQueue *) malloc(sizeof(priorityQueue));
    fila->head = NULL;
    return fila;
}

void enqueue_sh(priorityQueue **filapt, int v, int p, int *comparacoes)
{
    bool comp = comparacoes != NULL;

    priorityQueue *fila = *filapt;

    queueItem *item = (queueItem *)malloc(sizeof(queueItem));
    item->value = v;
    item->priority = p;

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
        {
            if(comp) *comparacoes+=1;
            current = current->next;
        }

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

void swap(int* a, int* b)
{
    int *aux = a;
    *a = *b;
    *b = *aux;
}

void enqueue_heap(heapQueue *heap, int item, int *comparacoes)
{
    bool comp = comparacoes != NULL;

    if (heap->size >= MAX_HEAP_SIZE) {
        
        printf("Heap overflow!\n");
        exit(1);

    } else {

        heap->data[++heap->size] = item;

        int key_index = heap->size;
        int parent_index = get_parent_index(heap, heap->size);

        //parent_index >= i.e 'enquando não for a root'
        while (parent_index >= 1 &&
        heap->data[key_index] > heap->data[parent_index]) {
            if(comp) *comparacoes+=1;

            //a função swap estava se comportando de alguma forma errada
            //fazendo o swap 'manualmente' aqui dentro da função resolveu o problema
            //swap(&heap->data[key_index], &heap->data[parent_index]);
            int aux = heap->data[key_index];
            heap->data[key_index] = heap->data[parent_index];
            heap->data[parent_index] = aux;
            key_index = parent_index;
            parent_index = get_parent_index(heap, key_index);

        }
    }
}


void max_heapify(heapQueue *heap, int i)
{
    int largest;
    int left_index = get_left_index(heap, i);
    int right_index = get_right_index(heap, i);

    if (left_index <= heap->size && heap->data[left_index] > heap->data[i]) 
    {
        largest = left_index;
    } 
    else 
        largest = i;

    if (right_index <= heap->size && heap->data[right_index] > heap->data[largest]) 
        largest = right_index;
    
    if (heap->data[i] != heap->data[largest]) 
    {
        //swap(&heap->data[i], &heap->data[largest]);
        int aux = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = aux;
        max_heapify(heap, largest);
    }
}

int dequeue_heap(heapQueue *heap)
{
    if (heap->size <= 0) {
        printf("Heap underflow!\n");
        return -1;
    }
    
    int item = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;

    // printf("Max heapify em %d\n",heap->data[1]);

    max_heapify(heap, 1);
    return item;
   
}

//roda testes aleatorios e salva em um arquivo
void runQueueBenchmarking()
{
    srand(time(NULL));

    int testes=1000;
    int maxrand=20000;

    FILE *fheap = criar_stream("../HeapQmarking.txt",NULL);

    FILE *f = criar_stream("../LinkedQmarking.txt",NULL);
    for(int k=0; k<testes; k++)
    {
        int size = rand()%maxrand;

        priorityQueue *linkedq = newPriorityQueue();

        int comps = 0;
        
        for(int i=0; i<size; i++)
        {
            enqueue_sh(&linkedq,rand()%maxrand,rand()%maxrand,&comps);
        }

        char st[1000];
        sprintf(st,"%d %f\n", size, (double)comps/size);

        escrever_str(f,st);

    }

    encerrar_stream(f);

    maxrand = 2000;

    for(int k=0; k<testes; k++)
    {
        int comps=0;
        int size = rand()%maxrand;


        
        double media=0;
        for(int h=0; h<100; h++)
        {
            heapQueue *heap = newHeapQueue();
            comps=0;
            for(int i=0; i<size; i++){
                enqueue_heap(heap,rand()%maxrand,&comps);
            }
            media += (double)comps/size;
        }

        media /= 100;
        char st[1000];

        sprintf(st,"%d %f\n", size, media);
        escrever_str(fheap,st);
    }

    encerrar_stream(fheap);
}