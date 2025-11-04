#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes.h"

int verificarJogada(Celula **tabuleiro, int linha, int coluna, char tipoPeca,
                    int *gatinhosJogadorAtual, int *gataoJogadorAtual)
{
    // Verifica se o tipo de peça é válido
    if (tipoPeca != 'g' && tipoPeca != 'G')
    {
        printf("Tipo de peça inválido! Use 'g' para gatinho ou 'G' para gatão.\n");
        return 0;
    }

    // Verifica se a posição está dentro dos limites do tabuleiro
    if (linha < 0 || linha >= 7 || coluna < 0 || coluna >= 6)
    {
        printf("\033[33mPosição fora dos limites do tabuleiro!\033[0m\n");
        printf("\033[33mVerificando posição: linha %d, coluna %d\033[0m\n", linha+1, coluna+1);
        return 0; // Posição fora dos limites
    }

    if (tabuleiro[linha][coluna].gato == ' ')
    { // Dereferenciando
        if (tipoPeca == 'g' && *gatinhosJogadorAtual > 0)
        {
            (*gatinhosJogadorAtual)--;
            return 1;
        }
        else if (tipoPeca == 'G' && *gataoJogadorAtual > 0)
        {
            (*gataoJogadorAtual)--;
            return 1;
        }
    }

    printf("Jogada inválida! Célula ocupada ou peças insuficientes.\n");
    return 0;
}

// Função auxiliar para verificar se uma posição está dentro dos limites do tabuleiro
int posicaoValida(int linha, int coluna, int totalLinhas, int totalColunas)
{
    return linha >= 0 && linha < totalLinhas && coluna >= 0 && coluna < totalColunas;
}

void aplicarBoop(Celula **tabuleiro, int linha, int coluna, int direcaoLinha, int direcaoColuna,
                 int totalLinhas, int totalColunas, char tipoPeca,
                 int *gatinhosJogador1, int *gatoJogador1,
                 int *gatinhosJogador2, int *gatoJogador2, int saltando, int *gatosAtivos)
{
    // Calcula a posição adjacente
    int proxLinha = linha + direcaoLinha;
    int proxColuna = coluna + direcaoColuna;

    if (!posicaoValida(proxLinha, proxColuna, totalLinhas, totalColunas))
    {
        return;
    }

    if (tabuleiro[proxLinha][proxColuna].gato == ' ')
    {
        return;
    }

    // Gatinhos não empurram gatos
    if (tipoPeca == 'g' && tabuleiro[proxLinha][proxColuna].gato == 'G')
    {
        return;
    }

    // Calcula a posição anterior ao boop
    int anteriorLinha = linha - direcaoLinha;
    int anteriorColuna = coluna - direcaoColuna;

    // Verifica se a posição anterior está detnro do limite e se forma um trio para graduar
    if (posicaoValida(anteriorLinha, anteriorColuna, totalLinhas, totalColunas) &&
        tabuleiro[anteriorLinha][anteriorColuna].gato != ' ' &&
        tabuleiro[anteriorLinha][anteriorColuna].gato == tabuleiro[proxLinha][proxColuna].gato)
    {
        return; // Três peças alinhadas para graduar
    }

    // Calcula a posição seguinte para o boop
    int novaLinha = proxLinha + direcaoLinha;
    int novaColuna = proxColuna + direcaoColuna;

    // Verifica se a nova posição é válida
    if (posicaoValida(novaLinha, novaColuna, totalLinhas, totalColunas))
    {

        if (tabuleiro[novaLinha][novaColuna].gato == ' ')
        {

            // Move a peça empurrada
            tabuleiro[novaLinha][novaColuna].gato = tabuleiro[proxLinha][proxColuna].gato;
            tabuleiro[novaLinha][novaColuna].cor = tabuleiro[proxLinha][proxColuna].cor;

            // Limpa a célula anterior
            tabuleiro[proxLinha][proxColuna].gato = ' ';
            tabuleiro[proxLinha][proxColuna].cor = NULL;

            return;
        }
        // Não se boopa peças que estão lado a lado
        else
        {
            return;
        }
    }
    else
    {

        // Retorna boopada para fora do limite ao inventário

        char gatoRemovido = tabuleiro[proxLinha][proxColuna].gato;
        const char *corRemovida = tabuleiro[proxLinha][proxColuna].cor;

        if (gatoRemovido == 'g')
        {
            if (corRemovida == RED)
                (*gatinhosJogador1)++;
            else if (corRemovida == BLUE)
                (*gatinhosJogador2)++;
        }
        else if (gatoRemovido == 'G')
        {
            if (corRemovida == RED)
                (*gatoJogador1)++;
            else if (corRemovida == BLUE)
                (*gatoJogador2)++;
        }

        (*gatosAtivos)--;

        tabuleiro[proxLinha][proxColuna].gato = ' ';
        tabuleiro[proxLinha][proxColuna].cor = NULL;
    }
}

void fazBoop(
    Celula **tabuleiro, int linha, int coluna, int totalLinhas, int totalColunas,
    int *gatinhosJogadorAtual, int *gataoJogadorAtual,
    int *gatinhosAdversario, int *gataoAdversario, char tipoPeca, int Jogador, int *gatosAtivos, int playCorreta)
{
    // Verifica jogada válida e atualiza o tabuleiro
    if (playCorreta)
    {
        tabuleiro[linha][coluna].gato = tipoPeca;
        tabuleiro[linha][coluna].cor = (Jogador == 1) ? RED : BLUE;
    }
    // O vetor direcoes é um vetor bidimensional (ou matriz 2D).
    // Ele armazena pares de valores que representam as mudanças de linha e coluna para cada direção possível no tabuleiro.

    int direcoes[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    // Aplica boop em todas as direções
    for (int i = 0; i < 8; i++)
    {
        // direcoes[i][0] é o direcaoLinha
        // direcoes[i][1] é o direcaoColuna
        aplicarBoop(tabuleiro, linha, coluna, direcoes[i][0], direcoes[i][1],
                    totalLinhas, totalColunas, tipoPeca,
                    gatinhosJogadorAtual, gataoJogadorAtual, gatinhosAdversario, gataoAdversario, 0, gatosAtivos);
    }
}