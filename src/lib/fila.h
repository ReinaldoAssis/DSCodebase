#define MAX_HEAP_SIZE 10000000

//implementação de fila de prioridade com linked list
typedef struct queueItem 
{
    int value;
    int priority;
    struct queueItem *next;
} queueItem;

//fila sem heap
typedef struct priorityQueue
{
    queueItem *head;
} priorityQueue;

priorityQueue *newPriorityQueue();

//enqueue na fila sem heap
void enqueue_sh(priorityQueue **fila, int v, int p, int *comparacoes);

queueItem* dequeue_sh(priorityQueue *fila);


//==================================================

void swap(int *a, int *b);

typedef struct heapQueue
{
    int size;
    int data[MAX_HEAP_SIZE];
} heapQueue;

heapQueue *newHeapQueue();

void enqueue_heap(heapQueue *heap, int item, int *comparacoes);

int dequeue_heap(heapQueue *heap);

int get_parent_index(heapQueue *heap, int i);

int get_left_index(heapQueue *heap, int i);

int get_right_index(heapQueue *heap, int i);

void max_heapify(heapQueue *heap, int i);

int item_of(heapQueue *heap, int i);

void heapsort(heapQueue *heap);

void runQueueBenchmarking();