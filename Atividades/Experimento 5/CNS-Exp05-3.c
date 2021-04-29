//CNS_Exp05-3.c - Nome e sobrenome
//Caio de Nasi Sclavi 28/04/2021
/*Juntar duas strings*/

#include <stdio.h>
#include <string.h>

int main()
{
    char nome[50], snome[50], ns[101];
    char i, t;
    printf("Coloque seu primeiro nome: ");
    fgets(nome, 50, stdin);
    printf("Coloque seu sobre nome: ");
    fgets(snome, 50, stdin);
    for (i = 0; i < strlen(nome) - 1; i++)
        ns[i] = nome[i];
    ns[i] = '\0';
    t = strlen(ns) + 1;
    ns[i] = ' ';
    for (i = 0; i < strlen(snome) - 1; i++)
        ns[t++] = snome[i];
    ns[t++] = '\0';
    printf("Nome inteiro: %s", ns);
}
