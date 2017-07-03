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
void add_son(Tree*, char, int, int);
void destroy_tree(Tree*);
#endif
