//CNS24 - Contar caracteres da string
//Caio Sclavi - 22/04
/*Busca um caracter especifico na string inserida*/
#include <stdio.h>
#include <string.h>
int main()
{
    char texto[100], carac, i, count;
    printf("Digite o Texto: ");
    fgets(texto, 100, stdin);
    texto[strlen(texto) - 1] = '\0';
    printf("%s\n", texto);
    printf("\nCaracter a pesquisar (@ Para sair): ");
    scanf(" %c", &carac);
    do
    {
        printf("==========================\n");
        printf("Caracteres: ");
        for(i = 0, count = 0; i < strlen(texto); i++)
        {
            if(texto[i] == carac)
            {
                printf("%d ", i + 1);
                count++;
            }
        }
        printf("\nA letra apareceu %d vezes", count);
        printf("\n==========================");
        printf("\n\nCaracter a pesquisar (@ Para sair): ");
        scanf(" %c", &carac);
    } while (carac != '@');
    
}