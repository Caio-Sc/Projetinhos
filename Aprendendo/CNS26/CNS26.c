//CNS26 - Matrizes
//Caio Sclavi - 29/04
/*insere valores na matriz*/
#include <stdio.h>
int main()
{
    int matriz[3][4];
    char j, i;
    for (j = 0; j < 3; j++)
        for (i = 0; i < 4; i++)
        {
            printf("Coloque o valor da matriz (%d, %d): ", j + 1, i + 1);
            scanf("%d", &matriz[j][i]);
        }
    printf("\n");
    for (j = 0; j < 3; j++)
        for (i = 0; i < 4; i++)
        {
            printf("Matriz[%d][%d]: [%d][%d]\n", j + 1, i + 1, j + 1, matriz[j][i]);
        }
    printf("\n");
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 4; i++)
        {
            printf("%d\t", matriz[j][i]);
        }
        printf("\n");
    }
}