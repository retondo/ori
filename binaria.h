#ifndef BINARIA_H
#define BINARIA_H

typedef struct No_Bin {
    int info;
    struct No_Bin *dir;
    struct No_Bin *esq;
} no_bin;

no_bin *arvore_bin;

int bin_vazia(no_bin *arvore);                      // Verifica se a árvore está vazia
no_bin *bin_buscar(no_bin *arvore, int valor);      // Realiza a busca de um nó na árvore
no_bin *bin_inserir(no_bin *arvore, int valor);     // Insere um nó na árvore
void bin_imprimir(no_bin *arvore);                  // Imprime a estrutura da árvore em ordem crescente

#endif

