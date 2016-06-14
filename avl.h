#ifndef AVL_H
#define AVL_H

typedef struct No_AVL {
    int info;
    int bal;                    // Indica o fator de balanceamento do nó AVL

    struct No_AVL *pai;
    struct No_AVL *dir;
    struct No_AVL *esq;
} no_avl;

int arv_avl_vazia(no_avl *arvore);                                  // Verifica se a árvore está vazia
int arv_avl_nivel(no_avl *arvore);                                  // Verifica o nível da árvore
no_avl *arv_avl_inserir(no_avl *arvore, no_avl *pai, int valor);    // Insere um nó na árvore
no_avl *arv_avl_buscar(no_avl *arvore, int valor);                  // Realiza a busca de um nó na árvore
void arv_avl_imprimir(no_avl *arvore);                              // Imprime a árvore em ordem crescente
void arv_avl_rot_esq(no_avl *no);                                   // Realiza rotação à esquerda
void arv_avl_rot_dir(no_avl *no);                                   // Realiza rotação à direita
void arv_avl_rot_esq_dir(no_avl *no);                               // Realiza rotação esquerda-direita
void arv_avl_rot_dir_esq(no_avl *no);                               // Realiza rotação direita-esquerda

#endif
