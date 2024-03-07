#include <stdio.h>

int main(void)
{
   int a = 10;
   int b = 20;

   int *p = &a;
   *p += 10;
   printf("%d %d\n", a, b);

   a = 10;
   b = 20;
   double *q = &a;
   *q += 10;
   printf("%d %d\n", a, b);

   return 0;
}
