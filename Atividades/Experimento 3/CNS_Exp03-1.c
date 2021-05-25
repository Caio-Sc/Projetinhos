//CNS_Exp03-1.c - Checar Par ou Impar
//Caio de Nasi Sclavi 25/03/2021
/*Este programa pega o n�mero indicado pelo usu�rio e checa se o n�mero � par ou �mpar.
 Caso seja par o programa ira ver se a metade do n�mero indicado � par ou �mpar e informar o usu�rio*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num; 
    char Y; // Usado para parar ou recome�ar o loop
    while (1)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);
        if (num % 2 == 0) // Checa se o n�mero indicado � par ou impar atrav�s do resto
        {
            printf("======================================\n");
            printf("O Numero digitado e par!\n");
            if ((num / 2) % 2 == 0)// Checa se a metade do n�mero indicado � par ou �mpar atrav�s do resto
            {
                printf("A metade de %d (%d) e um numero par\n", num, (num / 2));
                printf("======================================\n");
            }
            else
            {
                printf("A metade de %d (%d) e um numero impar\n", num, (num / 2));
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
                printf("\nOpcao invalida, tente novamente\n");
                continue;
            }
        }
    }
}