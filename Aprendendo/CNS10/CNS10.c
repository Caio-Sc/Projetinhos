//CNS09 - Faixa de Peso normal com reciclagem
//Caio Sclavi 25/03/2021
#include <stdio.h> nain()

int main() 
{
    float altura, pesominimo, pesomaximo;
    altura = 1;
    while (altura != 0)
    {
        printf("Coloque sua altura em metros (0 para sair): ");
        scanf("%f", &altura);
        pesominimo = (altura * altura * 18.5);
        pesomaximo = (altura * altura * 24.999);
        printf("O seu peso deve estar entre %4.f e %4.f Kg\n", pesominimo, pesomaximo);
        system("pause");
    }
}
