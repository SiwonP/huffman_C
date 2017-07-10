#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree *init_tree(int w, char e) {
    Tree *node = malloc(sizeof(Tree));
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
    if (node == NULL) {
        return;
    }
    printf("{");
    printf("\"left\" : ");
    if (node->left != NULL) {
        display_tree(node->left);
    } else {
        printf("\"_\"");
    }
    printf(", ");
    printf("\"weight\" : %d,", node->weight);
    printf("\"char\" : \"%c\"", node->el);
    printf(", ");
    printf("\"right\" : ");
    if(node->right != NULL) {
        display_tree(node->right);
    } else {
        printf("\"_\"");
    }
    printf("}");
}

Tree *merge_two_sons(Tree *leftSon, Tree *rightSon) {
    int w;
    w = leftSon->weight + rightSon->weight;
    Tree *son = init_tree(w, -1);
    son->left = leftSon;
    son->right = rightSon;

    return son;
}

void make_basic_nodes(Tree **nodes_storage, int *tab, int size) {
    //Tree *nodes_storage[128];
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (tab[i] > 0) {
           Tree *tmp = init_tree(tab[i], i);
           nodes_storage[counter] = tmp;
           counter++;
        }
    }
}
