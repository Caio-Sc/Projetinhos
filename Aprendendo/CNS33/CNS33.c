//CNS33 - Tipo agregado heterogeneo
//Caio Sclavi - 13/05
/*Cadastrar numa matriz heterogenea os dados de varias pessoas
sair com cpf = 0
apresentalos na tela
*/
#include <stdio.h>
typedef struct pessoa
{
    char cpf[14];
    char nome[40];
    char email[20];
    int idade;
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
        printf("Idade:\t%d\n\n", Alunos[i].idade);
    }
}