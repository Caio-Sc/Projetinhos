//Codigo feito por Caio Sclavi

#include <stdio.h>

void main()
{
    float P1, P2, A1, A2, Media, first;
    char Continuar;
    while (1)
    {
        printf("=====================================\n");
        printf("Calculador de Media para Calculo\n");
        printf("=====================================\n");
        printf("Coloque sua nota na prova 1: ");
        scanf("%f", &P1);
        if(P1 > 10){
            printf("\n=============================================\n");
            printf("Esse numero e maior que 10, tente novamente\n");
            printf("=============================================\n\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("Coloque sua nota na prova 2: ");
        scanf("%f", &P2);
        if(P2 > 10){
            printf("\n=============================================\n");
            printf("Esse numero e maior que 10, tente novamente\n");
            printf("=============================================\n\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("Coloque sua nota na Atividade 1: ");
        scanf("%f", &A1);
         if(A1 > 10){
            printf("\n=============================================\n");
            printf("Esse numero e maior que 10, tente novamente\n");
            printf("=============================================\n\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("Coloque sua nota na Atividade 2: ");
        scanf("%f", &A2);
         if(A2 > 10){
            printf("\n=============================================\n");
            printf("Esse numero e maior que 10, tente novamente\n");
            printf("=============================================\n\n");
            system("pause");
            system("cls");
            continue;
        }
        Media = ((((2 * P1 + A1) / 3) + ((2 * P2 + A2)) / 3) / 2) * (0.8 + (0.04 * 5));
        printf("\n=====================================\n");
        printf("Sua media foi: %.1f", Media);
        if (Media >= 5)
            printf("  Voce Passou!! C:\n");
        else
            printf(" Voce Reprovou... :C\n");
        printf("=====================================\n");
        while (1){
            printf("\nQuer Calcular novamente? S/N ");
            scanf(" %c", &Continuar);
            if (Continuar == 's' || Continuar == 'S')
            {
                system("cls");
                break;
            }
            else if (Continuar == 'n' || Continuar == 'N')
            {
                return 0;
            }
            else
            {
                printf("Essa opcao e invalida\n");
            }
        }
    }
}