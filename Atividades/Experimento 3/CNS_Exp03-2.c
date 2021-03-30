//CNS_Exp03-2 - Quantidade de dias desde o início do ano
//Caio Sclavi 25/03
//O programa tem como objetivo calcular e indicar ao usuario quantos dias se passaram desde o inicio do ano, levando em conta se ele é bissexto.

#include <stdio.h>

int main()
{
    int ano, mes, dia, aux;
    char Y;
    while (1)
    {
        printf("Coloque o ano em que voce esta: ");
        scanf("%d", &ano);
        if (ano <= 0)
        {
            printf("==================================================\n");
            printf("Coloque um valor de ano positivo e maior que zero\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("Coloque o mes que voce esta: ");
        scanf("%d", &mes);
        if (mes <= 0 || mes > 12)
        {
            printf("===============================================\n");
            printf("Coloque um valor maior que zero e menor que 12\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("Coloque o dia que voce esta: ");
        scanf("%d", &dia);
        if (dia <= 0 || dia > 31)
        {
            printf("===============================================\n");
            printf("Coloque um valor maior que zero e menor que 32\n");
            system("pause");
            system("cls");
            continue;
        }
        aux = mes;
        mes = (mes - 1) * 31; //Converte de mes para dias.
        if (aux == 3 || aux == 4)
            mes = mes - 3;
        else if (aux == 5 || aux == 6)
            mes = mes - 4;
        else if (aux > 6 && aux < 10) //Os ifs tiram dias de acordo com os meses de 30 dias que ja passaram.
            mes = mes - 5;
        else if (aux == 10 || aux == 11)
            mes = mes - 6;
        else if (aux == 12)
            mes = mes - 7;
        dia = mes + dia;
        if (ano % 4 == 0 || ano % 400 == 0 && ano % 100 != 0) //Checa para ver se o ano é bissexto.
        {
            if (aux > 2)
                dia++;
            printf("===============================================\n");
            printf("O ano e bissexto");
            printf("\nSe passaram %d dias desde o comeco do ano\n", dia);
            printf("===============================================\n");
        }
        else
        {
            printf("===============================================\n");
            printf("O ano nao e bissexto");
            printf("\nSe passaram %d dias desde o comeco do ano\n", dia);
            printf("===============================================\n");
        }
        while (1) // Pergunta se quer calcular novamente
        {
            printf("\nGostaria de calcular novamente?(S/N) ");
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