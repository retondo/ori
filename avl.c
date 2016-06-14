#include <stdio.h>
#include "avl.h"

int arv_avl_vazia(no_avl *arvore)
{
    return arvore == NULL;
}

void arv_avl_imprimir(no_avl *arvore)
{
    if (!arv_avl_vazia(arvore)) {
        arv_avl_imprimir(arvore->esq);
        printf("%d\n", arvore->info);
        arv_avl_imprimir(arvore->dir);
    }
}

no_avl *arv_avl_inserir(no_avl *no, no_avl *pai, int valor)
{
    if (arv_avl_vazia(no)) {
        no = (no_avl *) malloc(sizeof(no_avl));
        no->pai = pai;
        no->dir = no->esq = NULL;
        no->bal = 0;
        no->info = valor;
    } else if (valor > no->info) {
        no->dir = arv_avl_inserir(no->dir, no, valor);
    } else if (valor < no->info) {
        no->esq = arv_avl_inserir(no->esq, no, valor);
    } else {
        printf("Nó já existe!");
    }

    return no;
}

int arv_avl_nivel(no_avl *arvore)
{
    int esq, dir;

    if (arv_avl_vazia(arvore)) return -1;

    esq = arv_avl_nivel(arvore->esq);
    dir = arv_avl_nivel(arvore->dir);

    if (esq > dir)
        return esq + 1;
    else
        return dir + 1;
}

void arv_avl_rot_esq(no_avl *no)
{
    no->pai = no->dir;
    no->dir->esq = no;
    no->dir = NULL;
}

void arv_avl_rot_dir(no_avl *no)
{
    no->pai = no->esq;
    no->esq->dir = no;
    no->esq = NULL;
}

void arv_avl_rot_esq_dir(no_avl *no)
{
    no->bal = 0;
    no->esq = 0;
    no->esq->dir = 0;
    no->esq->dir->esq = no->esq;
    no->esq->dir->dir = no;
    no->esq->dir->pai = no->pai;
    no->pai = no->esq->dir;
    no->esq->pai = no->esq->dir;
    no->esq->dir = NULL;
    no->esq = NULL;
}

void arv_avl_rot_dir_esq(no_avl *no)
{
    no->bal = 0;
    no->dir = 0;
    no->dir->esq = 0;
    no->dir->esq->dir = no->dir;
    no->dir->esq->esq = no;
    no->dir->esq->pai = no->pai;
    no->pai = no->dir->esq;
    no->dir->pai = no->dir->esq;
    no->dir->esq = NULL;
    no->dir = NULL;
}
