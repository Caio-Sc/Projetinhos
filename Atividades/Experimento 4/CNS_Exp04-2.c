//CNS_Exp04-1.c - Checar validade de CPF
//Caio de Nasi Sclavi 28/04/2021
/*Este programa obtem um cpf inserido pelo usuario, identificando e informando ao usuario se o cpf é valido ou não*/

#include <stdio.h>

int main()
{
    char cpf[13]; //Valor do CPF com  hífen
    int d[11];    //Valor do cpf sem hífen
    int soma[3];  //Variavel usada para armazenar soma do numero de controle
    int k;        //Utilizado para transferir valor da variavel "cpf" para a variavel "d"
    printf("digite o cpf na forma XXXXXXXXX-XX: ");
    scanf("%s", cpf);
    cpf[9] = '-';
    for (k = 0; k < 11; k++) //transferir valor da variavel "cpf" para a variavel "d"
    {
        if (k < 9)
            d[k] = cpf[k] - 48;
        else
            d[k] = cpf[k + 1] - 48;
    }
    soma[0] = 10 * d[0] + 9 * d[1] + 8 * d[2] + 7 * d[3] + 6 * d[4] + 5 * d[5] + 4 * d[6] + 3 * d[7] + 2 * d[8]; //Obtem a soma 1 do numero de controle
    if(soma[0] % 11 < 2)                                                                                         //Checa para validar o penultimo numero;
    d[9] = 0;                                                                                                    //Define o penultimo numero para o teste
    else                                                                                                        
    d[9] = 11 - (soma[0] % 11);                                                                                  //Define o penultimo numero para o teste
    soma[1] = 11*d[0]+ 10*d[1]+ 9*d[2] + 8*d[3]+ 7*d[4]+ 6*d[5]+ 5*d[6]+ 4*d[7]+ 3*d[8];                         //Obtem a soma 2 do numero de controle
    soma[2] = soma[1] + 2*d[9];                                                                                  //Obtem a soma 3 do numero de controle
    if(soma[2] % 11 < 2)                                                                                         //Checa para validar o ultimo numero
    d[10] = 0;                                                                                                   //Define o ultimo numero para o teste
    else                                                                                                         
    d[10] = 11 - (soma[2] % 11);                                                                                 //Define o ultimo numero para o teste
    if(d[9] + 48 == cpf[10] && d[10] + 48 == cpf[11]) //Checa se o numero de controle é igual o inserido para verificação
    {
        printf("============\n");
        printf("CPF Valido!\n");
        printf("============\n");
    }
    else
    {
    cpf[10] = d[9] + 48;    //Define o penultimo numero para printar o valor do cpf valido
    cpf[11] = d[10] + 48;   //Define o ultimo numero para printar o valor do cpf valido
    printf("=================================================\n");
    printf("CPF Invalido\n");
    printf("Para ser valido o CPF precisaria ser %s\n", cpf);
    printf("=================================================\n");
    }
    //system("pause");
}