#include "./unity/src/unity.h"
#include "../src/lib/lib_test.h"

//obrigatório
void setUp(void)
{}

//obrigatório
void tearDown(void)
{}

void main()
{
    TEST_ASSERT_MESSAGE(helloworld() == 42, "Error, resposta inesperada de helloworld.");
}