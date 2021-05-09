//CNS31 - Votos
//Caio Sclavi - 06/05
/*Entrar com valores de votos em uma matriz bidimensional e contar os votos*/
#include <stdio.h>
int main()
{
    int votos[50][10], p, e, i, j, cont;
    printf("Quantidade de candidatos: ");
    scanf("%d", &p);
    printf("Quantidade de eleitores: ");
    scanf("%d", &e);
    for (i = 0; i < e; i++)
    {
        printf("Eleitor %d: ", i + 1);
        for (j = 0; j < p; j++)
        {
            scanf("%d", &votos[i][j]);
        }
    }
    for(j = 0; j < p; j++)
    {
        cont = 0;
        for(i = 0; i < e; i++)
        {
            if(votos[i][j] == 1)
            cont++;
        }
        printf("Candidato %d: %d\n", j+1, cont);
    }
}