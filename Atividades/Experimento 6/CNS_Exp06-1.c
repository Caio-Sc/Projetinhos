//CNS_Exp06-1.c - Sistema de Hotel
//Caio de Nasi Sclavi 09/05/2021
/*Este programa funciona como um sistema de hotel, podendo fazer check-in, check-out, apresentar os quartos vazios e a taxa de ocupação total do hotel*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tHotel[20][14];                    //Usado para fazer check-in e check-out de cada quarto do hotel
    int escolhaandar, escolhaquarto, opcao; //Usadas para escolhas dos quartos, andares e da opção do menu
    float taxa = 0;                         //Usado para contar quantos quartos estão ocupados

    for (char i = 0; i < 20; i++)
        for (char t = 0; t < 14; t++) //loop usado para definir todos os valores de cada quarto como 0 (desocupado)
            tHotel[i][t] = 0;         //Define cada apartamento como desocupado
    while (1)
    {
        system("cls");
        printf("-----------------------------------------------\n"); //Menu para escolher o modulo do programa
        printf("(1) - Fazer check-in\n");
        printf("(2) - Fazer check-out\n");
        printf("(3) - Mostrar todos os apartamentos livres do hotel\n");
        printf("(4) - Mostrar a taxa de ocupacao do hotel\n");
        printf("(5) - Sair do Programa\n");
        printf("-----------------------------------------------\n");
        printf("Escolha uma opcao para continuar: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1: //Opção de check-in
            printf("Escolha o andar em que gostaria de fazer check-in: ");
            scanf("%d", &escolhaandar);
            if (escolhaandar <= 0 || escolhaandar > 20) //Impede que o usuario escolha valores de andares não existentes
            {
                printf("------------------------------\n");
                printf("Escolha um valor entre 1 e 20!\n");
                printf("------------------------------\n");
                system("pause");
                continue;
            }
            while (1)
            {
                taxa = 0;
                printf("Os quartos disponiveis para o andar %d sao: ", escolhaandar);
                for (char i = 0; i < 14; i++)             //Rotaciona por quarto do andar escolhido para verificar os quartos validos
                    if (tHotel[escolhaandar - 1][i] != 1) //Checa se o quarto é valido
                        printf("%d ", i + 1);             //Informa o usuario os quartos validos do andar
                    else
                        taxa++; //Conta quantos quartos estão ocupados
                if (taxa == 14) //Informa caso todos os quartos estejam ocupados
                {
                    printf("------------------------------------------------------------\n");
                    printf("\nTodos os quartos deste andar estao ocupados, escolha outro\n");
                    printf("------------------------------------------------------------\n");
                    system("pause");
                    break;
                }
                printf("\nEscolha um dos quartos: ");
                scanf(" %d", &escolhaquarto);
                if (escolhaquarto <= 0 || escolhaquarto > 14) //Impede que o usuario escolha valores de quartos não existentes
                {
                    printf("------------------------------\n");
                    printf("Escolha um valor entre 1 e 14!\n");
                    printf("------------------------------\n");
                    system("pause");
                    continue;
                }
                if (tHotel[escolhaandar - 1][escolhaquarto - 1] != 1) //Verifica se o quarto escolhido esta livre
                {
                    tHotel[escolhaandar - 1][escolhaquarto - 1] = 1; //Define quarto como ocupado e Informa a confirmação do check-in
                    printf("-------------------\n");
                    printf("Check-in Concluido!\n");
                    printf("-------------------\n");
                    system("pause");
                    break;
                }
                else //Informa se o quarto estiver ocupado
                {
                    printf("-------------------------------------------------\n");
                    printf("Este quarto esta ocupado, por favor escolha outro\n");
                    printf("-------------------------------------------------\n\n");
                    continue;
                }
            }
            continue;

        case 2: //Opção de check-out
            taxa = 0;
            printf("Escolha o andar em que gostaria de fazer check-out: ");
            scanf("%d", &escolhaandar);
            if (escolhaandar <= 0 || escolhaandar > 20) //Impede que o usuario escolha valores de andares não existentes
            {
                printf("------------------------------\n");
                printf("Escolha um valor entre 1 e 20!\n");
                printf("------------------------------\n");
                system("pause");
                continue;
            }
            while (1)
            {
                printf("Os quartos alugados do andar %d sao: ", escolhaandar);
                for (char i = 0; i < 14; i++)             //Rotaciona por quarto do andar escolhido para verificar os quartos validos
                    if (tHotel[escolhaandar - 1][i] == 1) //Checa se o quarto é valido
                        printf("%d ", i + 1);             //Informa o usuario os quartos validos para o check-out
                    else
                        taxa++; //Salva os quartos não ocupados
                if (taxa == 14) //Informa o usuario caso o andar esteja todo vazio
                {
                    printf("\n----------------------------------------------------------");
                    printf("\nNinguem possui nenhum quarto neste andar, escolha outro!\n");
                    printf("----------------------------------------------------------\n");
                    system("pause");
                    break;
                }
                printf("\nEscolha um dos quartos para fazer check-out: ");
                scanf(" %d", &escolhaquarto);
                if (escolhaquarto <= 0 || escolhaquarto > 14) //Impede que o usuario escolha valores de quartos não existentes
                {
                    printf("--------------------------------\n");
                    printf("Escolha um valor entre 1 e 14!\n");
                    printf("--------------------------------\n");
                    system("pause");
                    continue;
                }
                if (tHotel[escolhaandar - 1][escolhaquarto - 1] == 1) //Verifica se o quarto escolhido esta ocupado
                {
                    tHotel[escolhaandar - 1][escolhaquarto - 1] = 0; //Define quarto como desocupado e Informa a confirmação do check-out
                    printf("--------------------\n");
                    printf("Check-out Concluido!\n");
                    printf("--------------------\n");
                    system("pause");
                    break;
                }
                else //Informa caso o quarto não esteja ocupado
                {
                    printf("---------------------------------------------------------\n");
                    printf("Este quarto nao esta ocupado, por favor escolha um ocupado\n");
                    printf("----------------------------------------------------------\n");
                    continue;
                }
            }
            continue;

        case 3: //Opção para ver todos os quartos livres do hotel
            printf("Os quartos vazios do hotel por andar sao:");
            printf("\n--------------------------------------------");
            for (char i = 0; i < 20; i++) //Rotaciona por cada andar do hotel
            {
                printf("\nAndar %d: ", i + 1);
                for (char t = 0; t < 14; t++) //Rotaciona entre cada quarto do andar
                {
                    if (tHotel[i][t] != 1)    //Detecta se o quarto esta ocupado
                        printf("  %d", t + 1); //Informa os quartos ocupados do andar sendo verificado
                }
            }
            printf("\n--------------------------------------------\n");
            system("pause");
            continue;

        case 4: //Opção que calcula taxa de ocupação do hotel
            taxa = 0;
            for (char i = 0; i < 20; i++)
            {
                for (char t = 0; t < 14; t++) //Loop pesquisa todos os quartos ocupados
                {
                    if (tHotel[i][t] == 1) //Detecta se o quarto esta ocupado
                        taxa++;            //Salva quantidade de quartos ocupados
                }
            }
            printf("---------------------------------\n");
            printf("A taxa de ocupacao sera de %.2f%%\n", ((taxa / 280) * 100)); //Informa o usuario a taxa de ocupação
            printf("---------------------------------\nn");
            system("pause");
            continue;

        case 5: //Opção para sair do programa
            return 0;

        default: //Opção caso a opção escolhida seja invalida
            printf("-----------------------------\n");
            printf("opcao invalida, escolha outra\n");
            printf("-----------------------------\n");
            system("pause");
            continue;
        }
    }
    system("pause");
}