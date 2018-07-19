#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct endereco{
    char rua[100];
    char num[50];
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
        lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;
        fgets(lista[i].telefone, 50, fp);
        lista[i].telefone[strcspn(lista[i].telefone, "\n")] = 0;
        fgets(lista[i].endereco.rua, 100, fp);
        lista[i].endereco.rua[strcspn(lista[i].endereco.rua, "\n")] = 0;
        fgets(lista[i].endereco.num, 50, fp);
        lista[i].endereco.num[strcspn(lista[i].endereco.num, "\n")] = 0;
    }

    printf("Lista das pessoas:\n");
    for(int i = 0; i<MAX;i++){
        printf("Nome: %s\n", lista[i].nome);
        printf("Telefone: %s\n", lista[i].telefone);
        printf("Rua: %s\n", lista[i].endereco.rua);
        printf("Numero: %s\n", lista[i].endereco.num);
    }

    return 0;
}
