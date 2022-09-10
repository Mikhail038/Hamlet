#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <locale.h>
#include <string.h>
#include "core.h"

int main ()
{
    FILE* InputFile = NULL;
    InputFile = fopen ("hamlet.txt", "r");
    assert (InputFile != NULL);

    int str_num = str_in_f (InputFile);

    char** PtrArr = NULL;
    PtrArr = (char**) calloc (str_num, sizeof (*PtrArr));
    assert (PtrArr != NULL);

    int buf_size = 1 + sym_in_f (InputFile); //printf ("!!%d", buf_size);

    char* Buf = NULL;
    Buf = (char*) calloc (buf_size, sizeof (*Buf));
    assert (Buf != NULL);

    fread (Buf, sizeof (char), buf_size, InputFile); 
    Buf[buf_size - 1] = '\0';

    fclose (InputFile);


    separate_buf (PtrArr, Buf, buf_size - 1);
    
    qsort (PtrArr, str_num, sizeof (char*), sor_cmp);


    FILE* OutputFile = NULL;
    OutputFile = fopen ("hamlet1.txt", "w");
    assert (OutputFile != NULL);
    
    
    for (int i = 0; i < str_num; i++)
    {
        fprintf (OutputFile, "%s\n", PtrArr[i]);
    }

    fclose (OutputFile);

    free (Buf);
    free (PtrArr);
    
    return 0;
}