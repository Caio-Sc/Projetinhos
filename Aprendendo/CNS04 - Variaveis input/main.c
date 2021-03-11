//CNS03 - Variaveis input
//Caio Sclavi 11/03/21
//
#include <stdio.h>

int main()
{
    float n1, n2, media;
    printf("========================\n"
           "Defina a primeira nota:");
    scanf("%f", &n1);
    printf("Defina a segunda nota:");
    scanf("%f", &n2);
    media = (n1 + n2) / 2;
    printf("Media Final: %.1f\n", media);
    printf("========================\n");
    system("pause");
    return 0;
}