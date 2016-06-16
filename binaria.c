
#include "binaria.h"

int bin_vazia(no_bin *arvore)
{
    return arvore == NULL;
}

no_bin *bin_buscar(no_bin *arvore, int valor)
{
    if (!bin_vazia(arvore)) {
        if (valor == arvore->info)
            return arvore;
        else if (valor < arvore->info)
            return bin_buscar(arvore->esq, valor);
        else if (valor > arvore->info)
            return bin_buscar(arvore->dir, valor);
    }

    return NULL;
}

no_bin *bin_inserir(no_bin *arvore, int valor)
{
    if (bin_vazia(arvore)) {
        arvore = (no_bin *) malloc(sizeof(no_bin));
        arvore->dir = arvore->esq = NULL;
        arvore->info = valor;
    } else if (valor < arvore->info) {
        arvore->esq = bin_inserir(arvore->esq, valor);
    } else if (valor > arvore->info) {
        arvore->dir = bin_inserir(arvore->dir, valor);
    } else {
        printf("Nó já existe.\n");
    }

    return arvore;
}

void bin_imprimir(no_bin *arvore)
{
    if (!bin_vazia(arvore)) {
        bin_imprimir(arvore->esq);
        printf("%d\n", arvore->info);
        bin_imprimir(arvore->dir);
    }
}
