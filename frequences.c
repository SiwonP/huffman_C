#include "frequences.h"
#include "tree.h"
#include "list.h"
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

char *make_sorted_array(int *tab, int size) {
    static char res[128] = {0};

    for (int i = 0; i < size; i++) {
        res[i] = i;
    }
    return res;
}

void insertion_sort(int *tab, char *sorted, int size) {
    char c;
    int j;
    for (int i = 1; i < size; i++) {
        c = sorted[i];
        j = i;
        while (j > 0 && tab[sorted[i-1]] > tab[c]) {
            sorted[j] = sorted[j-1];
            j = j-1;
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
