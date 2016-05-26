#include "arvore.h"
#include "arquivo.h"

int arvore_vazia(no *arvore)
{
    return arvore == NULL;
}

// Faz busca de um nó na árvore
no *busca(no *arvore, int numero)
{
    if (!arvore_vazia(arvore)) {
        if (numero == arvore->nome)
            return arvore;
        else if (numero < arvore->nome)
            busca(arvore->esq, numero);
        else if (numero > arvore->nome)
            busca(arvore->dir, numero);
        else
            return NULL;
    }
}

// Função recursiva para inserção de um nó na árvore
no *inserir(no *arvore, int novo)
{
    if (arvore_vazia(arvore)) {
        arvore = (no *) malloc(sizeof(no));
        arvore->dir = arvore->esq = NULL;
        arvore->nome = novo;
    } else if (novo < arvore->nome) {
        arvore->esq = inserir(arvore->esq, novo);
    } else if (novo > arvore->nome){
        arvore->dir = inserir(arvore->dir, novo);
    } else {
        printf("Nó já existe.\n");
    }

    return arvore;
}

// Imprime a árvore em ordem crescente
void imprimir(no *arvore)
{
    if (!arvore_vazia(arvore)) {
        imprimir(arvore->esq);
        printf("%d\n", arvore->nome);
        imprimir(arvore->dir);
    }
}

no *remover(no *arvore, int numero)
{
    no *anterior = NULL;

    if (!arvore_vazia(arvore)) {
        if (numero == arvore->nome) {
            // Remove a raiz da árvore
            if (anterior == NULL) {
                if (!arvore_vazia(arvore->dir))
                    arvore = arvore->dir;
                else
                    arvore = arvore->esq;
            } else if (anterior->nome < numero) {
                if (!arvore_vazia(arvore->dir))
                    arvore = arvore->dir;
            }

        } else if (numero > arvore->nome) {
            anterior = remover(arvore->dir, numero);
        } else if (numero < arvore->nome){
            anterior = remover(arvore->esq, numero);
        } else {
            printf("O elemento %d não existe", numero);
        }
    }

    return arvore;
}

void remover_no_sem_filho(no *anterior, no *atual)
{
    anterior = NULL;
    free(atual);
}

void remover_no_um_filho(no *anterior, no *atual)
{
    if (!arvore_vazia(atual->dir))
        anterior = atual->dir;
    else
        anterior = atual->esq;

    free(atual);
}

void remover_no_dois_filhos(no *anterior, no *atual)
{
    no *aux = NULL;


}


