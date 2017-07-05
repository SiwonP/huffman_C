#include "token.h"

typedef struct Element Element;

struct Element{
    token *el;
    Element *next;
};

typedef struct List List;

struct List {
    Element *premier;
};

List *initialisation(void);

void insert_at_the_end(List*, token*);

void display_list(List*);
