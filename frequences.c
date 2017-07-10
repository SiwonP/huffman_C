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
