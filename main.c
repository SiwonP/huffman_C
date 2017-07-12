#include <stdio.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"
#include "dictionary.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};
    Entry dic[128];

    count_frequences(file, tab);

    Tree *tree = build_tree(tab, 128);
    store_code(tree, dic, 0,0);

    display_tree(tree);
    destroy_tree(tree);
    return 1;
}

