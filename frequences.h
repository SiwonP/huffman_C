#ifndef FREQUENCES_H
#define FREQUENCES_H

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void count_frequences(FILE*, int*);

int count_present_char(int*, int);

void make_sorted_array(int*, char*, int);

void insertion_sort(int*, char*, int);

Tree *build_tree(int*, char*, int);

#endif
