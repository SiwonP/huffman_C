#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

void decompress(char*, char*);

void read_frequences(FILE*, int*);

void decode(FILE*, FILE*, int*, Tree*);
#endif
