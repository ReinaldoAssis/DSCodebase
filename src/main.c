#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../test/global_tests.h"
#include "lib/logger.h"
#include "lib/fila.h"
#include "huffman/helpers.h"

int main(int argc, char *argv[])
{
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
    }
    if(benchmarking)
        runQueueBenchmarking();

    if(huffman)
        get_bytes_frequency();

    return 0;
}