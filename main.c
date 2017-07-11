#include <stdio.h>
#include "tree.h"
#include "frequences.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};

    count_frequences(file, tab);
    TreeArray *array = init_tree_array();

    make_basic_nodes(array, tab, 128);

    printf("%d", array->counter);

    int i = 0;
    while(array->nodes[i] != NULL) {
        display_tree(array->nodes[i]);
        i++;
    }

    return 1;
}

