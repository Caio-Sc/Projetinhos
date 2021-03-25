// CNS08 - Dividir heran�a herdeiros
// 18/03/2021
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char Y;
    int pessoas;
    float heranca;
    while (1)
    {
        printf("Quantidade de herdeiros: ");
        scanf("%d", &pessoas);
        printf("Valor da Heran�a: ");
        scanf("%f", &heranca);
        if (pessoas > 0 && heranca > 0)
        {
            printf("======================================================\n");
            printf("O valor a ser dividido ser� de: %.2f para cada herdeiro\n", (heranca / pessoas));
            printf("======================================================\n");
        }
        else
        {
            printf("=============================================================\n");
            printf("Imposs�vel dividir por uma quantia negativa ou igual a zero\n");
            printf("=============================================================\n");
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
                printf("Op��o invalida, tente novamente\n");
                system("pause");
                continue;
            }
        }
    }
}