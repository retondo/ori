#ifndef BINARIA_H
#define BINARIA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO_BIN {
    int nome;
    struct NO_BIN *dir;
    struct NO_BIN *esq;
} no_bin;

int arv_vazia(no_bin *arvore);
no_bin *arv_bin_aloc();
no_bin *arv_bin_buscar(no_bin *arvore, int numero);
no_bin *arv_bin_inserir(no_bin *arvore, int novo);
void arv_imprimir(no_bin *arvore);

#endif

