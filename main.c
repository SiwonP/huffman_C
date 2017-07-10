#include <stdio.h>
#include "tree.h"
#include "frequences.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};

    count_frequences(file, tab);
    TreeArray *array = init_tree_array();

    printf("%d", array->counter);

    return 1;
}

