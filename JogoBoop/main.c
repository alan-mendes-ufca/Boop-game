#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "funcoes.h"
#include "graduar/graduar.h"
#include "jogada/jogada.h"
#include "tabuleiro/tabuleiro.h"
#include "vitoria/vencer.h"

int main()
{
    // Configura a localidade para suportar caracteres especiais
    setlocale(LC_ALL, "Portuguese");

    Jogador jogador1 = {8, 0, 0};
    Jogador jogador2 = {8, 0, 0};

    Celula **tabuleiro;
    char tipoPeca;
    int linha, colunaIndex;
    char coluna;

    int turno = 0, jogoAtivo = 1, jogadaValida = 1;

    // Preenche com ' '
    tabuleiro = inicializarTabuleiro(TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);

    mostrarGato();

    while (jogoAtivo)
    {
        Jogador *atual = (turno % 2 == 0) ? &jogador1 : &jogador2;
        printf("\n");
        exibirTabuleiro(tabuleiro, TAMANHO_TABULEIRO, TAMANHO_TABULEIRO, "A          B          C          D          E          F", jogador1.quantidadeGatinhos,
                        jogador1.quantidadeGatos, jogador2.quantidadeGatinhos, jogador2.quantidadeGatos, (turno % 2) + 1);

        do
        {
            get_input(&tipoPeca, &linha, &coluna);

            // Ajusta entrada do jogador para os índices do tabuleiro
            linha--;
            colunaIndex = coluna - 'A';

            jogadaValida = verificarJogada(tabuleiro, linha, colunaIndex, tipoPeca,
                                           &atual->quantidadeGatinhos, &atual->quantidadeGatos);

        } while (!jogadaValida);

        atual->quantidadePecasAtivas++;

        fluxoJogo(tabuleiro, linha, colunaIndex, tipoPeca,
                   jogador1, jogador2,
                   atual, turno, jogadaValida);

        int vencedor = verificaVitoria(tabuleiro, TAMANHO_TABULEIRO, TAMANHO_TABULEIRO, jogador1.quantidadePecasAtivas, jogador2.quantidadePecasAtivas);
        if (vencedor == 1)
        {
            printf("Jogador 1 venceu!\n");
            break;
        }
        else if (vencedor == 2)
        {
            printf("Jogador 2 venceu!\n");
            break;
        }

        verificarEmpate(jogador1, jogador2);
        turno++;
    }
}
