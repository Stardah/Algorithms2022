#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct int_list
{
    struct list_node *front;
    struct list_node *back;
} int_list;

typedef struct list_node
{
    int value;
    struct list_node *next;
    struct list_node *prev;
} list_node;

list_node* init_node(int);
int_list list_init();
void list_push_back(int_list *, int);
void list_push_front(int_list *, int);
void list_pop_back(int_list *);
void list_pop_front(int_list *);
bool list_is_empty(int_list *);
void list_free(int_list *);