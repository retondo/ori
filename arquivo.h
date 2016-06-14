#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define RAND 10000                  // Define o intervalo de números randômicos

int gerador_nome_rand(void);        // Gera números aleatórios
void criador_arquivo(int num);      /* Gera uma pasta "arquivos" no diretório atual e arquivos txt,
                                    tendo como nomes os números gerados pela função gerador_nome_rand() */

#endif
