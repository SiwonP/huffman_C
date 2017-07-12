# Huffman in C

Here is an implementation of the Huffman compression algorithm from scratch.

## Explanation of the implementation 

### The compression

##### Reading the given file

I start making an array `tab` of 128 integers (representing the 128 Ascii caracters) and for every caracter `c` I read in the given file, I increment the `tab[c]` by 1 until I reach the `EOF`.

##### Making the first basics tree leaves

I make all the leaves of the huffman tree made from the `tab` elements whose weight are greater than 0 and store them sorted in a array. For every leaf inserted in this array I increment a `counter`.

##### Making the tree

I take the two lightest leaves, decrement the `counter` by 2 and make a new tree out of them. Then I inserted this new tree in the previous array, so that it is still sorted, and I repeat the process until the counter reaches 1, which gives me the root.

##### Figuring out the codes of the Huffman tree's leaves

To store the new huffman code in the leaves I go down the tree from the root, insert the code in the node if it's a leaf. Every time I reache a Tree which is not a leaf, I left bit shift the code and apply the function to its left son, and I left bit shift and add 1 to the code and apply the function to its right son.
As I do this, I also store the huffman code and the number of its bits in an array of 128 `struct Entry` containing the code and the number of bits

##### Encode the file


