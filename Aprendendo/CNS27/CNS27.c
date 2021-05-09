//CNS26 - Substituir caracter numa string
//Caio Sclavi - 06/05
/*Entrar com uma string de até 100 caracteres entrar com 2 caracteres
separados por espaço. Substituir na string o primeiro pelo segundo e falar quantas
operações foram feitas*/
#include <stdio.h>
int main()
{
    char texto[100], c1, c2, count = 0;
    printf("Digite o texto: ");
    fgets(texto, 100, stdin);
    printf("Escolha os caracteres a serem alterados: ");
    scanf(" %c %c", &c1, &c2);
    for(char i = 0; texto[i] != '\n'; i++)
    {
        if (texto[i] == c1){
            texto[i] = c2;
            count++;
        }
    }
    printf("\n%sForam alteradas %d letras", texto, count);
}