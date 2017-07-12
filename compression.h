#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <stdio.h>
#include "dictionary.h"

Entry **store_code(Tree*, int, int);

void encode(FILE*, FILE*, Entry**);

void compress(char*, char*);
#endif 
