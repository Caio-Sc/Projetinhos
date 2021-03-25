// CNS_Exp01 - 4 - Calculo de IMC
// Caio De Nasi Sclavi 18/03/2021
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); 
    float peso, altura, IMC, pfalta;
    printf("Escreva sua altura em metros ou centímetros (usar , para metros): ");
    scanf("%f", &altura);
    printf("Escreva seu peso em Kg: ");
    scanf("%f", &peso);
    if (altura > 5)
    {
        altura = altura / 100;
    }
    IMC = (peso / (altura * altura));
    printf("==================================================================================\n");
    printf("Seu IMC é: %.5f\n", IMC);
    pfalta = IMC - 24.9;
    pfalta = pfalta * (altura * altura);
    if (IMC < 18.5)
    {
        pfalta = 18.5 - IMC;
        pfalta = pfalta * (altura * altura);
        printf("Você esta abaixo do peso\n");
        printf("==================================================================================\n");
        printf("Faltam aproximadamente %.5f Kg para você ficar com um peso normal\n", pfalta);
    }
    else if (IMC <= 24.9)
    {
        printf("Você esta com o peso normal\n");
        printf("==================================================================================\n");
    }
    else if (IMC <= 29.9)
    {
        printf("Você esta com sobrepeso\n");
        printf("==================================================================================\n");
        printf("Você precisa emagrecer aproximadamente %.5f Kg para você ficar com um peso normal\n", pfalta);
    }
    else if (IMC <= 34.9)
    {
        printf("Você esta com Obesidade (Grau I)\n");
        printf("==================================================================================\n");
        printf("Você precisa emagrecer aproximadamente %.5f Kg para você ficar com um peso normal\n", pfalta);
    }
    else if (IMC <= 39.9)
    {
        printf("Você esta com Obesidade (Grau II)\n");
        printf("==================================================================================\n");
        printf("Você precisa emagrecer aproximadamente %.5f Kg para você ficar com um peso normal\n", pfalta);
    }
    else if (IMC >= 40)
    {
        printf("Você esta com Obesidade (Grau III)\n");
        printf("==================================================================================\n");
        printf("Você precisa emagrecer aproximadamente %.5f Kg para você ficar com um peso normal\n", pfalta);
    }
    if (IMC > 24.9 || IMC < 18.5)
    {
        printf("==================================================================================\n");
    }

    printf("\n====================================\n");
    printf("0 - 18,5 = Abaixo do peso\n"
           "18,5 - 24,9 = Peso normal\n"
           "25 - 29,9 = Sobrepeso\n"
           "30 - 34,9 = Obesidade (Grau I)\n"
           "35 - 39,9 = Obesidade (Grau II)\n"
           "Maior que 40 = Obesidade (Grau III)\n");
    printf("====================================\n");
    system("pause");
}