//CNS03 - Teste com váriaveis
//Caio Sclavi 11/03/21
//
#include <stdio.h>

int main()
{
    int A, B;
    float Nota1, Nota2, Nota3, Media;
    A = 10;
    B = 30;
    Nota1 = 5.5;
    Nota2 = 7.3;
    Nota3 = 9;
    Media = (Nota1 + Nota2 + Nota3) / 3;
    printf("A media do aluno foi: %.1f\n", Media);
    printf("Somando %d com %d temos o resultado %d\n", A, B, A + B);
    system("pause");
    return 0;
}