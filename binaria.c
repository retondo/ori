#include "binaria.h"
#include "arquivo.h"

// Retorna um ponteiro de uma aŕvore com espaço alocado dinâmicamente
no_bin *arv_bin_aloc()
{
    no_bin *a = (no_bin *) malloc(sizeof(no_bin));
    return a;
}

// Verifica se a árvore está vazia
int arv_vazia(no_bin *arvore)
{
    return arvore == NULL;
}

// Faz busca de um nó na árvore
no_bin *arv_bin_buscar(no_bin *arvore, int valor)
{
    if (!arv_vazia(arvore)) {
        if (valor == arvore->nome)
            return arvore;
        else if (valor < arvore->nome)
            return arv_bin_buscar(arvore->esq, valor);
        else if (valor > arvore->nome)
            return arv_bin_buscar(arvore->dir, valor);
    }

    return NULL;
}

// Função recursiva para inserção de um nó na árvore
no_bin *arv_bin_inserir(no_bin *arvore, int valor)
{
    if (arv_vazia(arvore)) {
        arvore = (no_bin *) malloc(sizeof(no_bin));
        arvore->dir = arvore->esq = NULL;
        arvore->nome = valor;
    } else if (valor < arvore->nome) {
        arvore->esq = arv_bin_inserir(arvore->esq, valor);
    } else if (valor > arvore->nome){
        arvore->dir = arv_bin_inserir(arvore->dir, valor);
    } else {
        printf("Nó já existe.\n");
    }

    return arvore;
}

// Imprime a árvore em ordem crescente
void arv_imprimir(no_bin *arvore)
{
    if (!arv_vazia(arvore)) {
        arv_imprimir(arvore->esq);
        printf("%d\n", arvore->nome);
        arv_imprimir(arvore->dir);
    }
}


