#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80] = "test string";
    char str2[80] = "test string1";

    printf("Длина str1: %d\n", strlen(str1));
    if (!strcmp(str1, str2)) // сравнение строк; 0 при s1 == s2; -1 при s1 < s2; 1 при s1 > s2
        printf("строки равны\n");

    strcat(str1, str2);
    
    char *entry1 = strchr(str1, 's'); // вхождение символа в строку
    char *entry2 = strstr(str1, "string"); // вхождение строки в строку
    char *sep = strtok(str1, "s,.! i"); // вхождение символов из набора в строку

    printf("%s\n", str1);

    char str[80];
    sprintf(str, "Так и запишем: %s", str1);
    puts(str);
    return 0;
}