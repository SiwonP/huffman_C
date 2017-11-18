#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"
#include "dictionary.h"

void compress(char *inputName, char *outputName) {
    printf("compressing ...\n");
    FILE *input = fopen(inputName, "r");
    FILE *output = fopen(outputName, "w");
    int tab[128] = {0};
    Entry *dic[128];
    int inputBytes;
    int outputBytes;

    inputBytes = count_frequences(input, tab);

    Tree *tree = build_tree(tab, 128);
    for (int i = 0; i < 128; i++) {
        Entry *entry = malloc(sizeof(Entry));
        dic[i] = entry;
    }
    store_code(tree, dic, 0, 0);

    rewind(input);

    outputBytes = encode(input, output, tab, dic);

    fclose(input);
    fclose(output);

    printf("done\n");

    printf("compression rate : %f\n", (double)outputBytes/inputBytes);
}


/*Write the huffman code in the corresponding nodes :
 * left branches are 0,
 * right branches are 1*/
void store_code(Tree *node, Entry **dic, int codage, int level) {
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

int encode(FILE *file, FILE *output, int *tab, Entry **dic) {
    unsigned int buffer = 0;
    unsigned char code = 0;
    int bufferSize = 0;
    int c;
    int byte = 0;

    for (int i = 0; i < 128; i++) {

        if (tab[i] > 0) {
            //printf("%d : %d\n",i, tab[i]);
            //fputc(dic[i]->code, output);
            fwrite(&i, 1, 1, output);
            byte++;
            fwrite(&tab[i], 1, 1, output);
            byte++;
        }
    }

    char delimiter = 2; 

    fwrite(&delimiter, 1, 1, output);
    byte++;

    while((c = fgetc(file)) != EOF) {
        buffer = buffer<<dic[c]->bits;
        buffer = buffer|dic[c]->code;
        bufferSize = bufferSize + dic[c]->bits;

        /* As long as the buffer is more than a byte long
         * we reduce the bufferSize by 8 (lentgh of a byte).
         * Then we right bit shift this buffer bufferSize times
         * and stored the result in the code variable, so that 
         * the code variable now contains the first
         * byte long piece of information
         * After that we write this byte in the new archive file */
        while (bufferSize > 7) {
            bufferSize = bufferSize - 8;
            code = buffer>>bufferSize;
            fputc(code, output);
            byte++;
        }
    }
    return byte;
}

