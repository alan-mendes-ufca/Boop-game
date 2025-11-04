#include <stdio.h>
#include "funcoes.h"
#include "jogada/jogada.h"
#include "graduar/graduar.h"

void get_input(char *tipoPeca, int *linha, char *coluna)
{
    printf("\nDigite o tipo de peça ('g' para gatinho, 'G' para gatão) e a coordenada (ex: g 1 A):\n");
    scanf(" %c %d %c", tipoPeca, linha, coluna);
}

void fluxoJogo(Celula **tabuleiro, int linha, int colunaIndex, char tipoPeca,
                Jogador jogador1, Jogador jogador2,
                Jogador *atual, int turno, int jogadaValida)
{
    fazBoop(tabuleiro, linha, colunaIndex, tamanhoTabuleiro, tamanhoTabuleiro, &jogador1.quantidadeGatinhos, &jogador1.quantidadeGatos, &jogador2.quantidadeGatinhos, &jogador2.quantidadeGatos,
            tipoPeca, (turno % 2 == 0) ? 1 : 2, &atual->quantidadePecasAtivas, jogadaValida);

    graduar(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro,
            &atual->quantidadeGatinhos, &atual->quantidadeGatos,
            &atual->quantidadePecasAtivas);

    graduarMultiplasLinhas(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro,
                           &atual->quantidadeGatinhos, &atual->quantidadeGatos,
                           &atual->quantidadePecasAtivas);
}