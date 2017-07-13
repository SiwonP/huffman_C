CC=gcc

build: main.c frequences.c tree.c compression.c decompression.c
	$(CC) $^ -o huffman

debug: main.c frequences.c tree.c compression.c decompression.c
	$(CC) $^ -o huffman -g
