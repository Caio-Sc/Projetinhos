//CNS28 - Substituir caracter por uma string
//Caio Sclavi - 06/05
/*Entrar com uma string de até 100 caracteres entrar uma string de 10 caracteres
 e substituir o caracter pela segunda string string*/
#include <stdio.h>
int main()
{
    char texto[100], c1, c2[10], texto2[200], k, j = 0;
    printf("Digite a primeira string: ");
    fgets(texto, 100, stdin);
    printf("Digite a string a ser substituida: ");
    fgets(c2, 10, stdin);
    printf("Digite o caracter a ser substituido: ");
    scanf(" %c", &c1);
    for (char i = 0; texto[i] != '\n'; i++)
    {
        if(texto[i] == c1)
        {
            for(k = 0; c2[k] != '\n'; k++)
            {
                texto2[j] = c2[k];
                j++;
            }
        }
        else
        {
            texto2[j] = texto[i];
            j++;
        }
    }
    texto2[j] = '\n';
    texto2[j + 1] = '\0';
    puts(texto2);


}