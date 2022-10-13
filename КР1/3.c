#include <stdio.h>
#include <stdbool.h>

bool is_progression(int a, int b, int c)
{
    if ((a - b) == (b - c))
        return true;
    return false;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int seq[N];
    scanf("%d", &seq[0]);
    scanf("%d", &seq[1]);

    int count = 2;
    int max_count = 2;
    int first_index = 0;
    int max_first_index = 0;

    for (size_t i = 2; i < N; i++)
    {
        scanf("%d", &seq[i]);
        if (is_progression(seq[i - 2], seq[i - 1], seq[i]))
        {
            count++;
        }
        else
        {
            count = 2;
            first_index = i - 1;
        }

        if (count > max_count)
        {
            max_count = count;
            max_first_index = first_index;
        }
    }

    for (size_t i = max_first_index; i < max_first_index + max_count; i++)
    {
        printf("%d ", seq[i]);
    }
    return 0;
}