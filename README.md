# Huffman in c

Here is an implementation of the Huffman compression algorithm from scratch.

## Explanation of the implementation 

### Reading the given file

I start making an array `tab` of 128 integers (representing the 128 Ascii caracters) and for every caracter `c` I read in the given file, I increment the `tab[c]` by 1 until I reach the `EOF` 

### Sorting the character in frequency order

I create a second array `sorted` made of 128 char sorted according to its frequency in the original file. For exemple for an integer `i`, `sorted[i]` has a frequency of `tab[sorted[i]]`
