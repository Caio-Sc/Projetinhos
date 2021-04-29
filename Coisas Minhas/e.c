#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
int main()
{
    char j[100];
    int i, r, c;
    printf("Escreva a Senha: ");
    fgets(j, 100, stdin);
    struct timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec * _getpid());
    FILE *fptr;
    fptr = fopen("C:\\Github\\Atividades-PUC\\NGerados.txt", "w");
    if (strcmp(j, "Pedro\n") == 0 || strcmp(j, "pedro\n") == 0)
    {
        system("color 02");
        printf("Hackear Nasa (1)\n");
        printf("Hackear Bancos (2)\n");
        printf("Hackear Outra Pessoa (3)\n");
        scanf("%d", &i);
        printf("Coloque o Ip: ");
        scanf("%d", &i);
        r = (rand() * rand()) % 10000001;
        gettimeofday(&t1, NULL);
        srand(t1.tv_usec * t1.tv_sec * _getpid());
        while (i != r)
        {
            i = (rand() * rand()) % 10000001;
            printf("%d\t", i);
            fprintf(fptr, "%d\t", i);
            c++;
        }
        printf("\nProntinho!\n");
        printf("O numero gerado foi: %d\n", r);
        fprintf(fptr, "\n%d", c);
        fclose(fptr);
    }
    else
    {
        system("color 04");
        printf("Senha errada\n");
    }
    system("pause");
}