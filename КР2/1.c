#include <stdio.h>
#include <stdint.h>

int estimate_success(int exams, int students)
{
    int success = students;
    if (exams == 0)
        return success;

    for (size_t i = 0; i < exams; i++)
    {
        success = (int)(success * 0.8);
    }

    return success;
}

int main(void)
{
    char *days_names[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    int N = 0;
    scanf("%d", &N);

    int days[7] = {0};

    int students = 0;
    int exams = 0;
    for (size_t i = 0; i < N; i++)
    {
        scanf("%d", &students);
        for (size_t j = 0; j < 7; j++)
        {
            scanf("%d", &exams);
            days[j] = days[j] + (int)estimate_success(exams, students);
        }
    }

    int max_day = 0;
    int max_idx = 0;
    for (size_t i = 0; i < 7; i++)
    {
        if (max_day < days[i])
        {
            max_day = days[i];
            max_idx = i;
        }
    }

    printf("%s", days_names[max_idx]);

    return 0;
}