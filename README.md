# Huffman in C

Here is an implementation of the Huffman compression algorithm from scratch.

## Explanation of the implementation 

### The compression

#### Reading the given file

I start making an array `tab` of 128 integers (representing the 128 Ascii caracters) and for every caracter `c` I read in the given file, I increment the `tab[c]` by 1 until I reach the `EOF`.

#### Making the first basics tree leaves

I make all the leaves of the huffman tree made from the `tab` elements whose weight are greater than 0 and store them sorted in a array. For every leaf inserted in this array I increment a `counter`.

#### Making the tree

I take the two lightest leaves, decrement the `counter` by 2 and make a new tree out of them. Then I inserted this new tree in the previous array, so that it is still sorted, and I repeat the process until the counter reaches 1, which gives me the root.
I should destroy all the stored trees btw...

#### Figuring out the codes of the Huffman tree's leaves

To store the new huffman code in the leaves I go down the tree from the root, insert the code in the node if it's a leaf. Every time I reache a Tree which is not a leaf, I left bit shift the code and apply the function to its left son, and I left bit shift and add 1 to the code and apply the function to its right son.
As I do this, I also store the huffman code and the number of its bits in an array `dic` of 128 `struct Entry` containing the code and the number of bits

#### Encode the file

##### Storing the frequences index

I run through the `tab` array and for every element superior to 0, I write in the archive file its index and its value. 
In other words I write the frequency and the character.
When I'm done with the `tab` I write a `char delimiter = 2`

##### Writing the encoded information

I put the cursor at the beginning of the file with a `rewind`. After that, for each character `c` I read, I write the code `dic[c]->code` in the new archive file.
I repeat this until I reach `EOF`.

### The decompression

#### Reading the index

I start by reading every pair of input which correspond to a character and its frequency until I reach a `char` equal to 2.
I store this info in a `tab` which is the same as for the compression.

#### Making the tree

Since I have the same `tab`, I make a new identical tree out of it with the same `build_tree`function.

#### Finding the huffman code

Same tree equals the possibilty of reusing the function `store_code` which give me the code used to compress the file.

## Installation

```
git clone https://github.com/SiwonP/huffman_C && cd huffman_C && make
```
