#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int count = 0;
    unsigned int point;

    scanf("%u", &point);

    while (point != 0)
    {
        short x = (point >> 16);
        short y = (point << 16) >> 16;

        if ((x >= 0 && y >= 0) || (x < 0 && y < 0))
            count++;

        scanf("%u", &point);
    }

    printf("%d", count);

    return 0;
}