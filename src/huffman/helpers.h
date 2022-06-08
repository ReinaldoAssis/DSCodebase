
#define MAX_BYTES_TO_READ 100000000 //100 mb
#define MAX_HEAP_SIZE 10000000

void get_bytes_frequency();

//======================================

//PRIORITY QUEUE

typedef struct binaryheapQueue
{
    int size;
    char data[MAX_HEAP_SIZE];
} binaryheapQueue;

binaryheapQueue *newHeapQueue();

void enqueue_heap(binaryheapQueue *heap, char item, int *comparacoes);

char dequeue_heap(binaryheapQueue *heap);

int get_parent_index(binaryheapQueue *heap, int i);

int get_left_index(binaryheapQueue *heap, int i);

int get_right_index(binaryheapQueue *heap, int i);

void min_heapify(binaryheapQueue *heap, int i);

char item_of(binaryheapQueue *heap, int i);

void runQueueBenchmarking();