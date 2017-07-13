#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <stdio.h>
#include "dictionary.h"

void store_code(Tree*, Entry**, int, int);

void encode(FILE*, FILE*, Entry**);

void compress(char*, char*);
#endif 
