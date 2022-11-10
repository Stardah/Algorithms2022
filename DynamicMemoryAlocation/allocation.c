#include <stdlib.h>
#include <string.h>

int main(void)
{
    // void *malloc (size_t n); - memory-alloc
    // void *calloc (size_t n, size_t size); - clear-alloc - заполняет выделяемую область нулями 
    // void *realloc (void *ptr, size_t size);
    // void free (void *p); 

    long long *array = malloc(100 * sizeof(long long)); // ~ realloc(NULL, _Size);
    long long *array_0 = calloc(100, sizeof(long long));

    // По возможности realloc выделит дополнительную память там же
    // иначе выделит память в новой области кучи
    long long *p = realloc(array, 200);
    if (NULL)

    array = p;
    
    free(array); // ~ realloc(_Block, 0);
    free(array_0);


    // void memset(void *s, int c, size_t n); Заполняет память байтом c
    char str[5];
    memset(str, 'G', 9);

    // void memcpy(void *dst, const void *src, size_t n); Копирует содержимое памяти
    char str_cpy[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    memcpy(str_cpy+1, str_cpy, 3);

    // void memmove(void *dst, const void *src, size_t n); - memcpy with memory overlapping check
    char str_move[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    memmove(str_move+1, str_move, 3);
    return 0;
}
