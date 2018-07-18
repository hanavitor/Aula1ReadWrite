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
    fp = fopen("dados.txt", "wb");

    if(fp<0){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    for(int i = 0; i<MAX; i++){
        printf("Digite o nome: ");
        gets(lista[i].nome);
        printf("Digite o telefone: ");
        gets(lista[i].telefone);
        printf("Digite a rua: ");
        gets(lista[i].endereco.rua);
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
