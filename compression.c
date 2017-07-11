#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"

/*Write the huffman code in the corresponding nodes :
 * left branches are 0,
 * right branches are 1*/
void encode(Tree *node, int codage) {
    if (node->left == NULL && node->right == NULL) {
        node->code = codage;
    } else {
        encode(node->left, codage << 1);
        encode(node->left, (codage << 1)+1);
    }
}
