#include "frequences.h"
#include "tree.h"
#include "character.h"

void count_frequences(FILE *file, int *tab){
    char c;
    while((c=fgetc(file)) != EOF) {
        tab[c]++;
    }
}

int count_present_char (int *tab, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        if (tab[i] > 0) {
            res++;
        }
    }
    return res;
}

void make_sorted_array(int *tab, char *sorted, int size) {

    for (int i = 0; i < size; i++) {
        sorted[i] = i;
    }
    
    insertion_sort(tab, sorted, size);
}

void insertion_sort(int *tab, char *sorted, int size) {
    char c;
    int j;
    int i;
    for (i = 0; i < size; i++) {
        c = sorted[i];
        for (j = i; j > 0 && tab[sorted[j-1]] > tab[c]; j--) {
            sorted[j] = sorted[j-1];
        }
        sorted[j] = c;
    }
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

