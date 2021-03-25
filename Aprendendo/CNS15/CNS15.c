//CNS13 - Múltiplos de 9
//Caio Sclavi 25/03
#include <stdio.h>

int main()
{
    int N;
    for(int i = 0; i <= 500000; i ++)
    {
        N = i * 9;
        printf("%d\t", N);
    }
    printf("\n\n\n\n");
    system("pause");
}