#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/*This function takes a weight w and a char e and return a tree leaf out of them*/
Tree *init_tree(int w, int e) {
    Tree *node = malloc(sizeof(Tree));
    node->el = e;
    node->weight = w;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

TreeArray *init_tree_array(void) {
    TreeArray *array = malloc(sizeof(TreeArray));
    array->counter = 0;
    for (int i = 0; i < 128; i++) {
        array->nodes[i] = NULL;
    }
    return array;
}


/*Destroy recursively all sons behind the node passed in argument
 * (ie the whole tree if the root is the argument)*/
void destroy_tree(Tree *node) {
    if (node != NULL) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        free(node);
    }
}

/*Display the tree like a JSON -> Can be beautified to see a clearer display*/
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
    printf("\"char\" : %d,", node->el);
    printf("\"code\" : %d,", node->code);
    printf("\"bits\" : %d", node->bits);
    printf(", ");
    printf("\"right\" : ");
    if(node->right != NULL) {
        display_tree(node->right);
    } else {
        printf("\"_\"");
    }
    printf("}");
}


/*Takes a Tree* array and the initial array where are stored the
 * occurences of the character in the file to compress and fill 
 * the Tree array with tree leaves made out of the int array*/
void make_basic_nodes(TreeArray *array, int *tab, int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i] > 0) {
           Tree *tmp = init_tree(tab[i], i);
           insert_node(tmp, array);
           array->nodes[i] = tmp;
        }
    }
}

/*Insert a node in the nodes array of the TreeArray nodes so that 
 * the nodes array is sorted*/
void insert_node(Tree *node, TreeArray *array) {
    int i;
    for (i = array->counter; i > 0 && (array->nodes[i-1]->weight < node->weight); i--) {
        array->nodes[i] = array->nodes[i-1];
    }
    array->nodes[i] = node;
    array->counter++;
}

/*Return the tree whose weight is the lightest of all
 * the trees in the nodes array of the TreeArray in question*/
Tree *pick_node(TreeArray *array) {
    array->counter --;
    return array->nodes[array->counter];
}

/*Build the huffman tree*/
Tree *build_tree(int *tab, int size) {
    TreeArray *array = init_tree_array();
    make_basic_nodes(array, tab, size);
    Tree *tree;

    while (array->counter > 1) {
        Tree *node = malloc(sizeof(Tree));
        node->bits = 0;
        node->left = pick_node(array);
        node->right = pick_node(array);
        node->weight = node->left->weight + node->right->weight;
        insert_node(node, array);
    }
    tree = pick_node(array);
    return tree;
}
    
Tree *search_in_tree(Tree *tree, unsigned int buffer, int bufferSize, int level) {

    /*if there's not enough bits to make a know character*/
    if (level > bufferSize) {
        return NULL;
    }

    /*if we end up on a leaf, we return the char decoded*/
    if (tree->left == NULL && tree->right == NULL) {
        return tree;
    }

    /*If the first bit read is a 0 we go left*/
    if (tree->left != NULL && !(buffer>>(bufferSize - level - 1)&1)) {
        return search_in_tree(tree->left, buffer, bufferSize, level+1);
    }

    /*if the first bit read is a 1 we go right*/
    if (tree->right != NULL && (buffer>>(bufferSize - level - 1)&1)) {
        return search_in_tree(tree->right, buffer, bufferSize, level+1);
    }

    return NULL;


}
