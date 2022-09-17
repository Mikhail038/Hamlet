#include "core.h"


void clear_begining_of_line (char* line)
{
    MCA (line != NULL, (void) 0);

    int i = 0, j = 0;

    while  ((line[j] == ' ')) j++;

    while (line[j] != '\0')
    {
        line[i] = line[j];
        i++;
        j++;
    }

    line[i] = '\0';
}

int count_lines_in_file (FILE* stream)
{
    MCA (stream != NULL, -1);

    char sym = '\0';
    int AmntLines = 0;

    while ((sym = getc (stream)) != EOF)
    {
        if (sym != '\n')
        {
            AmntLines++;
            while ((sym = getc (stream)) != '\n');
        }
    }

    return AmntLines;
}

int count_symbols_in_file (FILE* stream)
{
    MCA (stream != NULL,  -1);

    fseek (stream, 0, SEEK_END);

    int AmntSymbols = ftell (stream);

    fseek (stream, 0, SEEK_SET);
    return AmntSymbols;
}

int compare_strings_alphabet_start (const void* FirstLine, const void* SecondLine)
{
    MCA (FirstLine != NULL, -1);
    MCA (SecondLine != NULL, -1);

    char* FirstLineCpy =  *(char**) FirstLine;
    char* SecondLineCpy = *(char**) SecondLine;;


    return MyStrcmp ( (const char*) FirstLineCpy, (const char*) SecondLineCpy);
}

int compare_strings_alphabet_end (const void* FirstLine, const void* SecondLine)
{
    MCA (FirstLine != NULL, -1);
    MCA (SecondLine != NULL, -1);

    char* FirstLineCpy =  *(char**) FirstLine;
    char* SecondLineCpy = *(char**) SecondLine;

    return MyBackStrcmp ( (const char*) FirstLineCpy, (const char*) SecondLineCpy);
}

int MyStrcmp (const char* FirstLine, const char* SecondLine)
{
    MCA (FirstLine != NULL, -1);
    MCA (SecondLine != NULL, -1);

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
    MCA (FirstLine != NULL, -1);
    MCA (SecondLine != NULL, -1);

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

void separate_buffer_on_lines (char** ArrLinePtrs, const char* Buffer, int AmntLines)
{
    MCA (ArrLinePtrs != NULL, (void) 0);
    MCA (Buffer != NULL, (void) 0);
    MCA (AmntLines >= 0, (void) 0);

    int FirstCharNum = 0, CharNum = 0, LineNumber = 0;

    while (FirstCharNum < AmntLines)
    {
        CharNum = 0;

        while (Buffer[FirstCharNum + CharNum] != '\n')
        {
            CharNum++;
        }

        if (CharNum != 0)
        {

            ArrLinePtrs[LineNumber] = (char*) &(Buffer[FirstCharNum]);

            ArrLinePtrs[LineNumber][CharNum] = '\0';

            LineNumber++;
        }

        FirstCharNum += CharNum + 1;
    }
    return;
}

void print_strings_in_file (FILE* stream, int AmntLines, char** ArrLinePtrs)
{
    MCA (stream != NULL, (void) 0);
    MCA (ArrLinePtrs != NULL, (void) 0);
    MCA (AmntLines >= 0, (void) 0);

    for (int LineNumber = 0; LineNumber < AmntLines; LineNumber++)
    {
        fprintf (stream, "%s\n", ArrLinePtrs[LineNumber]);
    }
    put_decor_line (stream);

    return;
}

void print_strings_in_file_backwards (FILE* stream, int AmntLines, char** ArrLinePtrs)
{
    MCA (stream != NULL, (void) 0);
    MCA (ArrLinePtrs != NULL, (void) 0);
    MCA (AmntLines >= 0, (void) 0);

    for (int LineNumber = 0; LineNumber < AmntLines; LineNumber++)
    {
        fprintf (stream, "%70s\n", ArrLinePtrs[LineNumber]);
    }
    put_decor_line (stream);

    return;
}

void put_decor_line (FILE* stream)
{
    MCA (stream != NULL, (void) 0);

    fputs ("\n----------------------------------------------------"
           "------------------------------------------------------"
           "\n----------------------------------------------------"
           "------------------------------------------------------"
           "\n\n", stream);

    return;
}

void my_bub_sort (void* ArrayData, int AmntData, int SizeData,  int (*comparator) (const void*, const void*))
{
    void* buf = NULL;

    for (int i = 0; i < AmntData; i++)
    {
        for (int j = 0; j < AmntData - 1; j++)
        {
            if (comparator ((const void*) (ArrayData + SizeData * j), (const void*) (ArrayData + SizeData * (j + 1))) > 0)
            {
                change_byte_by_byte ((ArrayData + SizeData * j), (ArrayData + SizeData * (j + 1)), SizeData);
            }
        }
    }
}

void change_byte_by_byte (void* FirstData, void* SecondData, int Size)
{
    char buf = '\0';

    for (int i = 0; i < Size; i++)
    {
        buf = ((char*) FirstData)[i];
        ((char*) FirstData)[i] = ((char*) SecondData)[i];
        ((char*) SecondData)[i] = buf;
    }

    return;
}
