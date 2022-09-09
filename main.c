#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main(){
    
char opt;
int count = 0;
Cliente *First = NULL;
Cliente *Current = NULL;
    
do{
    opt = menu(opt);
    switch(opt){
        case '0':
            ins_st(&First, &count);
        break;  
                
        case '1':

        break;    

        case '2':
             
        break; 

        case '3':
             
        break;

        case '4':
             
        break;

        case '5':
             
        break;

        case '6':
             
        break;

        case '7':
             
        break;

        case '8':
             
        break;

        case '9':
             
        break;

        case 'x':
             
        break;    

        default:
             printf("Opcao Invalida\n");
    }
}while(opt!='x');

}
