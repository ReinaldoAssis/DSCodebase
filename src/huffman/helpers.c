#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "helpers.h"
#include "priorityQ.h"
#include "hufftree.h"

#include <math.h>

//HASH TABLE

hashnode *newhashnode()
{
    hashnode *node = (hashnode*)malloc(sizeof(hashnode));
    node->code = NULL;
    node->frequency = -1;
    node->byte = NULL;
    node->level = -1;
    return node;
}

hashtable *newhashtable()
{
    hashtable *h = (hashtable*)malloc(sizeof(hashtable));
    for(int i=0; i<256; i++)
        h->table[i] = NULL;
    return h;
}

void put_hashtable(hashtable *h, unsigned char byte, long long int frequency, unsigned int code, int level)
{
    hashnode *nd = (hashnode*)malloc(sizeof(hashnode));
    nd->code = code;
    nd->frequency = frequency;
    nd->byte = byte;
    nd->level = level;
    h->table[byte] = nd;
}

hashnode* get_hashtable(hashtable *tb, unsigned char key)
{
    return tb->table[key];
}

void print_hashtable(hashtable *h)
{
    for(int i=0; i<256; i++)
    {
        if(h->table[i] != NULL)
        {
            printf("%d|%02X|level %d|f %d\n",i,h->table[i]->byte,h->table[i]->level,h->table[i]->frequency);
            //if(h->table[i]->code != NULL)
                //printf("code %s\n",h->table[i]->code);
        }
    }
}

//====================================

// void generate_bittable(hufftree_node *root, hashtable *h, unsigned char *code, int level)
// {
//     printf("code atual %s\n",code);
//     if(root != NULL)
//     {
//         if(is_leaf(root))
//         {
//             printf("putting %c = %s | level %d\n",root->value,code,level);
//             put_hashtable(h,root->value,root->frequency,code,level);
//             free(code);
//             code = (char *)malloc(1000*sizeof(char));
//         } 
//         else
//         {
//             char l[1] = {'0'};
//             char r[1] = {'1'};
            
//             unsigned char *codeleft = (unsigned char*)malloc(sizeof(code)*sizeof(unsigned char));
//             strcpy(codeleft,code);
//             strcat(codeleft,l);
            
//             generate_bittable(root->left,h,codeleft,level+1);

//             unsigned char *coderight = (unsigned char*)malloc(sizeof(code)*sizeof(unsigned char));
//             strcpy(coderight,code);
//             strcat(coderight,r);

//             generate_bittable(root->right,h,coderight,level+1);

//         }
//     }
// }

void print_tree(hufftree_node *tree, char *path)
{
    if(is_leaf(tree))
    {
        printf("%s\n",path);
        free(path);
        path = (char*)malloc(1000*sizeof(char));
        return;
    }

    unsigned char *codeleft = (unsigned char*)malloc(sizeof(path)*sizeof(unsigned char));
    
    char *temp = (char*)malloc(4*sizeof(char));
    sprintf(temp,"->%c",tree->left->value);
    strcpy(codeleft,path);
    strcat(codeleft,temp);
    print_tree(tree->left,codeleft);

    free(temp);
    temp = (char*)malloc(4*sizeof(char));
    sprintf(temp,"-|>%c",tree->right->value);

    unsigned char *coderight = (unsigned char*)malloc(sizeof(path)*sizeof(unsigned char));
    strcpy(coderight,path);
    strcat(coderight,temp);
    print_tree(tree->right,coderight);
}

