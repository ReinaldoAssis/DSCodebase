
#ifndef priorityq_h
#define priorityq_h

#define MAX_HUFF_Q 257

typedef struct hufftree_node
{
    long long int frequency;
    unsigned char value;
    struct hufftree_node *left;
    struct hufftree_node *right;

} hufftree_node;

//PRIORITY QUEUE

// typedef struct heapq_node
// {
//     long long int priority;
//     unsigned char value;

// } heapq_node;

typedef struct huffheapQueue
{
    int size;
    hufftree_node *items[MAX_HUFF_Q];
} huffheapQueue;

huffheapQueue *newHuffQueue();

hufftree_node* newHeapNode(char value, int priority);

void huff_enqueue(huffheapQueue *heap, char value, int priority);

void huff_enqueue_from_node(huffheapQueue *heap, hufftree_node *node);

hufftree_node* huff_dequeue(huffheapQueue *heap);

int huff_get_parent_index(huffheapQueue *heap, int i);

int huff_get_left_index(huffheapQueue *heap, int i);

int huff_get_right_index(huffheapQueue *heap, int i);

void min_heapify_huff(huffheapQueue *heap, int i);

hufftree_node* huff_item_of(huffheapQueue *heap, int i);

void swap(hufftree_node **x, hufftree_node **y);

#endif