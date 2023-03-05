#include <stdio.h>

int main(void)
{
    printf("%d = %c\n", 65, 65);
    printf("%d = %c\n", 'A', 'A');
    if (65 == 'A') {
        printf("A and \'65\' are the same thing\n");
    }

    return 0;
}
