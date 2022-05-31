#include <stdbool.h>
#include <stdio.h>

#include "../src/lib/logger.h"
#include "./framework/CuTest.h"
#include "./global_tests.h"

// typedef struct arquivo
// {
//     FILE *file;
//     char name[20];
//     bool criado;

// } arquivo;

void test_criar_e_escrever_stream(CuTest *tc)
{
    bool resp = false;
    FILE *f = criar_stream("test_stream.txt",&resp);
    
    CuAssertIntEquals_Msg(tc,"Error, test_criar_e_escrever_stream: criar arquivo falhou.",true,resp);

    resp = escrever_str(f,"Test executed with success.\n");
    CuAssertIntEquals_Msg(tc,"Error, test_criar_e_escrever_stream: escrever em arquivo falhou.",true,resp);

    resp = encerrar_stream(f);
    CuAssertIntEquals_Msg(tc, "Error, test_criar_e_escrever_stream: ocorreu um erro ao fechar o arquivo.",true,resp);

}

void test_criar_stream_null(CuTest *tc)
{
    bool resp = false;
    criar_stream(NULL,&resp);
    CuAssertIntEquals_Msg(tc,"Error, test_criar_stream_null: resultado inesperado.",false,resp);
}

void test_escrever_em_stream_null(CuTest *tc)
{
    bool resp = escrever_str(NULL,"Isso ocasiona um erro.\n");
    CuAssertIntEquals_Msg(tc,"Error, test_escrever_em_stream_null: resposta inesperada.",false,resp);
}

CuSuite *BasicSuite()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite,test_criar_e_escrever_stream);
    SUITE_ADD_TEST(suite,test_criar_stream_null);
    //SUITE_ADD_TEST(suite,test_escrever_em_stream_null);
    return suite;
}


void testRun()
{

    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite,BasicSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite,output);
    CuSuiteDetails(suite,output);
    printf("%s\n",output->buffer);
}