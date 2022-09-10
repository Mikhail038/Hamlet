#include "core.h"


int str_in_f (FILE* stream)
{
    char sym = '\0';
    int i = 0;

    while ((sym = getc (stream)) != EOF)
    {
        if (sym != '\n')
        {
            i++;
            while ((sym = getc (stream)) != '\n');
        }
    }

    return i;
}

int sym_in_f (FILE* stream)
{
    fseek (stream, 0, SEEK_END);

    int i = ftell (stream);

    fseek (stream, 0, SEEK_SET);
    return i;
}

int sor_cmp (const void* a, const void* b)
{
    const char* a1 = *(const char**) a;
    const char* b1 = *(const char**) b;

    assert (a1 != NULL);
    assert (b1 != NULL);

    
    return strcmp ( a1, b1);
}

void separate_buf (char** arr, char* buf, int n)
{
    char sym = 0;
    int i = 0, j = 0, c = 0;

    assert (arr != NULL);
    assert (buf != NULL);

    while (i < n)
    {
        j = 0;

        while ((sym = buf[i+j]) != '\n') 
        {
            j++;
        }

        if (j != 0)
        {
            arr[c] = &(buf[i]);

            (arr[c])[j] = '\0';
            c++;
        }

        i += j + 1;
    }
}

void free_arr (int n, void** Arr)
{       
    for (int i = 0; i < n; i++)
    {
        free (Arr[i]);
    }
    free (Arr);

    Arr = NULL;
}
