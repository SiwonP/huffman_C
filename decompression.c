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

}          

void read_frequences(FILE *input, int *tab) {

    int c = 0;
    unsigned char i;

    fread(&c, 1, 1, input);
    fread(&i, 1, 1, input);

    while (c != 2) {
        printf("%d : %d\n", c, i);

        tab[c] = i;
        fread(&c, 1, 1, input);
        fread(&i, 1, 1, input);
    }

    tab[2] = 0;
}
