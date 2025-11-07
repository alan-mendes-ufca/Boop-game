#ifndef JOGADA_H
#define JOGADA_H
# include "../funcoes.h"
int verificarJogada(Celula **tabuleiro, int linha, int coluna, char* tipoPeca,
                    int *gatinhosJogadorAtual, int *gatosJogadorAtual);

int posicaoValida(int linha, int coluna, int totalLinhas, int totalColunas);

void fazBoop(
    Celula **tabuleiro, int linha, int coluna, int totalLinhas, int totalColunas,
    int *gatinhosJogadorAtual, int *gataoJogadorAtual,
    int *gatinhosAdversario, int *gataoAdversario, char* tipoPeca, int Jogador, int *gatosAtivos, int playCorreta);

void aplicarBoop(Celula ***tabuleiro, int linha, int coluna, int direcaoLinha, int direcaoColuna,
                 int totalLinhas, int totalColunas, char* tipoPeca,
                 int *gatinhosJogador1, int *gatosJogador1,
                 int *gatinhosJogador2, int *gatosJogador2, int saltando, int *gatosAtivos);

#endif // JOGADA_H