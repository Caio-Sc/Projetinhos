//CNS03 - Exp1 - Exercicio 4 (impressora)
//Caio Sclavi 11/03/21
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qpag, qh, qm, qs, totmin; //qpag (paginas totais), qh(horas), qm(minutos), totmin(segundos totais)
    printf("==============================================================\n");
    printf("Quantidade de paginas que pretende imprimir:");
    scanf("%d", &qpag);
    totmin = qpag / 5;
    qm = totmin;
    totmin = totmin * 60; //Calcula total de segundos
    qh = (totmin / 60) / 60; //Calcula as horas
    qm = qm - (qh * 60);
    qs = (((qpag * 12) - (qm * 60)) - ((qh * 60) * 60)); //Calcula segundos
    printf("faltam %d horas %d minutos e %d segundos para o fim da impressao\n", qh, qm, qs);
    printf("==============================================================\n");
    system("pause");
}