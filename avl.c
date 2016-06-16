#include "avl.h"

int aux;

int avl_vazia(no_avl *arvore)
{
    return arvore == NULL;
}

void avl_imprimir(no_avl *arvore)
{
    if (!avl_vazia(arvore)) {
        printf("%d\t%d\t%d\n", arvore->info, arvore->alt, arvore->bal);
        avl_imprimir(arvore->esq);
        avl_imprimir(arvore->dir);
    }
}

no_avl *avl_inserir(no_avl *arvore_avl, no_avl *pai, int valor)
{
    // Insere se for o lugar certo
    if (avl_vazia(arvore_avl)) {
        arvore_avl = (no_avl *) malloc(sizeof(no_avl));
        if (arvore_avl == NULL) {
            aux = -1;
            return arvore_avl;
        }
        arvore_avl->pai = pai;
        arvore_avl->dir = arvore_avl->esq = NULL;
        arvore_avl->bal = 0;
        arvore_avl->info = valor;

        if (!arvore_avl->pai) {
            arvore_avl->alt = 1;
        } else {
            arvore_avl->alt = arvore_avl->pai->alt + 1;
        }

        aux = 1;
        return arvore_avl;
    }
    // Procura o lugar certo e se precisar faz as rotações
    if (valor > arvore_avl->info) {
        arvore_avl->dir = avl_inserir(arvore_avl->dir, arvore_avl, valor);
        if (aux != 1) {
            aux = 0;
            return arvore_avl;
        }

        if (++(arvore_avl->bal) == 2) {
            if (arvore_avl->dir->bal == 1) {
                arvore_avl = avl_rot_esq(arvore_avl);
                aux = 0;
                return arvore_avl;
            }
            arvore_avl->dir = avl_rot_dir(arvore_avl->dir);
            arvore_avl = avl_rot_esq(arvore_avl);
            aux = 0;
            return arvore_avl;
        }

        if (arvore_avl->bal == 0) {
            aux = 0;
            return arvore_avl;
        } else {
            aux = 1;
            return arvore_avl;
        }

        //return ((arvore_avl->bal == 0) ? 0 : 1);
    }

    if (valor < arvore_avl->info) {
        arvore_avl->esq = avl_inserir(arvore_avl->esq, arvore_avl, valor);
        if (aux != 1) {
            aux = 0;
            return arvore_avl;
        }

        if (--(arvore_avl->bal) == -2) {
            if (arvore_avl->esq->bal == -1) {
                arvore_avl = avl_rot_dir(arvore_avl);
                aux = 0;
                return arvore_avl;
            }
            arvore_avl->esq = avl_rot_esq(arvore_avl->esq);
            arvore_avl = avl_rot_dir(arvore_avl);
            aux = 0;
            return arvore_avl;
        }

        if (arvore_avl->bal == 0) {
            aux = 0;
            return arvore_avl;
        } else {
            aux = 1;
            return arvore_avl;
        }

        //return ((arvore_avl->bal == 0) ? 0 : 1);

    }

    aux = 0;
    return arvore_avl;
}

int avl_alt_esq(no_avl *no)
{
    int esq = 0;

    if (!no->esq)
        return 0;
    else {
        no_avl *aux = no;
        // Percorre o lado esquerdo do nó
        while (aux->esq) {
            aux = aux->esq;
            esq = esq + 1;
            // Percorre o lado direito se existir
            if ((!aux->esq) && (aux->dir)) {
                while(aux->dir) {
                    esq = esq + 1;
                    aux = aux->dir;
                } // fim while
            } // fim if
        } // fim while
    } // fim else

    return esq;
}

int avl_alt_dir(no_avl *no)
{
    int dir = 0;

    if (!no->dir)
        return 0;
    else {
        no_avl *aux = no;
        // Percorre o lado esquerdo do nó
        while (aux->dir) {
            aux = aux->dir;
            dir = dir + 1;
            // Percorre o lado direito se existir
            if ((!aux->dir) && (aux->esq)) {
                while(aux->esq) {
                    dir = dir + 1;
                    aux = aux->esq;
                } // fim while
            } // fim if
        } // fim while
    } // fim else

    return dir;
}

no_avl *avl_rot_esq(no_avl *no)
{
    no_avl *y;
    y = no->dir;
    // Realizando rotaçao
    no->dir = y->esq;
    if (y->esq)
        y->esq->pai = no;
    y->esq = no;
    y->pai = no->pai;
    if (no->pai) {
        if (no->pai->esq == no) {
            no->pai->esq = y;
        } else {
            no->pai->dir = y;
        }
    }
    no->pai = y;
    // Atualizando a altura dos nós e rebalanceando
    y->alt = y->alt - 1;
    no->alt = no->alt + 1;
    y->bal = avl_alt_dir(y) - avl_alt_esq(y);
    no->bal = avl_alt_dir(no) - avl_alt_esq(no);

    return y;
}

no_avl *avl_rot_dir(no_avl *no)
{
    no_avl *y;
    y = no->esq;
    // Realizando rotaçao
    no->esq = y->dir;
    if (y->dir)
        y->dir->pai = no;
    y->dir = no;
    y->pai = no->pai;
    if (no->pai) {
        if (no->pai->dir == no) {
            no->pai->dir = y;
        } else {
            no->pai->esq = y;
        }
    }
    no->pai = y;
    // Atualizando a altura dos nós e rebalanceando
    y->alt = y->alt - 1;
    no->alt = no->alt + 1;
    y->bal = avl_alt_dir(y) - avl_alt_esq(y);
    no->bal = avl_alt_dir(no) - avl_alt_esq(no);

    return y;
}
