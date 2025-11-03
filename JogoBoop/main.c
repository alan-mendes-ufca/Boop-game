#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int qtde_gatinhosJogador1 = 8;
    int qtde_gatoJogador1 = 0;
    int qtde_gatinhosJogador2 = 8;
    int qtde_gatoJogador2 = 0;

    int gatosAtivosPlayer1 = 0;
    int gatosAtivosPlayer2 = 0;

    int jogadorAtual = 0;

    int *gatinhosJogadorAtual;
    int *gatoJogadorAtual;
    int *gatosAtivosJogadorAtual;

    int *gatinhosAdversario;
    int *gatoAdversario;

    int *gatinhosJogador1;
    int *gatoJogador1;
    int *gatinhosJogador2;
    int *gatoJogador2;

    int jogadaValida = 0, tamanhoTabuleiro = 6, turno = 0, jogoAtivo = 1;
    Celula ***tabuleiro;
    Estado **estado;
    char letrasColuna[] = "A          B          C          D          E          F", tipoPeca;
    int linha;
    char coluna, comando;

    // Preenche com ' '
    tabuleiro = inicializarTabuleiro(tamanhoTabuleiro, tamanhoTabuleiro);

    mostrarGato();

    while (jogoAtivo)
    {
        printf("\n");

        exibirTabuleiro(tabuleiro, tamanhoTabuleiro, tamanhoTabuleiro, letrasColuna, qtde_gatinhosJogador1, qtde_gatoJogador1, qtde_gatinhosJogador2, qtde_gatoJogador2);

        // Determina o jogador atual
        if (turno % 2 == 0)
        {
            jogadorAtual = 1;
            gatinhosJogadorAtual = &qtde_gatinhosJogador1;
            gatinhosAdversario = &qtde_gatinhosJogador2;
            gatoJogadorAtual = &qtde_gatoJogador1;
            gatoAdversario = &qtde_gatoJogador2;
            gatosAtivosJogadorAtual = &gatosAtivosPlayer1;
            printf("\033[31mÉ a vez do Jogador 1! Boa sorte!\033[0m\n");
        }
        else
        {
            jogadorAtual = 2;
            gatinhosJogadorAtual = &qtde_gatinhosJogador2;
            gatinhosAdversario = &qtde_gatinhosJogador1;
            gatoJogadorAtual = &qtde_gatoJogador2;
            gatoAdversario = &qtde_gatoJogador1;
            gatosAtivosJogadorAtual = &gatosAtivosPlayer2;
            printf("\033[34mJogador 2, é sua vez! Mostre seu talento!\033[0m\n");
        }

        gatinhosJogador1 = &qtde_gatinhosJogador1;
        gatoJogador1 = &qtde_gatoJogador1;
        gatinhosJogador2 = &qtde_gatinhosJogador2;
        gatoJogador2 = &qtde_gatoJogador2;

        do
        {
            printf("\nDigite o tipo de peça ('g' para gatinho, 'G' para gatão) e a coordenada (ex: g 1 A):\n");
            scanf(" %c %d %c", &tipoPeca, &linha, &coluna);

            // Ajusta entrada do jogador para os índices do tabuleiro
            linha--;
            int colunaIndex = coluna - 'A';

            jogadaValida = verificarJogadaValida(tabuleiro, linha, colunaIndex, tipoPeca, gatinhosJogadorAtual, gatoJogadorAtual);
            if (jogadaValida)
            {
                (*gatosAtivosJogadorAtual)++;

                fazBoop(tabuleiro, linha, colunaIndex, tamanhoTabuleiro, tamanhoTabuleiro,
                        gatinhosJogador1, gatoJogador1, gatinhosJogador2, gatoJogador2, tipoPeca, jogadorAtual, gatosAtivosJogadorAtual, jogadaValida);

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
