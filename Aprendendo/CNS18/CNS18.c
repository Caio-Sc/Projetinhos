//CNS18 - Números pares e impares
//Caio Sclavi - 08/04/2021

#include <stdio.h>

int main()
{
    int n;
    do
    {
        printf("Digite um numero inteiro(0 para sair): ");
        scanf("%d", &n);
        if (n % 2 == 0)
            if (n / 2 % 2 == 0)
                printf("%d eh par e sua metade %d tambem eh par\n\n", n, (n / 2));
            else
                printf("%d eh par e sua metade %d eh impar\n\n", n, (n / 2));
        else
            printf("%d eh impar\n\n", n);
    } while (n != 0);
}