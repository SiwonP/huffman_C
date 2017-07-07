# Huffman in C

Here is an implementation of the Huffman compression algorithm from scratch.

## Explanation of the implementation 

### Reading the given file

I start making an array `tab` of 128 integers (representing the 128 Ascii caracters) and for every caracter `c` I read in the given file, I increment the `tab[c]` by 1 until I reach the `EOF` 

### Sorting the character in frequency order

I create a second array `sorted` made of 128 char sorted according to its frequency in the original file. For exemple for an integer `i`, `sorted[i]` has a frequency of `tab[sorted[i]]`

### Making the tree

I start by making 2 nodes which are initiated by `init_tree(tab[sorted[0]], sorted[0])` and by `init_tree(tab[sorted[1]], sorted[1])`. In other words, I make two trees with no sons with the two least frequents character (indexes 0 and 1 since the `sorted` array is ... well ... sorted). After that I merge thoses nodes into a `init` tree whose weight is the sum of the two above, and whose char is -1, because, since it's not a leaf, it doesn't refer to any character to code.
