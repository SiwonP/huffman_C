#include "frequences.h"
#include "tree.h"
#include "list.h"

void count_frequences(FILE *file, int *tab){
    char c;
    while((c=fgetc(file)) != EOF) {
        tab[c]++;
    }
}

List *count_present_char (int *tab, int size) {
    List *liste = initialisation();
    int res = 0;
    for (int i = 0; i < size; i++) {
        if (tab[i] > 0) {
            res++;
        }
    }

    return liste;
}

Tree *build_tree(int *tab, int size) {
    int min = 1;

    for (int i = 0; i < size; i++) {
        if (tab[i] > 0 && tab[i] < min) {
            min = tab[i];
        }
    }

    Tree *node = init_tree(0,0);

    return node;
} 
