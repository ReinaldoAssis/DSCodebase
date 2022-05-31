#include <stdio.h>
#include <stdbool.h>

/*Escreve no arquivo especificado, retorna false se pt de msg for NULL. 
Retorna true se escrever no arquivo.*/
bool escrever_str(FILE *f,char* msg);

/*Cria um ponteiro para um arquivo, retorna NULL se falhar
retorna o ponteiro se possuir êxito. Como argumento opcional
é possível passar uma &bool para obter o código de sucesso.*/
FILE *criar_stream(char *name, bool **success);

/*Fecha a stream do arquivo. Retorna false se falhar e true se tiver êxito.*/
bool encerrar_stream(FILE *f);