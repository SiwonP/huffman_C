CC=gcc

build: main.c frequences.c
	$(CC) $^ -o huffman
