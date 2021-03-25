// CNS06 - Calculos com numeros inteiros
// 18/03/2021
#include <stdio.h>

int main()
{
    char Y;
    int x, y;
    while (1)
    {
        printf("Coloque o primeiro numero a ser calculado: ");
        scanf("%d", &x);
        printf("Coloque o segundo numero a ser calculado: ");
        scanf("%d", &y);
        printf("=============\n");
        printf("%d + %d = %d\n", x, y, (x + y));
        printf("%d - %d = %d\n", x, y, (x - y));
        printf("%d/%d = %d // E restam %d\n", x, y, (x / y), (x % y));
        printf("=============\n");
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
}