void bin(unsigned n, int len)
{
    unsigned i;
    for (i = 1 << len; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

void generate_bittable(hufftree_node *root, hashtable *h, bool flag, unsigned int code, int level)
{
    //printf("code atual %s\n",code);
    // printf("code atual ");
    // bin(code,level);
    // printf("\n");

    if(root != NULL)
    {
        if(is_leaf(root))
        {
            printf("putting %c = ",root->value);
            bin(code,level);
            printf(" | level %d\n",level);
            put_hashtable(h,root->value,root->frequency,code,level);
            return;
        }

        if(flag)
        {
            generate_bittable(root->left,h,false,code,level+1);
            generate_bittable(root->right,h,false,(code|1),level+1);
        }
        else
        {
            generate_bittable(root->left,h,false,(code<<1),level+1);
            generate_bittable(root->right,h,false,((code<<1)|1),level+1);
        }
       
    }
}

void print_bytes()
{
    FILE *f = fopen("./huffman.txt","r");
    
    if(f != NULL)
    {
        unsigned char buffer[4096];
        size_t sz;
        while((sz = fread(buffer, 1, sizeof(buffer), f)) > 0)
        {
            for(int i = 0; i < sz; i++)
                //printf("%d", buffer[i]);
                //ou usar "%02X", para printar valores byte
                printf("%02X ", buffer[i]);
        }
        printf("\n");

    }else
    {
        printf("Algo de errado aconteceu ao tentar abrir o arquivo :(\n");
    }

}

void print_bytes_frequency()
{
    FILE *f = fopen("./huffman.txt","r");

    long long int frequency[256] = {0};
    get_bytes_frequency(frequency,f);

    for(int i=0; i<256; i++)
    {
        printf("%d %ld\n",i,frequency[i]);
    }
}

void get_bytes_frequency(long long int *frequency, FILE *f)
{
    unsigned char byte;
    while(fscanf(f,"%c",&byte) != EOF)
        frequency[byte]++;
}

void print_huffqueue(huffheapQueue *heap)
{
    printf("Estado da heap\n");
    for(int i=1; i<=heap->size; i++)
        printf("%c ", huff_dequeue(heap)->value);
    printf("\n");
}

int total_number_of_bits(hashtable *h)
{
    int bits=0;
    for(int i=0; i<256; i++)
    {
        if(h->table[i] != NULL)
        {
            if(h->table[i]->frequency > 0)
                bits += (h->table[i]->frequency*h->table[i]->level);
        }

    }
    return bits;
}

int total_number_of_bytes(double bits)
{
    return ceil(bits/8);
}

void write_header(FILE *output, int treesize, int transhsize, hufftree_node *root)
{
    // unsigned char* bytes = (unsigned char*)malloc(2*sizeof(unsigned char));
    // bytes[0] = transhsize << 5 | treesize >> 8; //5 bits para a arvore, 3 bits para o trash
    // bytes[1] = treesize;

    // fputc(bytes[0],output);
    // fputc(bytes[1],output);

    short int initialbytes = transhsize;
    initialbytes <<= 13;
    initialbytes += treesize;
    fprintf(output,"%c%c",initialbytes >> 8, initialbytes);
    write_hufftree(root,output);
}

void convert(FILE *input, FILE *output, hashtable *tb)
{
    unsigned char byte;
    unsigned char rem; //resto

    while(fscanf(input,"%c",&byte) != EOF)
    {
        unsigned char converted;
        long long int level = tb->table[byte]->level+1;
        if(level <= 7)
        {
            converted = (unsigned char)(tb->table[byte]->code | converted);
        }
    }
}

void *compress(FILE *f, char *path)
{
    long long int frequency[256] = {0};
    get_bytes_frequency(frequency,f);

    huffheapQueue *heap = newHuffQueue();
    
    unsigned char value;
    for(int i=0; i<256; i++)
    {
        value = (unsigned char)i;
        if(frequency[i] > 0)
        {
            //printf("enqueue %c\n",value);
            huff_enqueue(heap,value,frequency[i]);
        }
    }

    //DEBUG
    //print_huffqueue(heap);

    printf("Finished bytes heap queue.\n");

    hufftree_node *root = parse_to_tree(heap);
    
    FILE *output = fopen("hufftreeoutput.txt","w");
    write_hufftree(root,output);
    fclose(output);

    printf("Finished parsing the huffman tree.\n");

    long long int tree_size = 0;
    find_hufftree_size(root,&tree_size);

    free(heap);

    //TODO: habilitar modificacao da extensao
    //usar .fzip - apenas como demonstracao
    char extension[5] = ".huff";

    strcat(path, extension);

    //resultado da compresssao
    FILE *result = fopen(path,"w");
    int trashlen = 0;

    hashtable *tb = newhashtable();
    //char buff[1000];
    unsigned int buff = (unsigned int) malloc(sizeof(unsigned int));
    generate_bittable(root,tb,true,buff,0);
    
    //print_tree(root,buff);
    
    //generate_bittable(root,tb,buff,0);
    print_hashtable(tb);

    printf("The hashtable has been generated!\n");

    int bits = total_number_of_bits(tb);
    int nbytes = total_number_of_bytes(bits);
    trashlen = (nbytes*8)-bits; //convertemos bytes completos para bits e fazemos a diferença com oq temos
    printf("tree size %d trash size %d\n",tree_size,trashlen);

    //TODO: trashlen
    write_header(result,tree_size,trashlen,root);



}

