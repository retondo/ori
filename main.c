#include "arquivo.h"
#include "binaria.h"
#include "avl.h"
#include "arvoreB.h"
#include <locale.h>

int main(void) {
	int indice, quantidade, i;
	arvoreB B;
	B = criar_arvoreB();

    // Define a língua portuguesa como padrão
    setlocale(LC_ALL, "Portuguese");

	printf("Forneça a quantidade de arquivos a serem criados: ");
	scanf("%d", &quantidade);

    srand(time(NULL));

    /* Teste para árvore binária */
    //no_bin *arvore = NULL;
	for (i = 0; i < quantidade; i++) {
		indice = gerador_nome_rand();
		printf("indice= %d\n", indice);
		criador_arquivo(indice);
        //arvore = arv_bin_inserir(arvore, indice);
		inserir_arvoreB(B, indice);
	}
    //arv_bin_imprimir(arvore);
	puts("\n\n\n");
	imprimir_arvoreB(B);
	
    //no_bin *busca = arv_bin_buscar(arvore, indice);
    //printf("O nó buscado é: %d\n", busca->info);
    arvoreB buscaB;
    buscaB = criar_arvoreB();
    buscaB = buscar_arvoreB(B, indice);
    printf("O nó buscado é: %d\n", buscaB->keys[0]);

    return 0;
}

