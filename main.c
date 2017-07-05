#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "frequences.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};
    count_frequences(file, tab);
    
    for (int i = 0; i < 128; i++) {
        if (tab[i] > 0) {
            printf("%c : ", i);
            printf("%d\n", tab[i]);
        }
   }
    printf("%d", count_present_char(tab, 128));
    return 1;
}

