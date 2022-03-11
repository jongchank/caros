#include <stdio.h>

int main(void)
{
    unsigned char uc = 255;
    uc++;
    printf("%u\n", uc);

    uc = 0;
    uc--;
    printf("%u\n", uc);

    char sc = 127;
    sc++;
    printf("%d\n", sc);

    sc = -128;
    sc--;
    printf("%d\n", sc);

    return 0;
}
