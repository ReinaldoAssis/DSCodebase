#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "lib/lib_test.h"
#include "../test/global_tests.h"
#include "lib/logger.h"


void routine(bool debug, int argc, char *argv[])
{
    if(debug)
    {
        testRun();
    }
    else
    {
        int n1 = atoi(argv[1]);
        int n2 = atoi(argv[2]);
    
        FILE *f = criar_stream("output.txt",NULL);
        char msg[20];
        sprintf(msg,"%d mod %d = %d\n",n1,n2,mod(n1,n2));
        escrever_str(f,msg);
        encerrar_stream(f);
    }
}

int main(int argc, char *argv[])
{
    bool debug = true;
    if(argc == 2) debug = (strcmp("true",argv[1]) == 0);
    routine(true, argc, argv);
    return 0;
}