#include "arquivo.h"
#include "binaria.h"
#include "avl.h"
#include <locale.h>

int main(void) {
	int indice, quantidade, i;

    // Define a língua portuguesa como padrão
    setlocale(LC_ALL, "Portuguese");

	printf("Forneça a quantidade de arquivos a serem criados: ");
	scanf("%d", &quantidade);

    srand(time(NULL));

    /* Teste para árvore binária */
    no_bin *arvore = NULL;
	for (i = 0; i < quantidade; i++) {
		indice = gerador_nome_rand();
		criador_arquivo(indice);
        arvore = arv_bin_inserir(arvore, indice);
	}
    arv_bin_imprimir(arvore);
    no_bin *busca = arv_bin_buscar(arvore, indice);
    printf("O nó buscado é: %d\n", busca->info);

    return 0;
}

