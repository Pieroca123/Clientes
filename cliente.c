#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

struct Cliente{
    char nome[50];
    char rg[50];
    struct Cliente *next;
    struct Cliente *prev;
};

int menu(int opt){
    system("cls");
	printf("---------MENU--------\n");
    printf("0 - Insercao no inicio da lista\n");
    printf("1 - Insercao no fim da lista\n");
    printf("2 - Insercao na posicao N da lista\n");
    printf("3 - Remocao no inicio da lista\n");
    printf("4 - Remocao no fim da lista\n");
    printf("5 - Remocao na posicao N da lista\n");
    printf("6 - Procura por RG\n");
    printf("7 - Mostrar lista\n");
    printf("8 - Salvar lista em arquivo\n");
    printf("9 - Ler lista de um arquivo\n");
    printf("x - Sair do Sistema\n");
    printf("Digite a opcao desejada: ");
    opt = getchar();
    return(opt);
}

void ins_st(Cliente **First, int *count){
    system("cls");
    fflush(stdin);
    
	Cliente *New = NULL;

    printf("\nNome do cliente: ");
    fgets(New->nome, 50, stdin);
    printf("\nRG do cliente: "); 
    fgets(New->rg, 50, stdin);
    printf("Nome: %s Rg:%s\n",New->nome,New->rg);
    printf("\nDeu bug");

    *count = (*count) + 1;

    if(*First== NULL){
        New->prev = New;
        New->next = New;
        *First = New;
    }else{
        (*First)->prev->next = New;
        New->prev = (*First)->prev;
        (*First)->prev = New;
        New->next = *First;
        (*First) = New;
    }
}

void ins_end(){

}

void ins_n(){

}

void rem_st(){

}

void rem_end(){

}

void rem_n(){

}

void search(){

}

void list(){

}

void save(){

}

void read(){

}
