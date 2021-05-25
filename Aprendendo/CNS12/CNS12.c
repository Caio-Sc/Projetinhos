//CNS12 - Calculadora aritmética
//Caio Sclavi 25/03/2021
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1, n2;
    int escolha;
    char Y;
    while (1)
    {
        printf("Escolha o primeiro valor para realizar a conta: ");
        scanf("%f", &n1);
        printf("Escolha o segundo valor para realizar a conta: ");
        scanf("%f", &n2);
        printf("\nSoma (1)\n"
               "Subtracao (2)\n"
               "Multiplicacao (3)\n"
               "Divisao (4)\n"
               "Escolha uma opcao: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("\n===================================\n");
            printf("%.2f + %.2f = %.2f\n", n1, n2, (n1 + n2));
            break;

        case 2:
            printf("\n===================================\n");
            printf("%.2f - %.2f = %.2f\n", n1, n2, (n1 - n2));
            break;

        case 3:
            printf("\n===================================\n");
            printf("%.2f x %.2f = %.2f\n", n1, n2, (n1 * n2));
            break;

        case 4:
            printf("\n===================================\n");
            if (n2 != 0)
                printf("%.2f / %.2f = %.2f\n", n1, n2, (n1 / n2));
            else
                printf("Nao existe divisao por zero\n");
            break;

        default:
            printf("\n===================================\n");
            printf("Opcao invalida, tente novamente.\n");
            break;
        }
        printf("===================================\n");
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
                printf("Opção invalida, tente novamente\n");
                system("pause");
                continue;
            }
        }
    }
}