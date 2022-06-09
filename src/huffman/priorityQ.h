#define MAX_HUFF_Q 257

//PRIORITY QUEUE

typedef struct heapq_node
{
    int priority;
    char value;
} heapq_node;

typedef struct huffheapQueue
{
    int size;
    heapq_node *items[MAX_HUFF_Q];
} huffheapQueue;

huffheapQueue *newHuffQueue();

heapq_node* newHeapNode(char value, int priority);

void huff_enqueue(huffheapQueue *heap, char value, int priority);

heapq_node* huff_dequeue(huffheapQueue *heap);

int huff_get_parent_index(huffheapQueue *heap, int i);

int huff_get_left_index(huffheapQueue *heap, int i);

int huff_get_right_index(huffheapQueue *heap, int i);

void min_heapify_huff(huffheapQueue *heap, int i);

heapq_node* huff_item_of(huffheapQueue *heap, int i);

void swap(heapq_node **x, heapq_node **y);