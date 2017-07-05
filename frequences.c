#include "frequences.h"

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
