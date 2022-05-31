#include <stdio.h>
#include <stdbool.h>

bool escrever_str(FILE *f, char *msg)
{
    if(f == NULL) return false;
    if(msg == NULL || msg[0] == '\0') return false;
    
    fprintf(f,msg);
    return true;
}

FILE *criar_stream(char *name, bool **success)
{
    if(name == NULL)
    {
        if(success != NULL) *success = false;
        return NULL;
    }
    
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