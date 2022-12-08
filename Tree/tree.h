#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct tree_node
{
    int value;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
} tree_node;

tree_node *tree_init_node(int);
tree_node *tree_find_node(tree_node *, int);
tree_node *tree_find_min(tree_node *);
tree_node *tree_find_max(tree_node *);
void tree_insert(tree_node *, int);
bool tree_remove_node(tree_node *, int);
void tree_free(tree_node *);

// void tree_next(tree_node *);