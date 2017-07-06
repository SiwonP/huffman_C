#ifndef LIST_H
#define LIST_H
#include "character.h"

typedef struct List List;

struct List {
    Character *c;
    List *next;
};

List *initialisation(void);

void insert_at_the_end(List*, Character*);

void display_list(List*);

#endif
