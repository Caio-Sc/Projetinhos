// CNS07 - Cálculos com números flutuantes
// 18/03/2021
#include <stdio.h>

int main()
{
    char Y;
    float x, y;
    while (1)
    {
        printf("Coloque o primeiro numero a ser calculado: ");
        scanf("%f", &x);
        printf("Coloque o segundo numero a ser calculado: ");
        scanf("%f", &y);
        printf("====================\n");
        printf("%.2f + %.2f = %.2f\n", x, y, (x + y));
        printf("%.2f - %.2f = %.2f\n", x, y, (x - y));
        printf("%.2f/%.2f = %.2f\n", x, y, (x / y));
        printf("====================\n");
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