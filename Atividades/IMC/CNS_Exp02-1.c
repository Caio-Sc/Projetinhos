// CNS_Exp02 - 1 // Calculo de IMC
// Caio De Nasi Sclavi 18/03/2021
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso, altura, IMC;
    printf("Escreva sua altura em metros ou centimetros (usar . para metros): ");
    scanf("%f", &altura);
    printf("Escreva seu peso em Kg: ");
    scanf("%f", &peso);
    if (altura > 5)
    {
        altura = altura / 100;
    }
    IMC = (peso / (altura * altura));
    printf("================================\n"
           "Seu IMC e: %.2f\n", IMC);
    if (IMC < 18.5)
    {
        printf("Voce esta abaixo do peso\n");
    }
    else if (IMC <= 24.9)
    {
        printf("Voce esta com o peso normal\n");
    }
    else if (IMC <= 29.9)
    {
        printf("Voce esta com sobrepeso\n");
    }
    else if (IMC <= 34.9)
    {
        printf("Voce esta com Obesidade (Grau I)\n");
    }
    else if (IMC <= 39.9)
    {
        printf("Voce esta com Obesidade (Grau II)\n");
    }
    else if (IMC >= 40)
    {
        printf("Voce esta com Obesidade (Grau III)\n");
    }
    printf("================================\n");
    /*printf("\n====================================\n");
    printf("0 - 18,5 = Abaixo do peso\n"
           "18,5 - 24,9 = Peso normal\n"
           "25 - 29,9 = Sobrepeso\n"
           "30 - 34,9 = Obesidade (Grau I)\n"
           "35 - 39,9 = Obesidade (Grau II)\n"
           "Maior que 40 = Obesidade (Grau III)\n");
    printf("====================================\n");*/
    system("pause");
}