#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "funcoes.h"
#include "graduar/graduar.h"
#include "jogada/jogada.h"
#include "tabuleiro/tabuleiro.h"
#include "vitoria/vencer.h"

int tamanhoTabuleiro = 6;

void get_input(char *tipoPeca, int *linha, char *coluna);

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
    tabuleiro = inicializarTabuleiro(tamanhoTabuleiro, tamanhoTabuleiro);

    mostrarGato();

    while (jogoAtivo)
    {
        Jogador *atual = (turno % 2 == 0) ? &jogador1 : &jogador2;
        printf("\n");
        exibirTabuleiro(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro, "A          B          C          D          E          F", jogador1.quantidadeGatinhos,
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

        fazBoop(tabuleiro, linha, colunaIndex, tamanhoTabuleiro, tamanhoTabuleiro, &jogador1.quantidadeGatinhos, &jogador1.quantidadeGatos, &jogador2.quantidadeGatinhos, &jogador2.quantidadeGatos,
                tipoPeca, (turno % 2 == 0) ? 1 : 2, &atual->quantidadePecasAtivas, jogadaValida);

        graduar(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro,
                &atual->quantidadeGatinhos, &atual->quantidadeGatos,
                &atual->quantidadePecasAtivas);

        graduarMultiplasLinhas(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro,
                               &atual->quantidadeGatinhos, &atual->quantidadeGatos,
                               &atual->quantidadePecasAtivas);

        int vencedor = verificaVitoria(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro, jogador1.quantidadePecasAtivas, jogador2.quantidadePecasAtivas);
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

        if (jogador1.quantidadeGatinhos == 0 && jogador1.quantidadeGatos == 0 &&
            jogador2.quantidadeGatinhos == 0 && jogador2.quantidadeGatos == 0)
        {
            printf("\033[33mEmpate! Todos os gatinhos e gatões se foram.\033[0m\n");
            jogoAtivo = 0;
        }

        turno++;
    }
}

void get_input(char *tipoPeca, int *linha, char *coluna)
{
    printf("\nDigite o tipo de peça ('g' para gatinho, 'G' para gatão) e a coordenada (ex: g 1 A):\n");
    scanf(" %c %d %c", tipoPeca, linha, coluna);
}
