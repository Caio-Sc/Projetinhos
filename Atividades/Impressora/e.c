#include <stdio.h>

int main()
{
int a = 3, b = 4, c = 5;
int res1 = a + ++b * c;
int res2 = a + b * c;
printf ("%d\n", res1);
printf ("%d\n", res2);
    return 0;
}