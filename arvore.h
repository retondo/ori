#ifndef BINARIA_H_
#define BINARIA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int nome;
    struct No *dir;
    struct No *esq;
} no;

int arvore_vazia(no *arvore);
no *busca(no *arvore, int numero);
no *inserir(no *arvore, int novo);
no *remover(no *arvore, int numero);
void imprimir(no *arvore);

#endif

