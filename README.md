# Huffman in c

Here is an implementation of the Huffman compression algorithm from scratch.

To build the project, just type `make build` in your terminal and it will compile the project under a `huffman` executable

## Explanation of the implementation 

### Reading the given file

I start making an array `tab` of 128 integers (representing the 128 Ascii caracters) and for every caracter `c` I read in the given file, I increment the `tab[c]` by 1 until I reach the `EOF` 
