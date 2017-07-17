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
    while ((c = fgetc(input)) != EOF) {
        if (c == 2) {
            //printf("true\n");
            printf("%d\n", c);
        } else {
            printf("%d\n", c);
            //printf("false\n");
        }
    }
    */

    int tab[128];
    read_frequences(input, tab);

    for (int i = 0; i < 128; i++) {

        printf("%c : ", i);
        printf("%d\n", tab[i]);
    }

}          

void read_frequences(FILE *input, int *tab) {

    int c = 0;
    int i;

    while (c != 2) {
        fread(&c, 1, 1, input);
        fread(&i, 1, 1, input);

        tab[c] = i;
    }
}
