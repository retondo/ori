/* Este cabeçalho contém todas as funçẽos e bibliotecas necessárias para
 * geração de nomes de arquivos randômicos e etc */

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Define o intervalo de números randômicos
#define RAND 10000

// Gera arquivos .txt com nomes aleatórios
int gerador_nome_rand(void);
void criador_arquivo(int num);

#endif
