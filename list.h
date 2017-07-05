#ifndef LIST_H
#define LIST_H

typedef struct List List;

struct List {
    List *next;
};

List *initialisation(void);

void insert_at_the_end(List*);

void display_list(List*);

#endif
