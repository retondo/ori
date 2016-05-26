#include "arquivo.h"

// Gera nome (números) de forma randômica com base no tempo
int gerador_nome_rand(void) {
    return (rand()%RRAND);
}

int criador_arquivo(int num) {
	char nome[10];
	sprintf(nome, "%d", num);
	strcat(nome, ".txt");
	FILE *arquivo;
	arquivo = fopen(nome, "w");
	return 0;
}
