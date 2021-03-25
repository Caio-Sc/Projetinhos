#include <stdio.h>

int containsList(int c[10], int d){
    for(int i = 0; i < 10; i++){
        if(c[i] == NULL){
            c[i] = d;
            return 0;
        }else if(c[i] == d){
            return 1;
        }
    }
    return 2;
}

main(){
    int a[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int b;
    
    while(1){
        printf("Escolha um numero inteiro: ");
        scanf("%d", &b);
        
        if(containsList(a, b)){
            printf("Numero esta na lista.\n");
        }else{
            printf("Numero nao estava na lista\n");
            for(int i = 0; i < 10; i++){
                printf("Teste: %d\n", a[i]);
            }
        }
    }
}