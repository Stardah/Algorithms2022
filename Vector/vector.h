#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct int_vector
{
    int *items;
    int capacity;
    int size;
} int_vector;

int_vector vector_init(size_t);
int vector_size(int_vector *);
bool vector_resize(int_vector *, size_t);
void vector_push_back(int_vector *, int);
bool vector_set(int_vector *, size_t, int);
int *vector_get(int_vector *, size_t);
bool vector_remove_at(int_vector *, size_t);
void vector_free(int_vector *);