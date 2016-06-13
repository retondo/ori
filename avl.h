#ifndef AVL_H
#define AVL_H

typedef struct NO_AVL {
    int nome;
    int bal;                // Indica o fator de balanceamento do nó AVL

    struct NO_AVL *pai;
    struct NO_AVL *dir;
    struct NO_AVL *esq;
} no_avl;

no_avl *arv_avl_inserir(no_avl *arvore, int valor);

#endif
