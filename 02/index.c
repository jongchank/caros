#include <stdio.h>

int main(void)
{
    short A[4] = {1, 2, 3, 4};
    short B[4] = {5, 6, 7, 8};

    printf("%d\n", B[3]);
    A[7] = 99;
    printf("%d\n", B[3]);

    return 0;
}
