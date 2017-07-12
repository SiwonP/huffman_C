#include <stdio.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"
#include "dictionary.h"

int main(int argc, char *argv[]) {
    char out[] = "huf";

    compress(argv[1], out);

    
    return 1;
}

