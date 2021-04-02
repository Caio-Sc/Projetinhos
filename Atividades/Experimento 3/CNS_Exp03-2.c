//CNS_Exp03-2 - Quantidade de dias desde o início do ano
//Caio de Nasi Sclavi 25/03
//O programa tem como objetivo calcular e indicar ao usuario quantos dias se passaram desde o inicio do ano, levando em conta se ele é bissexto.

#include <stdio.h>

int main()
{
    int ano, dmes, dia, mestotal, aux; //Variavel "dmes" utilizada para setar a soma dos dias de todos os meses. // Variavel "aux" utilizada para indicar quantos dias cada mes tem
    char Y; //usada para recomeçar o loop
    while (1)
    {
        printf("Coloque o ano em que voce esta: ");
        scanf("%d", &ano);
        if (ano <= 0)
        {
            printf("==================================================\n");
            printf("Coloque um valor de ano positivo e maior que zero\n");
            printf("==================================================\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("Coloque o mes que voce esta: ");
        scanf("%d", &mestotal);
        if (mestotal <= 0 || mestotal > 12)
        {
            printf("===============================================\n");
            printf("Coloque um valor maior que zero e menor que 12\n");
            printf("===============================================\n");
            system("pause");
            system("cls");
            continue;
        }
        dmes = (mestotal - 1) * 31;//converte os meses em dias
        switch (mestotal)//Switch utilizado para indicar quantos dias tem cada mes. Também utilizado para diminuir os dias totais de acordo com os meses com menos que 31 dias
        {
        case 1:
            aux = 31;
            break;
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)// checa para ver se o ano é bissexto
                aux = 29;
            else
                aux = 28;
            break;
        case 3:
            aux = 31;
            dmes = dmes - 3;
            break;
        case 4:
            aux = 30;
            dmes = dmes - 3;
            break;
        case 5:
            aux = 31;
            dmes = dmes - 4;
            break;
        case 6:
            aux = 30;
            dmes = dmes - 4;
            break;
        case 7:
            aux = 31;
            dmes = dmes - 5;
            break;
        case 8:
            aux = 31;
            dmes = dmes - 5;
            break;
        case 9:
            aux = 30;
            dmes = dmes - 5;
            break;
        case 10:
            aux = 31;
            dmes = dmes - 6;
            break;
        case 11:
            aux = 30;
            dmes = dmes - 6;
        case 12:
            aux = 31;
            dmes = dmes - 7;
            break;
        }
        printf("Coloque o dia que voce esta (maximo = %d): ", aux);
        scanf("%d", &dia);
        if (dia <= 0 || dia > aux) //Bloqueia caso o usuario tenha colocado mais dias que o mês tem
        {
            printf("===============================================\n");
            printf("Coloque um valor maior que zero e menor que %d\n", aux); 
            printf("===============================================\n");
            system("pause");
            system("cls");
            continue;
        }
        dia = dmes + dia;
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) //Checa para ver se o ano é bissexto.
        {
            if (mestotal > 2) //Checa se o mês colocado pelo usuario é pós fevereiro, para assim adicionar o dia extra do ano bissexto 
                dia++;
            printf("===============================================\n");
            printf("O ano e bissexto");
            printf("\nVoce esta no dia %d do ano\n", dia);
            printf("===============================================\n");
        }
        else
        {
            printf("===============================================\n");
            printf("O ano nao e bissexto");
            printf("\nVoce esta no dia %d do ano\n", dia);
            printf("===============================================\n");
        }
        while (1) // loop para perguntar se quer calcular novamente
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