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
    Tree *tree;

    Entry *dic[128];

    int tab[128] = {0};
    read_frequences(input, tab);

    tree = build_tree(tab, 128);

    for (int i = 0; i < 128; i++) {
        Entry *entry = malloc(sizeof(Entry));
        dic[i] = entry;
    }

    store_code(tree, dic, 0, 0);

    printf("\n");
    decode(input, output, tab, tree);

}          

void read_frequences(FILE *input, int *tab) {

    int c = 0;
    unsigned char i;

    fread(&c, 1, 1, input);
    fread(&i, 1, 1, input);

    while (c != 2) {
        //printf("%d : %d\n", c, i);
        //printf("%ld\n", ftell(input));

        tab[c] = i;
        fread(&c, 1, 1, input);
        fread(&i, 1, 1, input);
    }
    //printf("%d : %d\n", c, i);
    //printf("%ld\n", ftell(input));

    tab[2] = 0;
}

void decode(FILE *input, FILE *output, int *tab, Tree *tree) {
    unsigned int buffer = 0;
    unsigned char code = 0;
    int bufferSize = 0;
    int c = 0;
    Tree *bottom;

    printf("position of the cursor : %ld\n", ftell(input));
    //display_tree(tree);

    while ((c = fgetc(input)) != EOF) {

        buffer = buffer<<8;
        buffer = buffer|c;
        bufferSize = bufferSize + 8;

        //printf("%ld\n", ftell(input));

        //display_tree(search_in_tree(tree, buffer,bufferSize,0));
        while ((bottom = search_in_tree(tree, buffer, bufferSize, 0)) != NULL) {
            //printf("%c\n", bottom->el);
            fputc(bottom->el, output);
            bufferSize = bufferSize - bottom->bits;
        }

    }
}

