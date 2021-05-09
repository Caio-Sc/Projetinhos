//CNS29 - Pesquisar string
//Caio Sclavi - 06/05
/*Entrar com uma string de até 100 caracteres entrar uma string para pesquisar
 e buscar na primeira string a string para pesquisar*/
#include <stdio.h>
int main()
{
    char texto[100], p[100], j, k, cont;
    printf("Digite a primeira string: ");
    fgets(texto, 100, stdin);
    printf("Digite a segunda string: ");
    fgets(p, 100, stdin);
    for(char i = 0; texto[i] != '\n'; i++)
    {
        j = 0;
        if(texto[i] = p[j])
        {
            k = i;
            while (texto[k] == p[j] && p[j] != '\n')
            {
                k++;
                j++;
            }
            if(p[j] == '\n')
                cont++;
        }
    }
    printf("\nEncontrou %d vezes a palavra %s", cont, p);
}