//CNS36 - Matriz taboada
//Caio Sclavi - 13/05
#include <stdio.h>

int main()
{
    int M[10][10];
    int D; //Dimens�o matriz
    int i, j, D1, D2;
    printf("Digite a dimens�o da matriz: ");
    scanf("%d", &D);
    if (D < 1 || D > 10)
    {
        printf("Dimens�o invalida");
        return 0;
    }
    printf("Digite os dados da matriz: ");
    for (i = 0; i < D; i++)
        for(j = 0; j < D; j++)
            scanf("%d", &M[i][j]);
    for (i = 0; i < D; i++)
    {
        for(j = 0; j < D; j++)
        {
            printf("%d\t", M[i][j]);
        }
                printf("\n");
    }
}