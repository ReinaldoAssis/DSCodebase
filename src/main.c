#include <stdio.h>
#include <stdbool.h>

#include "lib/lib_test.h"
#include "../test/my_first_test.h"
#include "lib/logger.h"


int main(int argc, char *argv[])
{
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    
    FILE *f = criar_stream("output.txt",NULL);
    char msg[20] = "oi oi\n";
    escrever_str(f,msg);
    encerrar_stream(f);

    //printf("atoi1 %d atoi2 %d\n",n1,n2);
    //printf("%d\n",mod(n1,n2));
    //testRun();
    return 0;
}