CC=gcc

build: main.c frequences.c tree.c
	$(CC) $^ -o huffman
