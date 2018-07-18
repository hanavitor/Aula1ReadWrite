#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct endereco{
    char rua[100];
    int num;
}tEndereco;

typedef struct pessoa{
    char nome[100];
    char telefone[50];
    tEndereco endereco;
}tPessoa;

int main (){
    
    tPessoa lista[MAX];
    FILE *fp;
    fp = fopen("dadoslegivel.txt", "r");

    if(fp<0){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    for(int i = 0; i<MAX; i++){
        fgets(lista[i].nome, 100, fp);
        fgets(lista[i].telefone, 50, fp);
        fgets(lista[i].endereco.rua, 100, fp);
        fscanf(fp, "%d%*c", &lista[i].endereco.num);
    }

    printf("Lista das pessoas:\n");
    for(int i = 0; i<MAX;i++){
        printf("%s\n", lista[i].nome);
        printf("%s\n", lista[i].telefone);
        printf("%s\n", lista[i].endereco.rua);
        printf("%d\n", lista[i].endereco.num);
    }
        

    return 0;
}
