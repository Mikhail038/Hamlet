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

#define DOTXT(Message) #Message

#define MCP(Message)                                                                                       \
        do                                                                                                 \
        {                                                                                                  \
            fprintf (stderr, "FAILED CHECK//" DOTXT (Message)                                              \
            "//IN FUNCTION//%s//IN LINE//%d//IN FILE//%s//\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);   \
            if (errno != 0) perror ("Error!");                                                               \
        } while (0)

#define MCA(Condition, ReturnNum)                     \
        do                                            \
        {                                             \
            if (!(Condition))                         \
            {                                         \
                MCP (Condition);                      \
                return ReturnNum;                     \
            }                                         \
        } while (0)

/*!
    @brief Function that restructurize string, deletes ' ' in the begining of it

    @param[in] line pointer to line
*/
void clear_begining_of_line (char* line);

/*!
    @brief Function that counts valid (non zero) lines in file

    @param[in] stream file

    @return amount of lines
*/
int count_lines_in_file (FILE* stream);

/*!
    @brief Function that counts all symbols in file

    @param[in] stream file

    @return amount of symbols
*/
int count_symbols_in_file (FILE* stream);

/*!
    @brief Function that separates buffer on lines

    @param[in] ArrLinePtrs array of line pointers
    @param[in] Buffer array of chars, which you want to separate
    @param[in] AmntLines amount of valid (non-zero) lines
*/
void separate_buffer_on_lines (char** ArrLinePtrs, const char* Buffer, int AmntLines);

/*!
    @brief Function that runs function, that compares 2 strings lexigraphically

    @param[in] FirstLine pointer to first line
    @param[in] SecondLine pointer to second line

    @return  > 0 if FirstLine is bigger then Second Line, < 0 if Second Line is bigger, 0 if lines are equal
*/
int compare_strings_alphabet_start (const void* FirstLine, const void* SecondLine);

/*!
    @brief Function that runs function, that compares 2 strings lexigraphically, begins from the last symbol

    @param[in] FirstLine pointer to first line
    @param[in] SecondLine pointer to second line

    @return  > 0 if FirstLine is bigger then Second Line, < 0 if Second Line is bigger, 0 if lines are equal
*/
int compare_strings_alphabet_end (const void* FirstLine, const void* SecondLine);

/*!
    @brief Function that compares 2 strings lexigraphically

    @param[in] FirstLine pointer to first line
    @param[in] SecondLine pointer to second line

    @return  > 0 if FirstLine is bigger then Second Line, < 0 if Second Line is bigger, 0 if lines are equal
*/
int MyStrcmp (const char* FirstLine, const char* SecondLine);

/*!
    @brief Function that compares 2 strings lexigraphically, begins from the last symbol

    @param[in] FirstLine pointer to first line
    @param[in] SecondLine pointer to second line

    @return  > 0 if FirstLine is bigger then Second Line, < 0 if Second Line is bigger, 0 if lines are equal
*/
int MyBackStrcmp (const char* FirstLine, const char* SecondLine);

/*!
    @brief Function that prints strings from array in file

    @param[in] stream file
    @param[in] StrNum amount of line
    @param[in] stream file
*/
void print_strings_in_file (FILE* stream, int StrNum, char** ArrLinePtrs);

/*!
    @brief Function that prints strings from array in file, but aligned at the ends

    @param[in] stream file
    @param[in] StrNum amount of line
    @param[in] stream file
*/
void print_strings_in_file_backwards (FILE* stream, int StrNum, char** ArrLinePtrs);

/*!
    @brief Function that prints two separating lines in file
*/
void put_decor_line (FILE* stream);

void MyBubSort (char** ArrayData, int AmntData, int SieDzata,  int (*comparator) (const void*, const void*));


#endif
