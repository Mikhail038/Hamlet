#include "core.h"


char* clear_begining_of_line (char* line)
{
    int i = 0, j = 0;

    while  ((line[j] == ' ') or (line[j] == '[') or (line[j] == '(') or (line[j] == '\''))  j++;

    while (line[j] != '\0')
    {
        line[i] = line[j];
        i++;
        j++;
    }

    line[i] = '\0';
    return line;
}

int count_lines_in_file (FILE* stream)
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

int count_symbols_in_file (FILE* stream)
{
    fseek (stream, 0, SEEK_END);

    int i = ftell (stream);

    fseek (stream, 0, SEEK_SET);
    return i;
}

int compare_strings_alphabet_start (const void* FirstLine, const void* SecondLine)
{
    char* FirstLineCpy =  *(char**) FirstLine;
    char* SecondLineCpy = *(char**) SecondLine;

    assert (FirstLineCpy != NULL);
    assert (SecondLineCpy != NULL);


    return MyStrcmp ( (const char*) FirstLineCpy, (const char*) SecondLineCpy);
}

int compare_strings_alphabet_end (const void* FirstLine, const void* SecondLine)
{
    char* FirstLineCpy =  *(char**) FirstLine;
    char* SecondLineCpy = *(char**) SecondLine;

    assert (FirstLineCpy != NULL);
    assert (SecondLineCpy != NULL);

    return MyBackStrcmp ( (const char*) FirstLineCpy, (const char*) SecondLineCpy);
}

int MyStrcmp (const char* FirstLine, const char* SecondLine)
{
    int length = strlen (FirstLine);
    int length2 = strlen (SecondLine);

    int min_length = (length < length2) ? length : length2;

    int i = 0, j = 0;

    while ((i < min_length) && (j < min_length))
    {
        if (!isalpha (FirstLine[i]))
        {
            i++;
        }
        else if (!isalpha (SecondLine[j]))
        {
            j++;
        }
        else if (FirstLine[i] != SecondLine[j])
        {
            return ((int) FirstLine[i] - (int) SecondLine[j]);
        }
        else
        {
            i++;
            j++;
        }
    }

    return (length - length2);
}

int MyBackStrcmp (const char* FirstLine, const char* SecondLine)
{
    int length = strlen (FirstLine);
    int length2 = strlen (SecondLine);

    int min_length = (length < length2) ? length : length2;

    int i = 0, j = 0;

    while ((i < min_length) && (j < min_length))
    {
        if (!isalpha (FirstLine[length - i]))
        {
            i++;
        }
        else if (!isalpha (SecondLine[length2 - j]))
        {
            j++;
        }
        else if (FirstLine[length - i] != SecondLine[length2 - j])
        {
            return ((int) FirstLine[length - i] - (int) SecondLine[length2 - j]);
        }
        else
        {
            i++;
            j++;
        }
    }

    return (length - length2);
}

void separate_buffer_on_lines (char** arr, const char* buf, int n)
{
    int i = 0, j = 0, c = 0;

    assert (arr != NULL);
    assert (buf != NULL);

    while (i < n)
    {
        j = 0;

        while (buf[i+j] != '\n')
        {
            j++;
        }

        if (j != 0)
        {

            arr[c] = (char*) &(buf[i]);

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

void print_strings_in_file (FILE* stream, int StrNum, char** Arr)
{
    for (int i = 0; i < StrNum; i++)
    {
        fprintf (stream, "%s\n", Arr[i]);
    }
    fputs ("\n----------------------------------------------------"
           "----------------------------------------------------\n\n", stream);
}

void print_strings_in_file_backwards (FILE* stream, int StrNum, char** Arr)
{
    for (int i = 0; i < StrNum; i++)
    {
        fprintf (stream, "%70s\n", Arr[i]);
    }
    fputs ("\n----------------------------------------------------"
           "----------------------------------------------------\n\n", stream);
}
