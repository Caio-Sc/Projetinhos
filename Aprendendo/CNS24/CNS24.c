//CNS24 - String invertida
//Caio Sclavi - 22/04
/*Inverte a string inserida*/
#include <stdio.h>
#include <string.h>
int main()
{
    char string[200];
    char string2[200];
    fgets(string, 200, stdin);
    char i = strlen(string) - 2; 
    for(char t = 0; i >= 0; i--, t++)
    {
        string2[t] = string[i];
    }
    string2[strlen(string) - 1] = '\0';
    printf("%s", string2);
}
