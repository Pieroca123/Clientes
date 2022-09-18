#include "cliente.h"

struct Cliente{
    char nome[50];
    char rg[50];
    struct Cliente *next;
    struct Cliente *prev;
};

struct Cseq{
    char nome[50];
    char rg[50];
};

struct Lista{
    Cseq *clientes;
    int size;
};

int menu(int opt){
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

void ins_st(Cliente **First, int *count, char *nome, char *rg, int *c, int *m){
    clock_t begin = clock();

	Cliente *New = NULL;	
	New = malloc(sizeof(Cliente));

    strcpy(New->nome,nome);
    strcpy(New->rg,rg);

    *count = (*count) + 1;
    
    if(*First== NULL){
        New->prev = New;
        New->next = New;
        *First = New;
        *c = (*c) + 1;
        *m = (*m) + 5;
    }else{
        (*First)->prev->next = New;
        New->prev = (*First)->prev;
        (*First)->prev = New;
        New->next = *First;
        *First = New;
        *c = (*c) + 2;
        *m = (*m) + 7;
    }

    clock_t end = clock();
    printf("Nome: %s Rg: %s Comparacoes: %d Movimentacoes: %d Tempo: %f Posicao: 1\n",New->nome,New->rg,(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC);
}

void ins_end(Cliente **First, int *count, char *nome, char *rg, int *c, int *m){
    clock_t begin = clock();

	Cliente *New = NULL;	
	New = malloc(sizeof(Cliente));
	
    strcpy(New->nome,nome);
    strcpy(New->rg,rg);

    *count = (*count) + 1;

    if(*First== NULL){
        New->prev = New;
        New->next = New;
        *First = New;
        *c = (*c) + 1;
        *m = (*m) + 5;
    }else{
        (*First)->prev->next = New;
        New->prev = (*First)->prev;
        (*First)->prev = New;
        New->next = *First;
        *c = (*c) + 2;
        *m = (*m) + 6;
    }

    clock_t end = clock();
    printf("Nome: %s Rg: %s Comparacoes: %d Movimentacoes: %d Tempo: %f Posicao: %d\n",New->nome,New->rg,(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC,(*count));
}

void ins_n(Cliente **First, int *count, char *nome, char *rg, int *n, int *c, int *m){
    clock_t begin = clock();

    Cliente *New = NULL;	
	New = malloc(sizeof(Cliente));

    if(*First == NULL && (*n) == 1){
        strcpy(New->nome,nome);
        strcpy(New->rg,rg);

        *count = (*count) + 1;

        New->prev = New;
        New->next = New;
        *First = New;
        *c = (*c) + 1;
        *m = (*m) + 5;
    }else if((*n) == 1){
        strcpy(New->nome,nome);
        strcpy(New->rg,rg);

        *count = (*count) + 1;

        (*First)->prev->next = New;
        New->prev = (*First)->prev;
        (*First)->prev = New;
        New->next = *First;
        *First = New;
        *c = (*c) + 2;
        *m = (*m) + 7;
    }else if((*n)==(*count)+1){
        strcpy(New->nome,nome);
        strcpy(New->rg,rg);

        *count = (*count) + 1;

        (*First)->prev->next = New;
        New->prev = (*First)->prev;
        (*First)->prev = New;
        New->next = *First;
        *c = (*c) + 3;
        *m = (*m) + 6;
    }else if((*n) > ((*count)+1) || (*n) <= 0){
        printf("A lista nao possui essa posicao\n");
        return;
    }else{
        Cliente *Current = (*First)->prev;

        for(int i=0;i<=((*n)-1);i++){
            Current = Current->next;
            *m = (*m) + 1;
        }

        strcpy(New->nome,nome);
        strcpy(New->rg,rg);
        
        Current->prev->next = New;
        New->prev = Current->prev;
        Current->prev = New;
        New->next = Current;
        *c = (*c) + 5;
        *m = (*m) + 7;
        *count = (*count) + 1;
    }
    clock_t end = clock();
    printf("Nome: %s Rg: %s Comparacoes: %d Movimentacoes: %d Tempo: %f Posicao: %d\n",New->nome,New->rg,(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC,(*n));
}

void rem_st(Cliente **First, int *count, int *c, int *m){
    clock_t begin = clock();
    system("cls");
	fflush(stdin);
    char nome[50];
    char rg[50];

    if(*First == NULL){
        printf("Nao existem mais clientes para serem apagados\n");
        return;
    }else if((*count) == 1){
        strcpy(nome, (*First)->nome);
        strcpy(rg, (*First)->rg);
        free(*First);
        *First = NULL;
        *count = (*count) - 1;
        *c = (*c) + 2;
        *m = (*m) + 4;
        printf("Voce acabou de apagar o ultimo cliente\n");
    }else{
        Cliente *Aux;
        (*First)->prev->next = (*First)->next;
        (*First)->next->prev = (*First)->prev;
        Aux = (*First)->next;
        strcpy(nome, (*First)->nome);
        strcpy(rg, (*First)->rg);
        free(*First);
        *First = Aux;
        *count = (*count) - 1;
        *c = (*c) + 3;
        *m = (*m) + 7;
        printf("Cliente apagado com sucesso\n");
    }
    clock_t end = clock();
    printf("Nome: %s Rg: %s Comparacoes: %d Movimentacoes: %d Tempo: %f Posicao: 1\n",nome,rg,(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC);
}

void rem_end(Cliente **First, int *count, int *c, int *m){
    clock_t begin = clock();
    system("cls");
	fflush(stdin);
    char nome[50];
    char rg[50];

    if(*First == NULL){
        printf("Nao existem mais clientes para serem apagados\n");
        return;
    }else if((*count) == 1){
        strcpy(nome, (*First)->nome);
        strcpy(rg, (*First)->rg);
        free(*First);
        *First = NULL;
        *count = (*count) - 1;
        *c = (*c) + 2;
        *m = (*m) + 4;
        printf("Voce acabou de apagar o ultimo cliente\n");
    }else{
        strcpy(nome, (*First)->prev->nome);
        strcpy(rg, (*First)->prev->rg);
        Cliente *Aux;
        (*First)->prev->prev->next = (*First);
        Aux = (*First)->prev->prev;
        free((*First)->prev);
        (*First)->prev = Aux;
        *count = (*count) - 1;
        *c = (*c) + 3;
        *m = (*m) + 6;
        printf("Cliente apagado com sucesso\n");
    }
    clock_t end = clock();
    printf("Nome: %s Rg: %s Comparacoes: %d Movimentacoes: %d Tempo: %f Posicao: %d\n",nome,rg,(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC,(*count));
}

void rem_n(Cliente **First, int *count, int *n, int *c, int *m){
    clock_t begin = clock();

    char nome[50];
    char rg[50];
    
    if(*First== NULL){
        printf("Nao existem mais clientes para serem apagados\n");
        return;
    }else if((*n) > (*count) || (*n) <= 0){
        printf("A lista nao possui essa posicao\n");
        return;
    }else if((*count) == 1 && (*n) == 1){
        strcpy(nome, (*First)->nome);
        strcpy(rg, (*First)->rg);
        free(*First);
        *First = NULL;
        *count = (*count) - 1;
        *c = (*c) + 3;
        *m = (*m) + 4;
        printf("Voce acabou de apagar o ultimo cliente\n");
    }else if((*n) == 1){
        Cliente *Aux;
        (*First)->prev->next = (*First)->next;
        (*First)->next->prev = (*First)->prev;
        Aux = (*First)->next;
        strcpy(nome, (*First)->nome);
        strcpy(rg, (*First)->rg);
        free(*First);
        *First = Aux;
        *count = (*count) - 1;
        *c = (*c) + 4;
        *m = (*m) + 7;
        printf("Cliente apagado com sucesso\n");
    }else{
        Cliente *Current = (*First)->prev;

        for(int i=0;i<=((*n)-1);i++){
            Current = Current->next;
            *m = (*m) + 1;
        }

        Current->prev->next = Current->next;
        Current->next->prev = Current->prev;
        strcpy(nome, Current->nome);
        strcpy(rg, Current->rg);
        free(Current);
        *count = (*count) - 1;
        *c = (*c) + 5;
        *m = (*m) + 6;
        printf("Cliente apagado com sucesso\n");
    }
    clock_t end = clock();
    printf("Nome: %s Rg: %s Comparacoes: %d Movimentacoes: %d Tempo: %f Posicao: %d\n",nome,rg,(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC,(*n));
}

void search(Cliente **First, int *count, char *rg, int *c, int *m){
    clock_t begin = clock();
    system("cls");
	fflush(stdin);

    if(*First== NULL){
        printf("Nao existem clientes cadastrados\n");
        return;
    }else{
        Cliente *Current = (*First)->prev;
        *m = (*m) + 1;
        for(int i=0;i<*count;i++){
            Current = Current->next;
            int result = strcmp(Current->rg,rg);
            *c = (*c) + 1;
            *m = (*m) + 1;
            if(result == 0){
                clock_t end = clock();
                *c = (*c) + 2;
                printf("Nome: %s Rg:%s Comparacoes: %d Movimentacoes: %d Tempo: %f Posicao: %d\n",Current->nome,Current->rg,(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC,(i+1));
                return;
            }
        }
        printf("RG nao encontrado!");
    }
}

void list(Cliente **First, int *count, int *c, int *m){
    clock_t begin = clock();
    system("cls");
	fflush(stdin);

    if((*count)<=0){
        printf("Nao existem clientes cadastrados\n");
    }else{
        Cliente *Current = (*First)->prev;
        for(int i=0;i<(*count);i++){
            Current = Current->next;
            *m = (*m) + 1;
            printf("%s\t %s\n",Current->nome,Current->rg);
        }
        *c = (*c) + 2;
        *m = (*m) + 1;
        clock_t end = clock();
        printf("Comparacoes: %d Movimentacoes: %d Tempo: %f\n",(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC);
    }
}

void save(FILE *Arquivo, Cliente **First, int *count, int *c, int *m){
    clock_t begin = clock();
    system("cls");
	fflush(stdin);

    Cliente *Aux;
    Aux = *First;
    remove("Arquivo.txt");

    if(*First != NULL) {
        *c = (*c) + 1;
        *m = (*m) + 1;
        Arquivo = fopen("Arquivo.txt", "wb");
        if(Arquivo == NULL) {     
            return;
        }do {
            fprintf(Arquivo, "%s,%s\n", Aux->nome, Aux->rg);
            Aux = Aux->next;
            *m = (*m) + 1;
        }while(Aux != *First);
        *c = (*c) + 1;
        fclose(Arquivo);
        clock_t end = clock();
        printf("Comparacoes: %d Movimentacoes: %d Tempo: %f\n",(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC);
    }
}

void read(Cliente **First, int *count, int *c, int *m){
    clock_t begin = clock();
    system("cls");
	fflush(stdin);

    FILE *arq = fopen("NomeRG10.txt", "r");
    const char s[2] = ",";
    char *token;
    int i;
    if(arq != NULL)
    {
        *c = (*c) + 1;
        char line[100];
        while(fgets(line, sizeof line, arq) != NULL)
        {
            if(*First== NULL){
                Cliente *New = NULL;
                New = malloc(sizeof(Cliente));
                token = strtok(line, s);
                for(i=0;i<2;i++){
                    if(i==0)
                    {   
                        strcpy(New->nome, token);
                        token = strtok(NULL,s);
                    } else {
                        token[strcspn(token, "\n")] = 0;
                        strcpy(New->rg, token);
                    }    
                }
                New->prev = New;
                New->next = New;
                *First = New;
                *c = (*c) + 4;
                *m = (*m) + 2;
            }else{
                Cliente *New = NULL;
                New = malloc(sizeof(Cliente));
                Cliente *Current = (*First)->prev;

                token = strtok(line, s);
                for(i=0;i<2;i++){
                    if(i==0)
                    {   
                        strcpy(New->nome, token);
                        token = strtok(NULL,s);
                    } else {
                        token[strcspn(token, "\n")] = 0;
                        strcpy(New->rg, token);
                    }    
                }
                Current->next = New;
                (*First)->prev = New;
                New->next = *First;
                New->prev = Current;
                Current = New;
                *c = (*c) + 4;
                *m = (*m) + 7;
            }

            *count = (*count) + 1;
        }
        fclose(arq);
        clock_t end = clock();
        printf("Comparacoes: %d Movimentacoes: %d Tempo: %f\n",(*c),(*m),(double)(end - begin)/CLOCKS_PER_SEC);
    } else {
        perror("NomeRG10.txt");
    }   
}

void inicializarLista(Lista **l){
    (*l)->size = 0;
}