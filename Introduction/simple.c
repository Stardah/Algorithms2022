/* Простая программа на Си, показывающая определение
функций, объявления глобальных и локальных
переменных.
Это пример многострочного комментария */ 

// В Си-99 возможны такие однострочные комментарии
// Включение заголовочного файла

#include <stdio.h>

#include <stdbool.h>

// #include "algebra.h"

#define A_NUMERIC_CONSTANT (1234)

int count = 0;              /* глобальная переменная */
static int inner_сount;      /* статическая переменная */
const long MY_NUMBER = 31L; /* константа long int */
const long MY_NUMBER_8 = 037; /* константа long int */
const long MY_NUMBER_16 = 0x1F; /* константа long int */

// long* ptr = &MY_NUMBER;
// const long* const_ptr = &MY_NUMBER;
// const long* ptr_to_constant = &A_NUMERIC_CONSTANT; // Это не работает!!!

void sum(int x, int y) /* определение функции */
{
    printf("сумма %d и %d равна %d\n", x, y, x + y);
    count++;
}

void func(void)
{
    int count = 0; /* локальная переменная */
    count = count - 2;
}

int main(void)
{
    int a, b; // другие локальные переменные

    count = 0;
    scanf("%d", &a); /* & как обозначение адреса (взятие адреса) */
    scanf("%d", &b);

    sum(a, b);
    b = b * 3;
    sum(a, b);
    func();
    printf("Вызвали функцию sum %d раз\n", count);

    // printf("%d\n", fib(10));
    // printf("%d", global);
    // printf("%d", PI);

    return 0;
}
