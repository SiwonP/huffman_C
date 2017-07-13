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
    Entry **dic;

    count_frequences(input, tab);
    printf("frequences counted\n");

    Tree *tree = build_tree(tab, 128);
    printf("tree built\n");
    dic = store_code(tree, 0, 0);
    printf("code stored\n");

    rewind(input);
    printf("cursor at position 0\n");

    encode(input, output, dic);
    printf("compressed in %s\n", outputName);
}
    

/*Write the huffman code in the corresponding nodes :
 * left branches are 0,
 * right branches are 1*/
Entry **store_code(Tree *node, int codage, int level) {
    static Entry *dic[128];
    for (int i = 0; i < 128; i++) {
        Entry *entry = malloc(sizeof(Entry));
        dic[i] = entry;
    }
    if (node->left == NULL && node->right == NULL) {
        node->code = codage;
        node->bits = level;
        dic[node->el]->code = codage;
        dic[node->el]->bits = level;
    }
    if (node->left != NULL) {
        store_code(node->left, codage<<1, level+1);
    }
    if (node->right != NULL) {
        store_code(node->right, (codage<<1)+1, level+1);
    }
    return dic;
}

void encode(FILE *file, FILE *output, Entry **dic) {
    unsigned int buffer = 0;
    unsigned char code = 0;
    int bufferSize = 0;
    int c;

    for (int i = 0; i < 128; i++) {
        fputc(dic[i]->code, output);
    }

    char delimiter = 32;

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

