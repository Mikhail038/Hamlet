
#include "core.h"


int main ()
{
    long int start = clock();

    //printf ("%d\n", MyBackStrcmp ("bbaa!", "bbaa"));
    FILE* InputFile = fopen ("hamlet.txt", "r");
    assert (InputFile != NULL);
    if (errno != 0) perror ("Error");

    int AmntLines = count_lines_in_file (InputFile);

    char** ArrLinePtrs = (char**) calloc (AmntLines, sizeof (*ArrLinePtrs));
    assert (ArrLinePtrs != NULL);
    if (errno != 0) perror ("Error");

    int BufferSize = 1 + count_symbols_in_file (InputFile);

    char* Buf = (char*) calloc (BufferSize, sizeof (*Buf));
    assert (Buf != NULL);
    if (errno != 0) perror ("Error");

    fread (Buf, sizeof (char), BufferSize, InputFile);
    Buf[BufferSize - 1] = '\0';

    fclose (InputFile);

    char* BufCpy = strdup (Buf);

    separate_buffer_on_lines (ArrLinePtrs, (const char*) BufCpy, BufferSize - 1);

    FILE* OutputFile = fopen ("hamlet1.txt", "w");
    assert (OutputFile != NULL);
    if (errno != 0) perror ("Error");

    for (int i = 0; i < AmntLines; i++)
    {
        clear_begining_of_line (ArrLinePtrs[i]);
    }

    qsort (ArrLinePtrs, AmntLines, sizeof (char*), compare_strings_alphabet_start);

    print_strings_in_file (OutputFile, AmntLines, ArrLinePtrs);

    qsort (ArrLinePtrs, AmntLines, sizeof (char*), compare_strings_alphabet_end);

    print_strings_in_file_backwards (OutputFile, AmntLines, ArrLinePtrs);

    fputs (Buf, OutputFile);


    fclose (OutputFile);

    free (Buf);
    free (BufCpy);
    free (ArrLinePtrs);

    printf ("%ld\n", clock() - start);

    return 0;
}
