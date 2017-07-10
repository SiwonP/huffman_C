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

