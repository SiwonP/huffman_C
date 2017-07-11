#include <stdio.h>
#include "tree.h"
#include "frequences.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};

    count_frequences(file, tab);

    Tree *tree = build_tree(tab, 128);

    display_tree(tree);
    destroy_tree(tree);
    return 1;
}

