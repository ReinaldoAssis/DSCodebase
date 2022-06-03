

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
void enqueue_sh(priorityQueue *fila, int v, int p);
queueItem* dequeue_sh(priorityQueue *fila);