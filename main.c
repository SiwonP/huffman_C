#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "frequences.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};
    char sort[128] = {0};

    count_frequences(file, tab); 
    make_sorted_array(tab, sort, 128);

    for (int i = 0; i < 128; i++) {
        if (tab[i] > 0) {
            //printf("%c : ", i);
            //printf("%d\n", tab[i]);
        }
    }
    for (int j = 0; j < 128; j++) {
        printf("%d/", sort[j]);
        printf("%d - ", j);
        printf("%c : ", sort[j]);
        printf("%d\n", tab[sort[j]]);
    }
    
    return 1;
}

