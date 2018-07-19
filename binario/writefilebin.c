#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    fp = fopen("dados.txt", "wb");

    if(fp<0){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    for(int i = 0; i<MAX; i++){
        printf("Digite o nome: ");
        fgets(lista[i].nome, 100, stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;
        printf("Digite o telefone: ");
        fgets(lista[i].telefone, 50, stdin);
        lista[i].telefone[strcspn(lista[i].telefone, "\n")] = 0;
        printf("Digite a rua: ");
        fgets(lista[i].endereco.rua, 100, stdin);
        lista[i].endereco.rua[strcspn(lista[i].endereco.rua, "\n")] = 0;
        printf("Digite o numero: ");
        scanf("%d", &lista[i].endereco.num);
        getchar();
    }

    fwrite(lista, sizeof(tPessoa), MAX, fp);

    printf("Lista das pessoas:\n");
    for(int i = 0; i<MAX;i++){
        printf("Nome: %s\n", lista[i].nome);
        printf("Telefone: %s\n", lista[i].telefone);
        printf("Rua: %s\n", lista[i].endereco.rua);
        printf("Numuro: %d\n", lista[i].endereco.num);
    }


    return 0;
}
