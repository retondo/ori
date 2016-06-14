#include <stdio.h>
#include "binaria.h"

int arv_bin_vazia(no_bin *arvore)
{
    return arvore == NULL;
}

no_bin *arv_bin_buscar(no_bin *arvore, int valor)
{
    if (!arv_bin_vazia(arvore)) {
        if (valor == arvore->info)
            return arvore;
        else if (valor < arvore->info)
            return arv_bin_buscar(arvore->esq, valor);
        else if (valor > arvore->info)
            return arv_bin_buscar(arvore->dir, valor);
    }

    return NULL;
}

no_bin *arv_bin_inserir(no_bin *arvore, int valor)
{
    if (arv_bin_vazia(arvore)) {
        arvore = (no_bin *) malloc(sizeof(no_bin));
        arvore->dir = arvore->esq = NULL;
        arvore->info = valor;
    } else if (valor < arvore->info) {
        arvore->esq = arv_bin_inserir(arvore->esq, valor);
    } else if (valor > arvore->info) {
        arvore->dir = arv_bin_inserir(arvore->dir, valor);
    } else {
        printf("Nó já existe.\n");
    }

    return arvore;
}

void arv_bin_imprimir(no_bin *arvore)
{
    if (!arv_bin_vazia(arvore)) {
        arv_bin_imprimir(arvore->esq);
        printf("%d\n", arvore->info);
        arv_bin_imprimir(arvore->dir);
    }
}
