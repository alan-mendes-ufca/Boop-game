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
    
    Jogador jogador1 = {8, 0};
    Jogador jogador2 = {8, 0};

    int gatosAtivosPlayer1 = 0, gatosAtivosPlayer2 = 0, jogadorAtual = 0;

    int *gatinhosJogadorAtual, *gatoJogadorAtual, *gatosAtivosJogadorAtual, *gatinhosAdversario, *gatoAdversario,
    *gatinhosJogador1, *gatoJogador1, *gatinhosJogador2, *gatoJogador2;

    int jogadaValida = 0, tamanhoTabuleiro = 6, turno = 0, jogoAtivo = 1;

    Celula **tabuleiro;
    Estado **estado;
    char letrasColuna[] = "A          B          C          D          E          F"; 
    char tipoPeca;
    int linha;
    char coluna, comando;

    // Preenche com ' '
    tabuleiro = inicializarTabuleiro(tamanhoTabuleiro, tamanhoTabuleiro);

    mostrarGato();

    while (jogoAtivo)
    {
        printf("\n");
        exibirTabuleiro(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro, letrasColuna, jogador1.quantidadeGatinhos, 
            jogador1.quantidadeGatos, jogador2.quantidadeGatinhos, jogador2.quantidadeGatos);

        Jogador *atual = (turno % 2 == 0) ? jogador1 : jogador2;
        
        do
        {
            printf("\nDigite o tipo de peça ('g' para gatinho, 'G' para gatão) e a coordenada (ex: g 1 A):\n");
            scanf(" %c %d %c", &tipoPeca, &linha, &coluna);

            // Ajusta entrada do jogador para os índices do tabuleiro
            linha--;
            int colunaIndex = coluna - 'A';

            jogadaValida = verificarJogada(tabuleiro, linha, colunaIndex, tipoPeca, 
                                           &atual->quantidadeGatinhos, &atual->quantidadeGatos);
                                           
            if (jogadaValida)
            {
                (*gatosAtivosJogadorAtual)++;

                fazBoop(tabuleiro, linha, colunaIndex, tamanhoTabuleiro, tamanhoTabuleiro, &jogador1.quantidadeGatinhos, &jogador1.quantidadeGatos, &jogador2.quantidadeGatinhos, &jogador2.quantidadeGatos,
                        tipoPeca, (turno%2==0)? 1 : 2, gatosAtivosJogadorAtual, jogadaValida);

                graduar(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro,
                        gatinhosJogadorAtual, gatoJogadorAtual,
                        gatosAtivosJogadorAtual);

                graduarMultiplasLinhas(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro,
                                       gatinhosJogadorAtual, gatoJogadorAtual,
                                       gatosAtivosJogadorAtual);

                int vencedor = verificaVitoria(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro, gatosAtivosPlayer1, gatosAtivosPlayer2);
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
            }
            else
            {
                printf("\033[33mJogada inválida! Posição indisponível ou qtde de peças inválida.\033[0m\n");
                printf("\033[33m A entrada não pode ser letras minúsculas!! \033[0m\n");
            }
        } while (!jogadaValida);

        if (*gatinhosJogadorAtual == 0 && *gatoJogadorAtual == 0 &&
            *gatinhosAdversario == 0 && *gatoAdversario == 0)
        {
            printf("\033[33mEmpate! Todos os gatinhos e gatões se foram.\033[0m\n");
            jogoAtivo = 0;
        }

        turno++;

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
}
