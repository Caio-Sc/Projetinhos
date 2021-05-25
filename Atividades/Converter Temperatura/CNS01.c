//CNS03 - Exp1 - Exercicio 3 (convertesor de temperatura)
//Caio Sclavi 11/03/21
//
#include <stdio.h>
#include <stdlib.h>
int main()
{
       float f, c;
       printf("====================================================\n"
              "Coloque o valor em Fahrenheit para ser convertido:");
       scanf("%f", &f);
       c = (f - 32) / 1.8; //Faz a conversão de graus Fahrenheit para graus Celsius
       printf("%f Celsius\n"
              "====================================================\n",
              c);
       system("pause");
}