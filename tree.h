#ifndef TREE_H
#define TREE_H
typedef struct Tree Tree;

struct Tree {
    char el;
    int weight;
    Tree *left;
    Tree *right;
};

Tree *init_tree(int, char);

void add_son(Tree*, Tree*, int);

void destroy_tree(Tree*);

void display_tree(Tree*);

Tree *merge_two_sons(Tree*, Tree*);
#endif
