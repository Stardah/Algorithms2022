#include <string.h>
#include <stdio.h>

void print_array(int *a, int length)
{
    for (size_t i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void prefix_function(int *pi, char *str)
{
    int j = 0;
    pi[0] = 0;
    size_t length = strlen(str);

    for (size_t i = 1; i < length; i++)
    {
        j = pi[i - 1];
        while (j > 0 && str[j] != str[i])
        {
            j = pi[j - 1];
        }

        if (str[j] == str[i])
            j++;

        pi[i] = j;
    }
}


int main(int argc, char const *argv[])
{
    char str[] = "ababc";
    int pi[strlen(str)];

    prefix_function(pi, str);
    print_array(pi, sizeof(pi) / sizeof(int));

    return 0;
}


/* Предполагается, что и строка, и массив начинаются с 1 */
void prefix_function_from_1(int *pi, char *str)
{
    int j = 0;
    pi[1] = 0;

    for (size_t i = 2; i <= strlen(str); i++)
    {
        while (j > 0 && str[j + 1] != str[i])
        {
            j = pi[j];
        }

        if (str[j + 1] == str[i])
            j++;

        pi[i] = j;
    }
}