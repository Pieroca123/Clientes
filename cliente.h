#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct Cliente Cliente;
typedef struct Cseq Cseq;
typedef struct Lista Lista;

int menu(int opt);
//Funcoes de Encadeada
void ins_st(Cliente **First, int *count, char *nome, char *rg, int *c, int *m);
void ins_end(Cliente **First, int *count, char *nome, char *rg, int *c, int *m);
void ins_n(Cliente **First, int *count, char *nome, char *rg, int *n, int *c, int *m);
void rem_st(Cliente **First, int *count, int *c, int *m);
void rem_end(Cliente **First, int *count, int *c, int *m);
void rem_n(Cliente **First, int *count, int *n, int *c, int *m);
void search(Cliente **First, int *count, char *rg, int *c, int *m);
void list(Cliente **First, int *count, int *c, int *m);
void save(FILE *Arquivo, Cliente **First, int *count, int *c, int *m);
void read(Cliente **First, int *count, int *c, int *m);

void inicializarLista(Lista **l);
//void ins_endseq(Cseq **LISTA, int *count, char *nome, char *rg, int *c, int *m);

#endif