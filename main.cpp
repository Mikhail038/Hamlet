#include "core.h"


int main ()
{
    FILE* InputFile = fopen ("hamlet.txt", "r");
    MCA (InputFile != NULL, 1);

    int AmntLines = count_lines_in_file (InputFile);

    MCA (AmntLines >= 0, 0);
    char** ArrLinePtrs = (char**) calloc (AmntLines, sizeof (*ArrLinePtrs));
    MCA (ArrLinePtrs != NULL, 1);

    int BufferSize = 1 + count_symbols_in_file (InputFile);

    MCA (BufferSize >= 0, 1);
    char* Buf = (char*) calloc (BufferSize, sizeof (*Buf));
    MCA (Buf != NULL, 0);

    fread (Buf, sizeof (char), BufferSize, InputFile);
    Buf[BufferSize - 1] = '\0';

    fclose (InputFile);


    FILE* OutputFile = fopen ("hamlet1.txt", "w");
    MCA (OutputFile != NULL, 1);

    //fseek (OutputFile, 2 * BufferSize, SEEK_SET);
    fputs (Buf, OutputFile);
    //fseek (OutputFile, 0, SEEK_SET);

    put_decor_line (OutputFile);

    separate_buffer_on_lines (ArrLinePtrs, (const char*) Buf, BufferSize - 1);

    for (int LineNumber = 0; LineNumber < AmntLines; LineNumber++)
    {
        clear_begining_of_line (ArrLinePtrs[LineNumber]);
    }

    my_quick_sort (ArrLinePtrs, AmntLines, sizeof (char*), compare_strings_alphabet_start);
    print_strings_in_file (OutputFile, AmntLines, ArrLinePtrs);

    //my_bub_sort (ArrLinePtrs, AmntLines, sizeof (char*), compare_strings_alphabet_start);
    //print_strings_in_file (OutputFile, AmntLines, ArrLinePtrs);

    // qsort (ArrLinePtrs, AmntLines, sizeof (char*), compare_strings_alphabet_start);
    // print_strings_in_file (OutputFile, AmntLines, ArrLinePtrs);

    // qsort (ArrLinePtrs, AmntLines, sizeof (char*), compare_strings_alphabet_end);
    // print_strings_in_file_backwards (OutputFile, AmntLines, ArrLinePtrs);


    fclose (OutputFile);

    free (Buf);
    free (ArrLinePtrs);

    return 0;
}
