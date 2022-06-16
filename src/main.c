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
        FILE *input = fopen("./basic.huff","r");
        FILE *output = fopen("./decomp.txt","w");
        char path[20] = "hufftest";
        //compress(f,path);
        decompress(input,output);

    }
    if(benchmarking)
        runQueueBenchmarking();

    if(huffman)
    {
        char file_path[500];
        char ouput_path[500];
        char opcao[50];

        printf("\nCompactar ou descompactar? [c/d]: ");
        fgets(opcao,sizeof(opcao),stdin);

        // printf("opcao: %s\n",opcao);

        if(strcmp(opcao,"Compactar\n") == 0 ||
        strcmp(opcao,"compactar\n") == 0 ||
        strcmp(opcao,"c\n") == 0 ||
        strcmp(opcao,"C\n") == 0)
        {
            printf("\nDigite o caminho para o arquivo: ");
            fgets(file_path,sizeof(file_path),stdin);

            printf("\nDigite o caminho de saída: ");
            fgets(ouput_path,sizeof(ouput_path),stdin);

            strtok(file_path,"\n");
            strtok(ouput_path,"\n");

            FILE *f = fopen(file_path,"r");
            compress(f,ouput_path);
        }
        else if(strcmp(opcao,"Descompactar\n") == 0 ||
        strcmp(opcao,"descompactar\n") == 0 ||
        strcmp(opcao,"d\n") == 0 ||
        strcmp(opcao,"D\n") == 0)
        {
            printf("\nDigite o caminho para o arquivo: ");
            fgets(file_path,sizeof(file_path),stdin);

            printf("\nDigite o caminho de saída: ");
            fgets(ouput_path,sizeof(ouput_path),stdin);

            strtok(file_path,"\n");
            strtok(ouput_path,"\n");

            FILE *input = fopen(file_path,"r");
            FILE *output = fopen(ouput_path,"w");
            decompress(input,output);
        }

    }

    return 0;
}