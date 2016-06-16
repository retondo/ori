#ifndef ARVOREB_H
#define ARVOREB_H
#define MAX_KEYS 9

typedef struct NO_B {
    int folha;     // booleano para verificar se é folha
    int nkeys;    // número de chaves que tem
    int keys[MAX_KEYS];
    struct NO_B *filhos[MAX_KEYS+1];  // nós filhos
} *arvoreB;


arvoreB criar_arvoreB(void);
void remover_arvoreB(arvoreB b);
int procurar_arvoreB(arvoreB b, int key);
void inserir_arvoreB(arvoreB b, int key);
void imprimir_arvoreB(arvoreB b);
arvoreB *buscar_arvoreB (arvoreB b, int x);

#endif
