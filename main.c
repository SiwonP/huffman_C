#include <stdio.h>
#include "tree.h"
#include "frequences.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};
    char sort[128] = {0};

    count_frequences(file, tab); 
    make_sorted_array(tab, sort, 128);

    for (int i = 0; i < 128; i++) {
        if (tab[i] > 0) {
            //printf("%c : ", i);
            //printf("%d\n", tab[i]);
        }
    }
    for (int j = 0; j < 128; j++) {
        //printf("%d/", sort[j]);
        //printf("%d - ", j);
        //printf("%c : ", sort[j]);
        //printf("%d\n", tab[sort[j]]);
    }
    Tree *node;
    node = malloc(sizeof(Tree));
    node->left = NULL;
    node->right = NULL;
    node->weight = 0;
    node->el = 1;

    Tree *l;
    l = malloc(sizeof(Tree));
    l->left = NULL;
    l->right = NULL;
    l->weight = 1;
    l->el = 1;

    display_tree(node);
    destroy_tree(node);

    return 1;
}

