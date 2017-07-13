#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"
#include "dictionary.h"

void compress(char *inputName, char *outputName) {
    FILE *input = fopen(inputName, "r");
    FILE *output = fopen(outputName, "w");
    int tab[128] = {0};
    Entry *dic[128];

    count_frequences(input, tab);

    Tree *tree = build_tree(tab, 128);
    store_code(tree, dic, 0, 0);

    rewind(input);

    encode(input, output, dic);

    fclose(input);
    fclose(output);
}


/*Write the huffman code in the corresponding nodes :
 * left branches are 0,
 * right branches are 1*/
void store_code(Tree *node, Entry **dic, int codage, int level) {
    if (!level) {
        for (int i = 0; i < 128; i++) {
            Entry *entry = malloc(sizeof(Entry));
            dic[i] = entry;
        }
    }
    if (node->left == NULL && node->right == NULL) {
        node->code = codage;
        node->bits = level;
        dic[node->el]->code = codage;
        dic[node->el]->bits = level;
    }
    if (node->left != NULL) {
        store_code(node->left, dic, codage<<1, level+1);
    }
    if (node->right != NULL) {
        store_code(node->right, dic, (codage<<1)+1, level+1);
    }
}

void encode(FILE *file, FILE *output, Entry **dic) {
    unsigned int buffer = 0;
    unsigned char code = 0;
    int bufferSize = 0;
    int c;

    for (int i = 0; i < 128; i++) {

        if (dic[i]->code > 0) {
            fputc(dic[i]->code, output);
        }
    }

    int delimiter = 2;

    fputc(delimiter, output);
    while((c = fgetc(file)) != EOF) {
        buffer = buffer<<dic[c]->bits;
        buffer = buffer|dic[c]->code;
        bufferSize = bufferSize + dic[c]->bits;

        while (bufferSize > 7) {
            bufferSize = bufferSize - 8;
            code = buffer>>bufferSize;
            fputc(code, output);
        }
    }
}

