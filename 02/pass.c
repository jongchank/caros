#include <stdio.h>


void show(short arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return;
}

int main(void)
{
    short arr[5] = {3, 9, 1, 5, 7};

    show(arr, 5);
    printf("\n");

    return 0;
}
