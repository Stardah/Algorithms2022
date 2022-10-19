#include <stdio.h>
#include <stdint.h>
#include <wchar.h>
#include <string.h>

void copy_string(char *dst, const char *src, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        dst[i] = *(src++);
    }
}

int main(void)
{
    // Разные спопобы задать строку
    char s1[] = "последовательность символов"; // const char *
    wchar_t s2[] = L"unicode string";
    char s3[10] = "ok"; // s[0]='o', s[1]='k', s[2]= '\0'
     
    char *wrong = "wrong";
    // wrong[0] = "i"; // так не работает  

    wprintf(L"%ls\n", s2);

    // Длина строки
    const int length = sizeof(s3) / sizeof(char);

    // Копирование
    char *dst; // это const char *
    copy_string(dst, s3, length);

    *dst = 'c';
    // Считывание строки
    char str[5];

    printf("Ввод с помощью fgets:\n"); // ввод заканчивается после EOF или перевода строки
    fgets(str, sizeof(str), stdin);
    printf("%s\n", str);

    // scanf("%s", str) - опасно, так как размер вводимой строки не ограничивается
    printf("Ввод с помощью scanf:\n");
    scanf("%9s", str); // ввод происходит до символа пробел, переноса строки или достижения указанного лимита
    printf("%s\n", str);
    const len1 = strlen(str);
    const len2 = sizeof(str);    
    fwrite(str, sizeof(char), sizeof(str), stdout);     
    puts("");
    puts(str);
    fputs(str, stdout);
    /*     
    int fprintf(FILE * stream, const char *format, ...);
    int sprintf(char * str, const char *format, ...);
    int snprintf(char * str, size_t size, const char *format, ...);
    int fscanf(FILE *stream, const char *format, ...);
    int sscanf(const char * str, const char *format, ...) 
    */

    return 0;
}