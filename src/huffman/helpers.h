
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

binaryheapQueue *newBinaryQueue();

void binary_enqueue(binaryheapQueue *heap, char item, int *comparacoes);

char binary_dequeue(binaryheapQueue *heap);

int binary_get_parent_index(binaryheapQueue *heap, int i);

int binary_get_left_index(binaryheapQueue *heap, int i);

int binary_get_right_index(binaryheapQueue *heap, int i);

void binary_min_heapify(binaryheapQueue *heap, int i);

char binary_item_of(binaryheapQueue *heap, int i);