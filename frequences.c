#include "frequences.h"
#include "tree.h"

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
    

Tree *build_tree(int *tab, int* sorted, int size) {

    Tree *rightSon = init_tree(tab[sorted[0]], sorted[0]);
    Tree *leftSon = init_tree(tab[sorted[1]], sorted[1]);

    Tree *init = merge_two_sons(leftSon, rightSon);

    return init;

} 

