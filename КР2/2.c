#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *input)
{

    const char *hexes[16] = {
        "0000",
        "0001",
        "0010",
        "0011",
        "0100",
        "0101",
        "0110",
        "0111",
        "1000",
        "1001",
        "1010",
        "1011",
        "1100",
        "1101",
        "1110",
        "1111",
    };

    const long long str_len = strlen(input);

    char *hex = malloc((str_len * 4 + 1) * sizeof(char));

    size_t hex_len = 0;

    char ch;
    size_t bin_i = 0;
    while ((ch = input[bin_i]) != '\0')
    {
        int digit = ch;

        if (ch <= '9')
            digit = digit - '0';
        else if (ch <= 'Z')
            digit = digit - 'A' + 10;
        else
            digit = digit - 'a' + 10;

        for (size_t i = hex_len; i < hex_len + 4; i++)
        {
            hex[i] = hexes[digit][i - hex_len];
        }

        hex_len += 4;
        bin_i++;
    }
    hex[hex_len] = '\0';
    // printf("%s", hex);
    free(input);
    return hex;
}

/* int main(void)
{
    char* input = malloc(7);
    strcpy(input, "C0ffee");
    char * result = convert(input);
    printf("%s", result);
    return 0;
} */