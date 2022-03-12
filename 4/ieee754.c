#include <stdio.h>

int main(void)
{
    float a = 0.001f; 

    printf("%f\n", a);
    printf("%35.33f\n", a);

    printf("%02x %02x %02x %02x\n",
        ((unsigned char *)&a)[0],
        ((unsigned char *)&a)[1],
        ((unsigned char *)&a)[2],
        ((unsigned char *)&a)[3]); 
    return 0;
}
