#include "frequences.h"
#include "tree.h"

/*Take a file and an empty array, for each char
 * c in the file, it increments the tab[c] value*/
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
    


int find_minimum_weight(Tree **nodes_storage, int size) {
    int min = nodes_storage[0]->weight;
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (nodes_storage[i] != NULL) {
            //printf("%d\n", nodes_storage[i]->weight);
            if (nodes_storage[i]->weight < min) {
                min = nodes_storage[i]->weight;
                index = i;
            }
        }
    }
    return index;
} 
