#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"
#include "dictionary.h"
#include "decompression.h"

void decompress(char *inputName, char *outputName) {
    FILE *input = fopen(inputName, "r");
    FILE *output = fopen(outputName, "w");

    char c = fgetc(input);
    for (int i = 0 ; i < 10; i++) {
        printf("%c", c);
        c = fgetc(input);
    }
}
