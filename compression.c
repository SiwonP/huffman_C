#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"

/*Write the huffman code in the corresponding nodes :
 * left branches are 0,
 * right branches are 1*/
void encode(Tree *node, int codage, int level) {
    if (node->left == NULL && node->right == NULL) {
        node->code = codage;
        node->bits = level;
    }
    if (node->left != NULL) {
        encode(node->left, codage<<1, level+1);
    }
    if (node->right != NULL) {
        encode(node->right, (codage<<1)+1, level+1);
    }
}
