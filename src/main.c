#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../test/global_tests.h"
#include "lib/logger.h"
#include "lib/fila.h"
#include "huffman/helpers.h"

void intro()
{
    printf("    ______   _\n");
    printf("    |  ___| (_)\n");
    printf("    | |_ _____ _ __ \n");
    printf("    |  _|_  / | '_ \\ \n");
    printf("    | |  / /| | |_) |\n");
    printf("    \\_| /___|_| .__/ \n");
    printf("              | |    \n");
    printf("              |_|    \n");

    printf("\n- O segundo melhor compactador na seu máquina, provavelmente -  \n");
    printf("Grupo: {Reinaldo, Matheus, Guilherme, Fernanda}\n");
 
}

int main(int argc, char *argv[])
{
    intro();

    bool debug = true;
    
    char whole_arg[500];
    for(int i=0; i<argc; i++)      
    {
        //printf("atual %s\n",argv[i]);
        char aux[500];
        sprintf(aux," %s",argv[i]);
        strcat(whole_arg,aux);
    }


    debug = (strstr(whole_arg,"--debug") != NULL);
    bool benchmarking = (strstr(whole_arg,"--benchmarking") != NULL);
    
    bool huffman = (strstr(whole_arg,"--huffman") != NULL);
    
    //printf("test %s\n",whole_arg);
    
    if(debug)
    {
        testRun();
        test_fila_run();
        test_huffman_run();
        
        FILE *f = fopen("./huffman.txt","r");
        char path[20] = "hufftest";
        compress(f,path);

    }
    if(benchmarking)
        runQueueBenchmarking();

    if(huffman)
    {
        // FILE *f = fopen("huffman.txt","r");
        // compress(f,"huftest");
    }

    return 0;
}