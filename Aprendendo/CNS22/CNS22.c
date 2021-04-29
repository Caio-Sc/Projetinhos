//CNS22 - Tamanho string
//Caio Sclavi - 15/04
//Entrar com uma string e dizer qual seu tamanho
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char Text[100]; //Tipo agregado homogeneo (Só contem tipo caracter)
                   //indexados de 0 a 99
                  //se considerarmos uma string, o ultimo caracter será '\0' (null)
    int i;
    printf("Digite um texto quaquer: ");
    gets(Text);
    printf("%s\n", Text);
    for(i = 0; Text[i]  != '\0'; i++){}
    printf("%d Caracteres\n", i);
    system("pause");
}
