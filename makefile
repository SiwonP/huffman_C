CC=gcc

build: main.c frequences.c tree.c
	$(CC) $^ -o huffman

debug: main.c frequences.c tree.c
	$(CC) $^ -o huffman -g
