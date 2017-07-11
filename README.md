# Huffman in C

Here is an implementation of the Huffman compression algorithm from scratch.

## Explanation of the implementation 

### Reading the given file

I start making an array `tab` of 128 integers (representing the 128 Ascii caracters) and for every caracter `c` I read in the given file, I increment the `tab[c]` by 1 until I reach the `EOF`.

### Making the first basics tree leaves

I created a type called TreeArray which is basically a struct containing an int representing the counter of how many trees there are in its second field which is a Tree array called `nodes`.
I make all the tree leaves at once and store them in this particular array of the TreeArray instance.
The thing is, that this so called array is sorted : the first index stores the most present char in the file and the last the least present char.
Everytime I sort-insert a Tree in this array, I increment the counter of the TreeArray instance so that when all leaves are created and stored, I know how many there are because I don't store characters not presents in the file.

### Making the tree

I keep working with this TreeArray. Its counter now show how many Trees I have to deal with left.
So, while its counter hasn't reached 1, I keep doing the following :

I create a new Tree instance, and I picked the Tree of the TreeArray array whose index is counter-1 (which is in fact the last one) and make it the new tree's left son.

I do the same for the right son of this new tree.

I've just decremented the counter by 2 as I picked two trees.
Now I sort-insert this new tree into the TreeArray's array and increment its counter by one as it is one new Tree I'll have to deal with.

So the counter decrements by 2 and increments by 1 so It should reach 1 eventually

Once it does I return the last Tree which is a pointer to the root of the huffman tree

### Figuring out the codes of the Huffman tree's leaves



