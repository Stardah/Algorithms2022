#include "vector.h"

#include <stdlib.h>

#define EXPANSION_K (2)

int_vector vector_init(size_t size)
{
    int_vector vec = {
        .items = calloc(size, sizeof(int)),
        .size = 0,
        .capacity = size};
    return vec;
}

int vector_size(int_vector *v)
{
    return v->size;
}

static bool vector_set_capacity(int_vector *v, size_t new_capacity)
{
    int *p = realloc(v->items, new_capacity * sizeof(int));

    if (p == NULL)
    {
        return false;
    }

    v->items = p;
    v->capacity = new_capacity;

    return true;
}

bool vector_resize(int_vector *v, size_t new_size)
{
    int cap = new_size;

    if (new_size <= v->capacity)
    {
        cap = v->capacity;
    }
    else if (!vector_set_capacity(v, new_size))
    {
        return false;
    }

    for (size_t i = v->size; i < cap; i++)
    {
        v->items[i] = 0;
    }
    
    v->size = new_size;

    return true;
}

void vector_push_back(int_vector *v, int item)
{
    if (v->size >= v->capacity)
    {
        vector_set_capacity(v, v->capacity * EXPANSION_K);
    }

    v->items[v->size] = item;
    v->size++;
}

bool vector_set(int_vector *v, size_t idx, int item)
{
    if (idx >= v->size)
    {
        return false;
    }

    v->items[idx] = item;

    return true;
}

int *vector_get(int_vector *v, size_t idx)
{
    if (idx >= v->size)
    {
        return NULL;
    }

    return v->items + idx;
}

bool vector_remove_at(int_vector *v, size_t idx)
{
    if (idx >= v->size)
    {
        return false;
    }

    for (size_t i = idx; i < v->size; i++)
    {
        v->items[i] = v->items[i + 1];
    }

    // memmove(v->items + idx, v->items + idx + 1, v->size - idx - 1);

    v->size--;

    return true;
}

void vector_free(int_vector *v)
{
    v->capacity = 0;
    v->size = 0;
    free(v->items);
}