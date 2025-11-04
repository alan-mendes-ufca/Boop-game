#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes.h"

int verificaVitoria(Celula **tabuleiro, int linhas, int colunas, int gatosNaCamaJogador1, int gatosNaCamaJogador2)
{
    // Regra 2: Verifica se todos os gatos de um jogador estão na cama
    if (gatosNaCamaJogador1 == 8)
        return 1; // Jogador 1 venceu
    if (gatosNaCamaJogador2 == 8)
        return 2; // Jogador 2 venceu

    // Regra 1: Verifica alinhamentos de três peças consecutivas
    // Direções: direita, baixo, diagonal principal, diagonal secundária
    int direcoes[4][2] = {
        {0, 1}, // Direita
        {1, 0}, // Para baixo
        {1, 1}, // Diagonal principal
        {-1, 1} // Diagonal secundária
    };

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            char pecaAtual = tabuleiro[i][j].gato;
            if (pecaAtual == 'g' || pecaAtual == 'G')
            {
                for (int d = 0; d < 4; d++)
                {
                    int x1 = i + direcoes[d][0];
                    int y1 = j + direcoes[d][1];
                    int x2 = i + 2 * direcoes[d][0];
                    int y2 = j + 2 * direcoes[d][1];

                    // Verifica se as posições estão dentro dos limites
                    if (x1 >= 0 && x1 < linhas && y1 >= 0 && y1 < colunas &&
                        x2 >= 0 && x2 < linhas && y2 >= 0 && y2 < colunas)
                    {
                        char peca1 = tabuleiro[x1][y1].gato;
                        char peca2 = tabuleiro[x2][y2].gato;

                        // Verifica alinhamento de três peças consecutivas
                        if (pecaAtual == peca1 && pecaAtual == peca2)
                        {
                            if (pecaAtual == 'g')
                                return 1; // Jogador 1 venceu
                            if (pecaAtual == 'G')
                                return 2; // Jogador 2 venceu
                        }
                    }
                }
            }
        }
    }

    // Sem vencedor
    return 0;
}

void verificarEmpate(Jogador jogador1, Jogador jogador2)
{
    if (jogador1.quantidadeGatinhos == 0 && jogador1.quantidadeGatos == 0 &&
        jogador2.quantidadeGatinhos == 0 && jogador2.quantidadeGatos == 0)
    {
        printf("O jogo terminou em empate! Ambos os jogadores ficaram sem peças.\n");
        exit(0); // Encerra o programa
    }
}