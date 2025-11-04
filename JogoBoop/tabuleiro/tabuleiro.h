#ifndef TABULEIRO_H
#define TABULEIRO_H
#include "../funcoes.h"

void mostrarGato();
Celula **inicializarTabuleiro(int linhas, int colunas);
void liberarTabuleiro(Celula **tabuleiro, int linhas);
void exibirTabuleiro(Celula **tabuleiro, int linhas, int colunas, char *rotuloColunas, int gatinhosjogador1, int gataojogador1, int gatinhosjogador2, int gataojogador2);

#endif // TABULEIRO_H