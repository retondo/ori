/* Este cabeçalho contém todas as funçẽos e bibliotecas necessárias para
 * geração de nomes de arquivos randômicos e etc */

#ifndef ARQUIVOS_H_
#define ARQUIVOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define o intervalo de números randômicos
#define RRAND 10000

// Gera arquivos .txt com nomes aleatórios
void gerador_arquivos(int quantidade);
int gerador_nome_rand(void);
int criador_arquivo(int num);
#endif
