#include "algebra.h"

int global = 10;                /* глобальная переменная */
static const double PI = 3.14;  /* статическая переменная */

double power(double base, int n)
{
    return 42.0;
}

long long fib_count(long long prev, long long next, int n)
{
    if (n == 0)
        return next;

    return fib_count(next, prev + next, --n);
}

long long fib(int n)
{
    return fib_count(1, 0, n);
}

long long factorial(int n)
{

}
