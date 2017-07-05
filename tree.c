#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree *init_tree(int w, char e) {
    Tree *node = (Tree*)malloc(sizeof(Tree*));
    node->el = e;
    node->weight = w;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void add_son(Tree *father, Tree *son, int side) {
    if (side < 0) {
        father->left = son;
    } else if (side > 0 ) {
        father->right = son;
    }

}

void destroy_tree(Tree *node) {
    if (node != NULL) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        free(node);
    }
}

void display_tree(Tree *node) {
    while (node != NULL) {
        printf("%c %d\n", node->el, node->weight);
        printf("(");
        display_tree(node->left);
        display_tree(node->right);
        printf(")");
    }
}
