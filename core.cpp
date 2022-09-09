#include "core.h"

void qsort (void* base, int num, int size, int (*compare) (const void*, const void*));

int str_in_f (FILE* stream)
{
    char sym = '\0';
    int i = 0;

    while ((sym = getc (stream)) != EOF)
    {
        //i++;
        if (sym != '\n')
        {
            i++;
            while ((sym = getc (stream)) != '\n');
            //printf ("%d\n", i);
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

void separate_buf (FILE* stream, char** arr, char* buf, int n)
{
    char sym = 0;
    int i = 0, j = 0, c = 0;
    //printf ("!%d\n", c);
    assert (arr != NULL);
    assert (buf != NULL);

    while (i < n)
    {
        j = 0;

        while (((sym = buf[i+j]) != '\n') && (feof (stream) == 0))
        {
            j++;
        }

        if (j != 0)
        {
            // arr[c] = (char*) calloc (j, sizeof(**arr));

            arr[c] = &(buf[i]);

            (arr[c])[j] = '\0';
            c++;
            //printf ("!%d\n", c);
        }

        i += j + 1;
    }
}

/*char getstring (FILE* stream, char** str, int n)
{
    *str = (char*) calloc (n, sizeof(**str));

    char sym = '\0';

    int i = 0;

    while ((i < n) && ((sym = getc (stream)) != '\n'))
    {
        (*str)[i] = sym;
        i++;
        //printf ("!%d %c\n", i, (*str)[i]);
    }

    (*str)[i] = '\n';

    if (i > 0)
    {
        (*str)[i] = '\0';
    }

    return (*str)[0];
}*/

void free_arr (int n, void** Arr)
{       

    for (int i = 0; i < n; i++)
    {
        //printf ("%d %s\n", i, (char*) Arr[i]);
        free (Arr[i]);
        // Arr[i] = NULL;
    }
    free (Arr);

    Arr = NULL;
}
