#include "cliente.h"

int main(){

FILE *Arquivo;
char opt;
int count = 0;
char nome[50];
char rg[50];
int n;
int c;
int m;
Cliente *First;
Lista *Liseq;

inicializarLista(&Liseq);
    
do{
    c = 0;
    m = 0;
    opt = menu(opt);
    switch(opt){
        case '0':
            system("cls");
	        fflush(stdin);
            printf("Nome do cliente: ");
            gets(nome);
            printf("RG do cliente: "); 
            gets(rg);
            ins_st(&First, &count, nome, rg, &c, &m);
        break;  
                
        case '1':
            system("cls");
	        fflush(stdin);
            printf("Nome do cliente: ");
            gets(nome);
            printf("RG do cliente: "); 
            gets(rg);
            //ins_endseq(&lista, &count, nome, rg, &c, &m);
            ins_end(&First, &count, nome, rg, &c, &m);
        break;    

        case '2':
            system("cls");
	        fflush(stdin);
            printf("Digite a posicao desejada: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("Nome do cliente: ");
            gets(nome);
            printf("RG do cliente: "); 
            gets(rg);
            ins_n(&First, &count, nome, rg, &n, &c, &m);
        break; 

        case '3':
            
            rem_st(&First, &count, &c, &m);
        break;

        case '4':
            rem_end(&First, &count, &c, &m);
        break;

        case '5':
            system("cls");
	        fflush(stdin);
            printf("Digite a posicao desejada: ");
            scanf("%d", &n);
            fflush(stdin);
            rem_n(&First, &count, &n, &c, &m);
        break;

        case '6':
            system("cls");
	        fflush(stdin);
            printf("RG que deseja procurar: "); 
            gets(rg);
            search(&First, &count, rg, &c, &m);
        break;

        case '7':
            list(&First, &count, &c, &m);
        break;

        case '8':
            save(Arquivo, &First, &count, &c, &m);
        break;

        case '9':
            if((&First != NULL)){
                for(int i = 0;i<(count);i++){
                    rem_st(&First, &count, &c, &m);
                }
                First = NULL;
                count = 0;
            }
            read(&First, &count, &c, &m);
        break;

        case 'x':
            printf("Programa Finalizado\n");
        break;    

        default:
            printf("Opcao Invalida\n");
    }

}while(opt!='x');

}
