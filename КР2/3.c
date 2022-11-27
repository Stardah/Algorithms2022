#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct ciksa
{
    short s;
    int i;
} ciksa;

typedef struct biburat
{
    long d;
    unsigned u;
} biburat;

typedef struct cell
{
    enum type
    {
        CIKSA,
        BIBURAT,
        EMPTY
    } t;
    union
    {
        ciksa c;
        biburat b;
    };
} cell;

cell *repack(void *soup)
{
    enum type
    {
        CIKSA,
        BIBURAT,
        EMPTY
    };
    
    cell *cells = malloc(1 * sizeof(struct cell));
    size_t cell_i = 0;

    char *input = (char *)soup;

    size_t byte_i = 0;
    int cur_type = 0;

    while ((cur_type = *((int *)(input + byte_i))) != EMPTY)
    {
        byte_i += sizeof(int);
        cells[cell_i].t = cur_type;

        if (cur_type == CIKSA)
        {
            cells[cell_i].c.s = *(short *)(input + byte_i);
            byte_i += sizeof(short);

            cells[cell_i].c.i = *(int *)(input + byte_i);
            byte_i += sizeof(int);
        }
        else
        {
            cells[cell_i].b.d = *(long *)(input + byte_i);
            byte_i += sizeof(long);

            cells[cell_i].b.u = *(unsigned *)(input + byte_i);
            byte_i += sizeof(unsigned);
        }

        cell_i++;
        cells = realloc(cells, (cell_i + 1) * sizeof(cell)); // Гарантируется наличие памяти
    }

    cells[cell_i].t = EMPTY;

    return cells;
}

void print_cells(cell *cells)
{
    int i = 0;
    int type = 0;
    while ((type = cells[i].t) != EMPTY)
    {
        printf("%d\n", cells[i].t);
        i++;
    }
}

int main(void)
{
    cell *cells = malloc(2 * sizeof(struct cell));
    cells[0].t = CIKSA;
    cells[0].c.i = 10;
    cells[0].c.s = 1;
    // cells[1].t = BIBURAT;
    // cells[1].b.d = 10;
    // cells[1].b.u = 1;
    cells[1].t = EMPTY;

    void *ptr = realloc(cells, 2 * sizeof(struct cell));

    print_cells(repack(ptr));
    return 0;
}