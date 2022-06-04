#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../test/global_tests.h"
#include "lib/logger.h"
#include "lib/fila.h"

void routine(bool debug, int argc, char *argv[])
{
    if(debug)
    {
        //testRun();
        test_fila_run();
        runQueueBenchmarking();
    }
    else
    {
        int n1 = atoi(argv[1]);
        int n2 = atoi(argv[2]);
    
        
    }
}

int main(int argc, char *argv[])
{
    bool debug = true;
    if(argc == 2) debug = (strcmp("true",argv[1]) == 0);
    routine(true, argc, argv);
    return 0;
}