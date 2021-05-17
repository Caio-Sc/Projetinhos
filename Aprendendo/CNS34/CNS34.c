//CNS34 - Tipo agregado heterogeneo
//Caio Sclavi - 13/05
/*Cadastrar numa matriz heterogenea os dados de varias pessoas
sair com cpf = 0
apresentalos na tela
*/
#include <stdio.h>
typedef struct ender
{
    char ender[50];
    char bairro[20];
    char munic[20];
    char UF[3];
    char cep[10];
} tipoEnder;

typedef struct pessoa
{
    char cpf[14];
    char nome[40];
    char email[20];
    int idade;
    tipoEnder endereco;
} tipoPessoa; //novo tipo de dado (agregado homogeneo)

int main()
{
    tipoPessoa Alunos[50]; //Matriz unidimensional de 50 elementos do tipoPessoa
    int i = 0, totalalunos;
    char limparbuffer;
    do
    {
        printf("\nCPF (0 = sair): ");
        fgets(Alunos[i].cpf, 14, stdin);
        if (Alunos[i].cpf[0] == '0')
            break;
        printf("Nome: ");
        fgets(Alunos[i].nome, 40, stdin);
        printf("Email: ");
        fgets(Alunos[i].email, 20, stdin);
        printf("Idade: ");
        scanf("%d", &Alunos[i].idade);
        while ((limparbuffer = fgetc(stdin)) != EOF && limparbuffer != '\n'){}
        printf("Endereco : ");
        fgets(Alunos[i].endereco.ender, 50, stdin);
        printf("Bairro: ");
        fgets(Alunos[i].endereco.bairro, 20, stdin);
        printf("Municipio: ");
        fgets(Alunos[i].endereco.munic, 20, stdin);
        printf("UF: ");
        fgets(Alunos[i].endereco.UF, 3, stdin);
        printf("CEP: ");
        fgets(Alunos[i].endereco.cep, 10, stdin);
        i++;
    } while (Alunos[i].cpf[0] != '0');
    totalalunos = i--;
    printf("\n");
    printf("--------------------------\n");
    for (i = 0; i < totalalunos; i++)
    {
        printf("CPF:\t%s", Alunos[i].cpf);
        printf("Nome:\t%s", Alunos[i].nome);
        printf("Email:\t%s", Alunos[i].email);
        printf("Idade:\t%d\n", Alunos[i].idade);
        printf("Endereco:\t%s", Alunos[i].endereco.ender);
        printf("Bairro:\t%s", Alunos[i].endereco.bairro);
        printf("Municipio:\t%s", Alunos[i].endereco.munic);
        printf("UF:\t%s", Alunos[i].endereco.UF);
        printf("CEP:\t%s\n\n", Alunos[i].endereco.cep);
    }
}