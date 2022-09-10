
#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


int str_in_f (FILE* stream);

int sym_in_f (FILE* stream);

void separate_buf (char** arr, char* buf, int n);

int sor_cmp (const void* a, const void* b);

void free_arr (int n, void** Arr);

#endif
