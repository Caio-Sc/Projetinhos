//CNS_Exp05-5.c - Gerar Histograma
//Caio de Nasi Sclavi 02/05/2021
/*Este programa tem como objetivo gerar um histograma apartir de numeros de 0 a 100 inseridos pelo usuario para uma quantidade variavel de colunas
também inserida pelo usuario e com maximo 10*/

#include <stdio.h>
int main()
{
    char barra[10], qColunas, lV, max = 0; //Variavel qColunas utilizada para quantidade de colunas, lV usada para loop dos valores e max pra valor mais alto
    float val[10];                         //Guarda cada valor de cada coluna inseridos pelo usuario
    do
    {
        printf("Escolha a quantidade de colunas (maximo 10): ");
        scanf("%s", &qColunas); //Pega a quantidade maxima de colunas
    } while ((qColunas > 10 || qColunas < 1));
    for (lV = 0; lV < qColunas; lV++) //loop para pegar valores de cada coluna
    {
        printf("Valor da Coluna %d: ", lV + 1);
        scanf("%f", &val[lV]);
        if (val[lV] > 100 || val[lV] < 0) //impede valores menores que zero e maiores que 100
        {
            printf("Escolha valores entre 0 e 100\n");
            lV--;
            continue;
        }
        if (val[lV] > max) //Usado para descobrir o valor maximo
            max = val[lV];
    }
    printf("\n\nHISTOGRAMA\n------");
    for (lV = 0; lV < qColunas; lV++) //loop para printar os valores numericos do histograma
    {
        printf("\n");
        printf("%.2f\t", val[lV]);
        barra[lV] = val[lV] * 20 / max;        //identifica a quantidade de X que tem para cada valor
        for (int lX = 0; lX < barra[lV]; lX++) //loop para printar a letra X para cada valor do histograma
            printf("X");
    }
}
