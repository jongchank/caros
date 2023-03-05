#include <stdio.h>

int main(void)
{
    int A[5] = {1, 2, 3, 4, 5};
    int i;

    printf("*A, A[0]: %d %d\n", *A, A[0]);

    for (i = 0; i < 5; i++) {
        printf("====================\n");
        printf("*(A + %d), A[%d]: %d %d\n", i, i, *(A + i), A[i]);
        printf("  A + %d, &A[%d]: %p %p\n", i, i, A + i, &A[i]);
    }
    return 0;
}
