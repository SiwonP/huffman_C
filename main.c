#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int tab[128] = {0};
    char c;
    while ((c = fgetc(file)) != EOF) {
        tab[c]++;
    }
    for (int i = 0; i < 128; i++) {
        printf("%c : ", i);
        printf("%d\n", tab[i]);
    }
    return 1;
}
