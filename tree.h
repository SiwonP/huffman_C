#ifndef TREE_H
#define TREE_H
typedef struct Tree Tree;

struct Tree {
    char el;
    int weight;
    Tree *left;
    Tree *right;
};

typedef struct TreeArray TreeArray;

struct TreeArray {
    int counter;
    Tree *nodes[128];
};

Tree *init_tree(int, char);

void destroy_tree(Tree*);

void display_tree(Tree*);

void make_basic_nodes(TreeArray*, int*, int);

void insert_node(Tree*, TreeArray*);

TreeArray *init_tree_array(void);
#endif
