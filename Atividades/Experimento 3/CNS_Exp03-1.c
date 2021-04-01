//CNS_Exp03-1.c - Checar Par ou Impar
//Caio Sclavi 25/03
/*Este programa pega o número indicado pelo usuário e checa se o número é par ou ímpar.
 Caso seja par o programa ira ver se a metade do número indicado é par ou ímpar e informar o usuário*/

#include <stdio.h>

int main()
{
    int num;
    char Y;
    while (1)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);
        if (num % 2 == 0)
        {
            printf("======================================\n");
            printf("O Numero digitado e par!\n");
            if ((num / 2) % 2 == 0)
            {
                printf("A metade de %d (%d) e um numero par\n", num, (num, num / 2));
                printf("======================================\n");
            }
            else
            {
                printf("A metade de %d (%d) e um numero impar\n", num, (num, num / 2));
                printf("======================================\n");
            }
        }
        else
        {
            printf("======================================\n");
            printf("O Numero digitado e impar!\n");
            printf("======================================\n");
        }
        while (1) // Pergunta se quer calcular novamente
        {
            printf("Gostaria de calcular novamente?(S/N) ");
            scanf(" %c", &Y);
            if (Y == 's' || Y == 'n' || Y == 'S' || Y == 'N')
            {
                if (Y == 'S' || Y == 's')
                {
                    system("cls");
                    break;
                }
                else if (Y == 'n' || Y == 'N')
                {
                    return 0;
                }
            }
            else
            {
                printf("Opcao invalida, tente novamente\n");
                system("pause");
                continue;
            }
        }
    }
    return 0;
}