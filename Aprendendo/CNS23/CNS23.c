//CNS23 - Numeros Primos
//Caio Sclavi - 15/04
/*Apresentar os N primeiros numeros primos
Entrar com a quantidade N.
Numero primo: é o numero que é somente divisivel por ele mesmo ou por 1*/
#include <stdio.h>
int main()
{
    int N, cont, num, i;
    int OK; //0 = falso e 1 = verdadeiro
    printf("Digite a quantidade de numeros primos: ");
    scanf("%d", &N);
    num = 1;
    OK = 1;
    for (cont = 0; cont < N; cont++)
    {
        OK = 1;
        if (cont % 2 == 0 && cont != 2)
        {
            OK = 0;
        }
        else
        {
            for (i = 2; i < cont; i++)
            {
                if (cont % i == 0)
                {
                    OK = 0;
                    break;
                }
            }
        }
        if (OK == 1)
            printf("|%d - %d|\n", num++, cont);
    }
    system("pause");
}