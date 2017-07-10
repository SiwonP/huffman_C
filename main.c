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
    //Tree *node = build_tree(tab,sort,128);

    //display_tree(node);
    //destroy_tree(node);
    

    TreeArray *array = malloc(sizeof(TreeArray));
    make_basic_nodes(array, tab, 128);

    for (int n = 0; n < 128; n++) {
        display_tree(array->nodes[n]);
        destroy_tree(array->nodes[n]);
    }
    fclose(file);
    return 1;
}

