#include "arquivo.h"

// Gera nome (números) de forma randômica com base no tempo
int gerador_nome_rand(void) {
    return (rand()%RAND);
}

void criador_arquivo(int num) {
	char nome[10];
	char diretorio[12] = "./arquivos/";
	struct stat st = {0};

	sprintf(nome, "%d", num);
	strcat(nome, ".txt");
	strcat(diretorio, nome);

	if (stat("./arquivos/", &st) == -1) 
		mkdir("./arquivos/", 0700);

    FILE *arquivo;
	arquivo = fopen(diretorio, "w");

	fprintf(arquivo, "Conteudo do arquivo %s\n", nome);
	fclose(arquivo);
}
