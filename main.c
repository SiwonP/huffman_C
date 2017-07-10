#include <stdio.h>
#include "tree.h"
#include "frequences.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};

    count_frequences(file, tab);

    TreeArray *array = malloc(sizeof(TreeArray));
    make_basic_nodes(array, tab, 128);

    for (int n = 0; n < 128; n++) {
        display_tree(array->nodes[n]);
        destroy_tree(array->nodes[n]);
    }
    fclose(file);
    return 1;
}

