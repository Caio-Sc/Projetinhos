//CNS_Exp04-1.c - Peso dos Bois
//Caio de Nasi Sclavi 28/04/2021
/*Este programa obtem o pessos de até 100 bois inseridos pelo usuario e informa o usuario qual boi é o mais pesado e qual o mais leve*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    char MaxBoi;        //Quantidade de boi maxima.
    float BoiPeso[101]; //A quantidade total de bois.
    float BoiLeve;      //Peso mais leve.
    float BoiPesado;    //Peso mais pesado.
    char i = 1, i2 = 1; //Usada para loops
    char ip = 0;        //Posição do mais pesado
    char il = 0;        //Posição do mais leve
    while (1)
    {
        printf("Digite o peso dos bois (Digite 0 para continuar): \n");
        printf("Boi 1: ");
        scanf("%f", &BoiPeso[0]);
        if (BoiPeso[0] <= 0) //Impede que coloquem um valor negativo ou zero no primeiro teste
        {
            printf("Coloque um numero maior que zero na primeira opcao\n");
            system("pause");
            system("cls");
            continue;
        }
        BoiLeve = BoiPeso[0];    //Define o primeiro boi como boi mais leve
        BoiPesado = BoiPeso[0];  //Define o primeiro boi como boi mais pesado
        i2++;
        break;
    }
    while (BoiPeso[i - 1] > 0)   //Loop para pegar peso de cada boi
    {
        printf("Boi %d: ", i2++);
        scanf("%f", &BoiPeso[i]);
        if (BoiPeso[i] > BoiPesado && BoiPeso[i] > 0) //Identifica se o ultimo boi escaneado tem peso maior que o atual mais pesado
        {
            BoiPesado = BoiPeso[i];                   //Define o boi mais pesado
            ip = i;                                   //Salva a posição do boi para printar
        }
        else if (BoiLeve > BoiPeso[i] && BoiPeso[i] > 0) //Identifica se o ultimo boi escaneado tem peso menor que o atual mais leve
        {
            BoiLeve = BoiPeso[i];                     //Define o boi mais leve
            il = i;                                   //Salva a posição do boi para printar
        }   
        i++;
    }
    MaxBoi = i;
    system("cls");
    printf("====================================\n");
    for (i = 0; i < MaxBoi - 1; i++)                     //Printa Cada boi
        printf("Boi %d - %.2fKg\n", (i + 1), BoiPeso[i]); 
    printf("====================================\n");
    printf("O Boi %d e o mais magro com %.2fKg\n", (il + 1), BoiPeso[il]);
    printf("O Boi %d e o mais gordo com %.2fKg\n", (ip + 1), BoiPeso[ip]);
    printf("====================================\n");
    system("pause");
}
