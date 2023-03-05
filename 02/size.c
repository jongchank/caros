#include <stdio.h>

int main(void)
{
    int A[5];

    printf("%ld\n", sizeof(A));
    printf("%ld\n", sizeof(A[0]));
    printf("%ld\n", sizeof(A) / sizeof(A[0]));

    return 0;
}
