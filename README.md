# Huffman in C

Here is an implementation of the Huffman compression algorithm from scratch.

## Explanation of the implementation 

### Reading the given file

I start making an array `tab` of 128 integers (representing the 128 Ascii caracters) and for every caracter `c` I read in the given file, I increment the `tab[c]` by 1 until I reach the `EOF`.

### Sorting the character in frequency order

For every character present in the file, I create a tree leaf whose right and left sons are `NULL` and I store them in an array called `nodes_storage`.

### Making the tree

