#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "frequences.h"
#include "compression.h"
#include "dictionary.h"
#include "decompression.h"

int main(int argc, char *argv[]) {
    if (!strcmp("-c", argv[1])) {
        printf("compressing ...\n");
        compress(argv[2], argv[3]);
        printf("done");
    } else if (!strcmp("-d", argv[1])){
        decompress(argv[2], argv[3]);
    } else {
        printf("help");
    }


    return 1;
}

