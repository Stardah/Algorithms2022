#include <stdlib.h>

void forgotten_pointer()
{
    long long *array = malloc(100 * sizeof(long long));

    long long *p = realloc(array, 200 * sizeof(long long));

    // Теперь использование array - UB
    *array = 10;
    free(p);
}

void classic_memory_leak()
{
    char *str = malloc(1000000 * sizeof(char)); // ~1мб

    // После завершения выполнения процедуры
    // указатель очистится
    // а зарезервированная на куче память останется
    // free(str);
}

void nested_memory_leak()
{
    const int array_size = 100;
    int **array2d;
    array2d = malloc(array_size * sizeof(int));

    for (size_t i = 0; i < array_size; i++)
    {
        int *sub_array = malloc(array_size * sizeof(int));
        array2d[i] = sub_array;
    }

    free(array2d);
    // array2d освобождена
    // а вот все выделения для sub_array
    // до сих пор зарезервированы в памяти
    // for (int i = 0; i < array_size; i++) {
    //     free(x[i]);
    // }
}

// Процедуры, которые не подчищают за собой память, опасны
char *fill(char value)
{
    char *p = malloc(100 * sizeof(char));
    for (size_t i = 0; i < 100; i++)
    {
        p[i] = value;
    }
    return p;
}

void function_leak()
{
    char *str[1];
    str[0] = fill('G'); // Утечка (´。＿。｀)
}

_Bool return_leak(int value) {
    char *p = malloc(100 * sizeof(char));
    
    if (value)
        return 1;

    free(p);
    return 0;
}

int main(void)
{
    // forgotten_pointer();
    // classic_memory_leak();
    // nested_memory_leak();
    // function_leak();
    // return_leak(11);
    return 0;
}
