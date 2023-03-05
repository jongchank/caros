#include <stdio.h>

int g = 0;

void func(void)
{
    return;
}

int main(void)
{
    int l = 0;
    printf("%p %p %p %p\n", &g, &func, &main, &l);
    return 0;
}
