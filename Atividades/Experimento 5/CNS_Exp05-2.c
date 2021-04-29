//CNS_Exp05-2.c - inverter primeira e ultima letra de uma string
//Caio de Nasi Sclavi 28/04/2021
/*inverter primeira e ultima letra de uma string*/


#include <stdio.h>
#include <string.h>

int main()
{
    char string[102], temp;
    char st;
    printf("Escreva um texto: ");
    fgets(string, 102, stdin);
    string[strlen(string) - 1] = '\0';
    st = strlen(string) - 1;
    temp = string[0];
    string[0] = string[st];
    string[st] = temp; 
    printf("Texto invertido: %s", string);
}
