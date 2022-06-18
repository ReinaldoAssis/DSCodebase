
#ifndef priorityq_h
#define priorityq_h

#define MAX_HUFF_Q 257

typedef struct hufftree_node
{
    long long int frequency;
    unsigned char value;
    void* left;             //hufftree_node pointer
    void* right;            //hufftree_node pointer

} hufftree_node;

//PRIORITY QUEUE

typedef struct huffheapQueue
{
    int size;
    hufftree_node *items[MAX_HUFF_Q];
} huffheapQueue;

//@return priority queue
huffheapQueue *newHuffQueue();

//@param value: byte value
//@param priority: byte's frequency
//@return huffmantree_node
hufftree_node* newHeapNode(char value, int priority);

//@param heap: priority queue
//@param value: byte' value
//@param priority: byte's frequency
void huff_enqueue(huffheapQueue *heap, char value, int priority);

//@param heap: priority queue
//@param node: huffman tree node to be enqueued
void huff_enqueue_from_node(huffheapQueue *heap, hufftree_node *node);

//@param heap: priority queue
//@return dequeued node
hufftree_node* huff_dequeue(huffheapQueue *heap);

//@param heap: priority queue
//@param i: current index
//@return parent index
int huff_get_parent_index(huffheapQueue *heap, int i);

//@param heap: priority queue
//@param i: current index
//@return left index
int huff_get_left_index(huffheapQueue *heap, int i);

//@param heap: priority queue
//@param i: current index
//@return right index
int huff_get_right_index(huffheapQueue *heap, int i);

//@param heap: priority queue
//@param i: current index
void min_heapify_huff(huffheapQueue *heap, int i);

//@param heap: priority queue
//@param i: current index
//@return hufftree_node from given index
hufftree_node* huff_item_of(huffheapQueue *heap, int i);

//swaps huffmantree nodes
void swap(hufftree_node **x, hufftree_node **y);

//TESTE - implementação sem heap

//@param heap: priority queue
//@param value: byte' value
//@param priority: byte's frequency
//void huff_enqueue_sh(huffheapQueue *heap, char value, int priority);

//@param heap: priority queue
//@param node: huffman tree node to be enqueued
//void huff_enqueue_from_node_sh(huffheapQueue *heap, hufftree_node *node);

//@param heap: priority queue
//@return dequeued node
//hufftree_node* huff_dequeue_sh(huffheapQueue *heap);

#endif