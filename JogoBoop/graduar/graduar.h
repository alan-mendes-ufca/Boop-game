#ifndef GRADUAR_H
#define GRADUAR_H   

#include "JogoBoop/funcoes.h"
// Realiza a graduação dos gatinhos em gatos quando aplicável
void graduar(Celula ***tabuleiro, int linhas, int colunas,
             int *gatinhosJogadorAtual, int *gatosJogadorAtual,
             int *pecasAtivas);

void graduarMultiplasLinhas(
    Celula ***tabuleiro, int linhas, int colunas,
    int *gatinhosJogadorAtual, int *gatosJogadorAtual,
    int *pecasAtivas);


#endif
