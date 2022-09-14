
#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <locale.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <ctime>


char* clear_begining_of_line (char* line);

void stack_null_lines (int AmntLines, char** ArrLinePtrs);

char* symbol_killer_queen (char* line);

int count_lines_in_file (FILE* stream);

int count_symbols_in_file (FILE* stream);

void separate_buffer_on_lines (char** arr, const char* buf, int n);

int compare_strings_alphabet_start (const void* a, const void* b);

int compare_strings_alphabet_end (const void* FirstLine, const void* SecondLine);

int MyStrcmp (const char* FirstLine, const char* SecondLine);

int MyBackStrcmp (const char* FirstLine, const char* SecondLine);

void free_arr (int n, void** Arr);

void print_strings_in_file (FILE* stream, int StrNum, char** Arr);

void print_strings_in_file_backwards (FILE* stream, int StrNum, char** Arr);




#endif
