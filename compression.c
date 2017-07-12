#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"
#include "dictionary.h"

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
