//Codigo feito por Caio Sclavi

#include <stdio.h>

void main()
{
    while (1)
    {
        float P1, P2, A1, A2, Media;
        printf("=====================================\n");
        printf("Calculador de Media para Calculo\n"
               "Feito por Caio Sclavi\n");
        printf("=====================================\n");
        printf("Coloque sua nota na prova 1: ");
        scanf("%f", &P1);
        printf("Coloque sua nota na prova 2: ");
        scanf("%f", &P2);
        printf("Coloque sua nota na Atividade 1: ");
        scanf("%f", &A1);
        printf("Coloque sua nota na Atividade 2: ");
        scanf("%f", &A2);
        Media = ((((2 * P1 + A1) / 3) + ((2 * P2 + A2)) / 3) / 2) * (0.8 + (0.04 * 5));
        printf("=====================================\n");
        printf("Sua media foi: %.1f", Media);
        if (Media >= 5)
            printf("  Voce Passou!! C:\n");
        else
            printf(" Voce Reprovou... :C\n");
        printf("=====================================\n");
        system("pause\n");
        printf("=====================================\n\n\n");
    }
}