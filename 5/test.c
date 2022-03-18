#include <stdio.h>

int a = 0xaa;
int b = 0xbb;

char *s = "You are a girl";
char p[] = "I am a boy";

int main(void)
{
    printf("%02x\n", 0x88);
    printf("%02x\n", a);
    printf("%02x\n", b);

    printf("%s", s);
    printf("%s", p);

    return 0;
}
