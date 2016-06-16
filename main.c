#include "arquivo.h"
#include "binaria.h"
#include "avl.h"
#include "arvoreB.h"
#include <locale.h>
#include <time.h>

int main(void) {
	float Tinicial, Tfinal,Ttotal;
	int indice, quantidade, i;
	no_bin *arvore = NULL;
	no_avl *arvoreavl = NULL;
	arvoreB B;
	B = criar_arvoreB();

    // Define a língua portuguesa como padrão
    setlocale(LC_ALL, "Portuguese");

	printf("Forneça a quantidade de arquivos a serem criados: ");
	scanf("%d", &quantidade);
	int vetor[quantidade];

    srand(time(NULL));
	
	//Criação de arquivos
	for (i = 0; i < quantidade; i++) {
		indice = gerador_nome_rand();
		printf("indice= %d\n", indice);
		criador_arquivo(indice);
		vetor[i] = indice;
	}
	
	//Medição de tempo para inserir na árvore binária
	Tinicial = (float)clock()/CLOCKS_PER_SEC;
	//inserção em arvore binária
	for (i = 0; i < quantidade; i++) {
        arvore = bin_inserir(arvore, vetor[i]);
	}
	Tfinal = (float)clock()/CLOCKS_PER_SEC;
	Ttotal = Tfinal - Tinicial;
    printf("Tempo total para inserir na árvore binária: %f\n", Ttotal);

	//Medição de tempo para inserir na árvore avl
	Tinicial = (float)clock()/CLOCKS_PER_SEC;
	//inserção em arvore binária
	for (i = 0; i < quantidade; i++) {
        arvoreavl = avl_inserir(arvoreavl, NULL, vetor[i]);
	}
	Tfinal = (float)clock()/CLOCKS_PER_SEC;
	Ttotal = Tfinal - Tinicial;
    printf("Tempo total para inserir na árvore avl: %f\n", Ttotal);

	//Medição de tempo para inserir na árvore B
	Tinicial = (float)clock()/CLOCKS_PER_SEC;
	//inserção em arvore B
	for (i = 0; i < quantidade; i++) {
		inserir_arvoreB(B, vetor[i]);
	}
	Tfinal = (float)clock()/CLOCKS_PER_SEC;
	Ttotal = Tfinal - Tinicial;
    printf("Tempo total para inserir na árvore B: %f\n", Ttotal);

	//Medição de tempo para busca em árvore binária
	no_bin *busca;
	Tinicial = (float)clock()/CLOCKS_PER_SEC;
	//busca em arvore binária
	for (i = 0; i < quantidade; i++) {
        busca = bin_buscar(arvore, vetor[i]);
	}
	Tfinal = (float)clock()/CLOCKS_PER_SEC;
	Ttotal = Tfinal - Tinicial;
    printf("Tempo total para buscar na árvore binária: %f\n", Ttotal);

	//Medição de tempo para busca em árvore avl
    no_avl *buscaavl;
	Tinicial = (float)clock()/CLOCKS_PER_SEC;
	//busca em arvore binária
	for (i = 0; i < quantidade; i++) {
        buscaavl = avl_buscar(arvoreavl, vetor[i]);
	}
	Tfinal = (float)clock()/CLOCKS_PER_SEC;
	Ttotal = Tfinal - Tinicial;
    printf("Tempo total para buscar na árvore avl: %f\n", Ttotal);

	//Medição de tempo para busca em árvore B
	arvoreB buscaB;
    buscaB = criar_arvoreB();
	Tinicial = (float)clock()/CLOCKS_PER_SEC;
	//busca em arvore binária
	for (i = 0; i < quantidade; i++) {
		buscaB = buscar_arvoreB(B, vetor[i]);
	}
	Tfinal = (float)clock()/CLOCKS_PER_SEC;
	Ttotal = Tfinal - Tinicial;
	printf("Tempo total para buscar na arvore B: %f\n", Ttotal);

    return 0;
}

