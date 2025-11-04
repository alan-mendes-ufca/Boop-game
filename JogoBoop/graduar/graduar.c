#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graduar.h"

// Função para graduar gatinhos em gatos
void graduar(
    Celula **tabuleiro, int linhas, int colunas,
    int *gatinhosJogadorAtual, int *gatosJogadorAtual,
    int *pecasAtivas)
{
    // Direções para busca: horizontal, vertical, diagonal principal, diagonal secundária
    int direcoes[4][2] = {
        {0, 1}, // Direita
        {1, 0}, // Para baixo
        {1, 1}, // Diagonal principal
        {-1, 1} // Diagonal secundária
    };

    // Lista de combinações de linhas de 3 encontradas
    int linhasEncontradas[100][3][2]; // Máximo de 100 combinações
    int numLinhasEncontradas = 0;

    // Percorre o tabuleiro para encontrar combinações de 3 peças
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            char pecaAtual = tabuleiro[i][j].gato;
            if (pecaAtual == 'g' || pecaAtual == 'G')
            {
                for (int d = 0; d < 4; d++)
                {
                    int linha1 = i + direcoes[d][0];
                    int coluna1 = j + direcoes[d][1];
                    int linha2 = i + 2 * direcoes[d][0];
                    int coluna2 = j + 2 * direcoes[d][1];

                    // Verifica se as posições estão dentro dos limites
                    if (linha1 >= 0 && linha1 < linhas && coluna1 >= 0 && coluna1 < colunas &&
                        linha2 >= 0 && linha2 < linhas && coluna2 >= 0 && coluna2 < colunas)
                    {
                        char peca1 = tabuleiro[linha1][coluna1].gato;
                        char peca2 = tabuleiro[linha2][coluna2].gato;
                        if ((peca1 == 'g' || peca1 == 'G') &&
                            (peca2 == 'g' || peca2 == 'G'))
                        {
                            // Adiciona a linha encontrada na lista
                            linhasEncontradas[numLinhasEncontradas][0][0] = i;
                            linhasEncontradas[numLinhasEncontradas][0][1] = j;
                            linhasEncontradas[numLinhasEncontradas][1][0] = linha1;
                            linhasEncontradas[numLinhasEncontradas][1][1] = coluna1;
                            linhasEncontradas[numLinhasEncontradas][2][0] = linha2;
                            linhasEncontradas[numLinhasEncontradas][2][1] = coluna2;
                            numLinhasEncontradas++;
                        }
                    }
                }
            }
        }
    }

    // Escolhe uma linha para graduar (por padrão, a primeira encontrada)
    if (numLinhasEncontradas > 0)
    {
        int (*linhaEscolhida)[2] = linhasEncontradas[0];

        // Remove as peças da linha do tabuleiro (colocando "na caixa")
        for (int k = 0; k < 3; k++)
        {
            int x = linhaEscolhida[k][0];
            int y = linhaEscolhida[k][1];
            tabuleiro[x][y].gato = ' ';
        }

        // Atualiza o número de peças ativas no tabuleiro
        *pecasAtivas -= 3;

        // Adiciona gatos adultos ao conjunto do jogador
        *gatosJogadorAtual += 3;

        // Garante que o jogador sempre tenha no máximo 8 peças ativas
        if (*pecasAtivas > 8)
        {
            *pecasAtivas = 8;
            *gatinhosJogadorAtual += 3; // Devolve os gatos extras à reserva
        }
    }
    if (*pecasAtivas > 8)
    {
        int excesso = *pecasAtivas - 8;

        // Prioriza devolver gatinhos ao conjunto
        if (excesso <= *gatinhosJogadorAtual)
        {
            *gatinhosJogadorAtual += excesso;
        }
        else
        {
            excesso -= *gatinhosJogadorAtual;
            *gatinhosJogadorAtual = 0;
            *gatosJogadorAtual += excesso; // O resto do excesso deve ser gatos
        }

        *pecasAtivas = 8; // Ajusta o número total de peças no tabuleiro
        printf("Ajustando peças ativas: excesso de %d peças removido.\n", excesso);
    }
    else if (*pecasAtivas == 8)
    {
        // Gradua automaticamente um gatinho para um gato
        if (*gatinhosJogadorAtual > 0)
        {
            (*gatinhosJogadorAtual)--;
            (*gatosJogadorAtual)++;
            printf("Um gatinho foi graduado para um gato!\n");
        }
        else
        {
            printf("Nenhum gatinho disponível para graduar.\n");
        }
    }
}

