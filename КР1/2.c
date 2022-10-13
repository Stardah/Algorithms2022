#include <stdio.h>
#include <stdint.h>

/* int foo(int x, int y)
{
    return x * x + y * y;
} */

int bar(int a, int b)
{
    int count = 0;

    for (int x = -a + 2 + 1; x < a + 2; x++) {
        for (int y = -b + 1; y < b; y++)
        {
            int value = foo(x, y);
            if (value < foo(x + 1, y + 1) 
                && value < foo(x + 1, y - 1) 
                && value < foo(x - 1, y + 1) 
                && value < foo(x - 1, y - 1)) {
                count++;
                }
        }
    }
    return count;
}

/* int main(void)
{
    printf("%d", bar(5, 5));
    return 0;
} */