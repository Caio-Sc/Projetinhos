//CNS13 - Calcular fahrenheit
//Caio Sclavi 25/03
#include <stdio.h>

int main()
{
    float C, F;
    for(C = 0; C <=400; C++)
    {
        F = (C * 1.8) + 32;
        printf("C:%.2f    F:%.2f\n", C, F);
    }
    system("pause");
}
