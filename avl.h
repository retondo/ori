#ifndef AVL_H
#define AVL_H

typedef struct No_AVL {
    int info;               // Informação do nó
    int alt;                // Indica a altura do nó
    int bal;

    struct No_AVL *pai;
    struct No_AVL *dir;
    struct No_AVL *esq;
} no_avl;

int avl_vazia(no_avl *arvore);                                  // Verifica se a árvore está vazia
int avl_fator_bal(no_avl *no);                                  // Calcula a altura do nó
no_avl *avl_inserir(no_avl *arvore, no_avl *pai, int valor);    // Insere um nó na árvore
no_avl *avl_buscar(no_avl *arvore, int valor);                  // Realiza a busca de um nó na árvore
void avl_imprimir(no_avl *arvore);                              // Imprime a árvore em ordem crescente
no_avl *avl_rot_esq(no_avl *no);                                // Realiza rotação à esquerda
no_avl *avl_rot_dir(no_avl *no);                                // Realiza rotação à direita
void avl_rot_esq_dir(no_avl *no);                               // Realiza rotação esquerda-direita
void avl_rot_dir_esq(no_avl *no);                               // Realiza rotação direita-esquerda

#endif
