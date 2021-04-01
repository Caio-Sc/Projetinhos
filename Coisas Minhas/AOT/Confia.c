#include <stdio.h>
#include <locale.h>

void main()
{
    char Y;
    setlocale(LC_ALL, "Portuguese");
    int qep, qmin, qmint, qht, qmeses, qanime, qdia;
    float tempo;
    while (1)
    {
        printf("Coloque quantos episodios voce pode assistir por dia: ");
        scanf("%d", &qep);
        printf("Coloque a quantidade de episodios que a serie tem: ");
        scanf("%d", &qanime);
        printf("Coloque quanto tempo tem cada episodio (minutos): ");
        scanf("%d", &qmin);
        tempo = qmin;
        tempo = ((24 * 60) / tempo);
        if (qep > tempo)
        {
            printf("\nNão é possivel assitir mais que %.0f episodios por dia\n", trunc(tempo));
            system("pause");
            system("cls");
            continue;
        }
        else
        {
            if (qanime < qep)
            {
                printf("\nA serie pode ser assistida em 1 dia\n");
                system("\npause");
            }
            else
            {
                qmint = ((qanime % qep) * qmin) % 60;
                qht = (((qanime % qep) * qmin) / 60) % 24;
                qdia = (qanime / qep) % 30;
                qmeses = (qanime / qep) / 30;
                printf("=====================================================\n");
                printf("Vai demorar %d meses %d dias %d horas e %d minutos\n", qmeses, qdia, qht, qmint);
                printf("=====================================================\n\n");
            }
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
                    return;
                }
            }
            else
            {
                printf("Opção invalida, tente novamente\n");
                system("pause");
                continue;
            }
        }
    }
}