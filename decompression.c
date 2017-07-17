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
    char c;

    /*
    c = fgetc(input);
    printf("%d\n",c);
    c = fgetc(input);
    printf("%d\n",c);
    c = fgetc(input);
    printf("%d\n",c);
    c = fgetc(input);
    printf("%d\n",c);
    c = fgetc(input);
    printf("%d\n",c);
    c = fgetc(input);
    printf("delimiter :\n");
    printf("%d\n",c);
    */
    
    while ((c = fgetc(input)) != EOF) {
        if (c == 2) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }

}
