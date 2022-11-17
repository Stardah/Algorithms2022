#include <stdio.h>

#define FILE_NAME "text.txt"

int main(int argc, char const *argv[])
{
    /* FILE *fopen(const char *filename, const char *mode); - открывает файл */
    /* mode:
        r - read
        w - write
        a - append
        чтоние и запись:
        r+ -
        w+ - создаёт новый файл, если требуется
        a+ - устанавливает текущую позицию в конец файла
        rb, wb ... - чтение бинарного файла
    */
    /* int fclose(FILE *stream); - закрывает файл */
    /* FILE *freopen (const char *name, const char *mode, FILE *f);
        freopen = fclose + fopen
    */

    FILE *file = fopen(FILE_NAME, "w");

    fprintf(file, "Hello, file!");

    fclose(file);

    file = fopen(FILE_NAME, "r");

    char ch;
    while (fscanf(file, "%c", &ch) == 1) {
        printf("%c", ch);
    }

    fclose(file);

    /* 
        int fscanf ( FILE *f , const char * format , ...);
        int fprintf ( FILE *f , const char * format , ...);
        int fgetc ( FILE * f );
        int fputc ( int c , FILE * f );
        char * fgets ( char *s , int n , FILE * f );
        int fputs ( char *s , FILE * f );
     */

    return 0;
}
