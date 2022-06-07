#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../test/global_tests.h"
#include "lib/logger.h"
#include "lib/fila.h"

int main(int argc, char *argv[])
{
    bool debug = true;
    
    char whole_arg[500];
    for(int i=0; i<argc; i++)      
        sprintf(whole_arg," %s",argv[i]);


    debug = (strstr(whole_arg,"--debug") != NULL);
    bool benchmarking = (strstr(whole_arg,"--benchmarking") != NULL);
    
    if(debug)
    {
        testRun();
        test_fila_run();
    }
    if(benchmarking)
        runQueueBenchmarking();

    

    return 0;
}