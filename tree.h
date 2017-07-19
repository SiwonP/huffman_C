#ifndef TREE_H
#define TREE_H
typedef struct Tree Tree;

struct Tree {
    int el;
    int weight;
    int code;
    int bits;
    Tree *left;
    Tree *right;
};

typedef struct TreeArray TreeArray;

struct TreeArray {
    int counter;
    Tree *nodes[128];
};

Tree *init_tree(int, int);

void destroy_tree(Tree*);

void display_tree(Tree*);

void make_basic_nodes(TreeArray*, int*, int);

void insert_node(Tree*, TreeArray*);

TreeArray *init_tree_array(void);

Tree *pick_node(TreeArray*);

Tree *build_tree(int*, int);

Tree *search_in_tree(Tree*, unsigned int, int, int);
#endif