void graduarMultiplasLinhas(
    Celula **tabuleiro, int linhas, int colunas,
    int *gatinhosJogadorAtual, int *gatosJogadorAtual,
    int *pecasAtivas)
{

    // Direções: horizontal, vertical, diagonal principal, diagonal secundária
    int direcoes[4][2] = {
        {0, 1}, // Direita
        {1, 0}, // Para baixo
        {1, 1}, // Diagonal principal
        {-1, 1} // Diagonal secundária
    };

    // Armazena todas as combinações de linhas encontradas
    int linhasEncontradas[100][3][2]; // Máximo de 100 combinações de 3 peças
    int numLinhasEncontradas = 0;

    // Passo 1: Detectar todas as linhas de 3 peças
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            char pecaAtual = tabuleiro[i][j].gato;

            // Verifica apenas gatinhos ou gatos
            if (pecaAtual == 'g' || pecaAtual == 'G')
            {
                for (int d = 0; d < 4; d++)
                {
                    int linha1 = i + direcoes[d][0];
                    int coluna1 = j + direcoes[d][1];
                    int linha2 = i + 2 * direcoes[d][0];
                    int coluna2 = j + 2 * direcoes[d][1];

                    // Verifica se as posições estão dentro dos limites
                    if (linha1 >= 0 && linha1 < linhas && coluna1 >= 0 && coluna1 < colunas &&
                        linha2 >= 0 && linha2 < linhas && coluna2 >= 0 && coluna2 < colunas)
                    {

                        // Verifica se as peças são do mesmo tipo
                        if (tabuleiro[linha1][coluna1].gato == pecaAtual &&
                            tabuleiro[linha2][coluna2].gato == pecaAtual)
                        {

                            // Adiciona a linha encontrada à lista
                            linhasEncontradas[numLinhasEncontradas][0][0] = i;
                            linhasEncontradas[numLinhasEncontradas][0][1] = j;
                            linhasEncontradas[numLinhasEncontradas][1][0] = linha1;
                            linhasEncontradas[numLinhasEncontradas][1][1] = coluna1;
                            linhasEncontradas[numLinhasEncontradas][2][0] = linha2;
                            linhasEncontradas[numLinhasEncontradas][2][1] = coluna2;
                            numLinhasEncontradas++;
                        }
                    }
                }
            }
        }
    }

    // Passo 2: Processar as linhas encontradas
    for (int k = 0; k < numLinhasEncontradas; k++)
    {
        printf("Graduando linha %d: (%d, %d), (%d, %d), (%d, %d)\n",
               k + 1,
               linhasEncontradas[k][0][0], linhasEncontradas[k][0][1],
               linhasEncontradas[k][1][0], linhasEncontradas[k][1][1],
               linhasEncontradas[k][2][0], linhasEncontradas[k][2][1]);

        // Remove as peças da linha do tabuleiro
        for (int p = 0; p < 3; p++)
        {
            int x = linhasEncontradas[k][p][0];
            int y = linhasEncontradas[k][p][1];
            tabuleiro[x][y].gato = ' '; // Remove a peça
        }

        // Atualiza o número de peças ativas no tabuleiro
        *pecasAtivas -= 3;

        // Adiciona gatos adultos ao conjunto do jogador
        *gatosJogadorAtual += 3;

        // Garante que o jogador tenha no máximo 8 peças ativas
        if (*pecasAtivas > 8)
        {
            int excesso = *pecasAtivas - 8;
            *gatinhosJogadorAtual += excesso;
            *pecasAtivas = 8; // Ajusta o número total de peças
        }
    }
}

