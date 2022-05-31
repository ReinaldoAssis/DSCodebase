#include <stdio.h>
#include <stdbool.h>

void* escrever_str(FILE *f, char *msg)
{
    if(msg == NULL) return false;
    
    fprintf(f,msg);
    return true;
}

FILE *criar_stream(char *name, bool **success)
{
    FILE *f = fopen(name,"w");
    if(f == NULL)
    {
        if(success != NULL)
            *success=false;
        return NULL;
    }
    if(success != NULL)
        *success=true;
    return f;
}

bool encerrar_stream(FILE *f)
{
    if(f == NULL) return false;
    fclose(f);
    return true;
}