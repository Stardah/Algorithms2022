#include "tree.h"
#include "list.h"
#include "list.c"

#include <stdlib.h>
#include <stdio.h>

tree_node *tree_init_node(int value)
{
    tree_node *node = malloc(sizeof(tree_node));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->value = value;
    return node;
}

tree_node *tree_find_node(tree_node *t, int value)
{
    if (t->value == value)
    {
        return t;
    }

    if (value > t->value && t->right != NULL)
    {
        return tree_find_node(t->right, value);
    }
    else if (value < t->value && t->left != NULL)
    {
        return tree_find_node(t->left, value);
    }

    return NULL;
}

tree_node *tree_find_min(tree_node *t)
{
    while (t->left != NULL)
    {
        t = t->left;
    }
    return t;
}

tree_node *tree_find_max(tree_node *t)
{
    while (t->right != NULL)
    {
        t = t->right;
    }
    return t;
}

void tree_insert(tree_node *t, int value)
{
    if (value < t->value)
    {
        if (t->left == NULL)
        {
            tree_node *new_node = init_node(value);
            new_node->parent = t;
            t->left = new_node;
        }
        else
        {
            tree_insert(t->left, value);
        }
    }
    else if (value > t->value)
    {
        if (t->right == NULL)
        {
            tree_node *new_node = init_node(value);
            new_node->parent = t;
            t->right = new_node;
        }
        else
        {
            tree_insert(t->right, value);
        }
    }
}

bool tree_remove_node(tree_node *t, int value)
{
    tree_node *node = tree_find_node(t, value);
    if (node != NULL)
    {
        // Right side
        if (node->value > node->parent->value)
        {
            if (node->left != NULL)
            {
                node->parent->right = node->left;
                tree_find_min(node->left)->right = node->right;
            }
            else
            {
                node->parent->right = node->right;
            }
        }
        // Left side
        if (node->value < node->parent->value)
        {
            if (node->right != NULL)
            {
                node->parent->left = node->right;
                tree_find_min(node->right)->left = node->left;
            }
            else
            {
                node->parent->left = node->left;
            }
        }

        free(node);
        return true;
    }

    return false;
}

void *free_nodes(tree_node *t)
{
    if (t->left != NULL)
    {
        free_nodes(t->left);
    }
    if (t->right != NULL)
    {
        free_nodes(t->right);
    }
    free(t->left);
    free(t->right);
}

void tree_free(tree_node *t)
{
    free_nodes(t);
    free(t);
}

int main(int argc, char const *argv[])
{
    tree_node *root = tree_init_node(10);

    tree_insert(root, 5);
    tree_insert(root, 15);
    tree_insert(root, 3);
    tree_insert(root, 0);
    tree_insert(root, 4);
    tree_insert(root, 2);

    // print_tree(root, 0);
    // print_tree_queue(root);

    tree_free(root);
    return 0;
}
