#include "vector.h"

#include <stdio.h>

void print_array(const int a[], int length)
{
    // вывод элементов массива
    for (size_t i = 0; i < length; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    int_vector vec = vector_init(1);
    vector_push_back(&vec, 0);
    vector_push_back(&vec, 1);
    vector_push_back(&vec, 2);
    vector_push_back(&vec, 3);
    vector_push_back(&vec, 4);
    vector_push_back(&vec, 5);
    vector_remove_at(&vec, 3);
    vector_set(&vec, 0, 10);
    vector_set(&vec, vec.size - 1, 10);
    vector_resize(&vec, 10);
    
    print_array(vec.items, vec.size);
    printf("Capacity: %d\nSize: %d", vec.capacity, vec.size);
    
    vector_free(&vec);

    return 0;
}