#pragma once

#include "list.h"
// #include "list.c"

#include <stdint.h>
#include <stdbool.h>

int_list* init_stack();
int stack_back(int_list *);
void stack_push_back(int_list *, int);
void stack_pop_back(int_list *);
void stack_free(int_list *);