#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void mostrarGato()
{

    printf("\033[1;33m"); // Cor amarela (negrito)

    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⠿⠉⠀⠀⠀⠀⠀⠹⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⡿⠛⠉⠁⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣷⣶⣶⣦⣤⣤⣄⣤⡀⣀⣩⣾⣿⠿⠋⠀⠀⠀⠀⠀⣠\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⠟⠋⠉⠉⠙⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⢀⡾⠁\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠁⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⡇⠁⠀⠀⠀⢀⣴⣿⣿⣿⣿⡏⠋⠀⠀⠀⠀⠀⠀⠀⡞⠋⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣼⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡏⠀⠀⠀⠀⣶⣿⣿⣿⣿⡿⠉⠀⠀⠀⠀⠀⠀⠀⠀⢸⡯⠤⣤\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣿⣿⣿⡏⠀⠀⠀⠀⣼⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠁\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣄⣄⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡿⠋⠀⠀⠀⠀⣼⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢷⣄\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀⠀⠀⠀⣾⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⣠⣶⣶⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻\n");
    printf("⠀⠀⠀⠀⠀⠀⢀⣾⠿⠛⢿⣿⣷⣄⡀⣿⠋⠀⠈⠀⠀⠀⠀⠀⠀⠀⢀⣾⡏⠀⢹⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⣠⣤⣦⣼⣿⠀⠀⠀⣿⣿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⢀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣾⣿⣿⣿⢷⣄⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⣠⣾⡿⠋⠉⠉⠁⠀⠀⠀⠀⠉⢯⡙⠻⣿⣿⣷⣤⡀⠀⠀⠀⠀⢿⣿⣿⣿⣿⡿⠃⢀⡤⠖⠋⣉⣉⣉⣉⠉⠉⠒⠦⣄⠀⠀⠀⢔⡟⡿⠟⠉⣟⣻⣮⣿⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⣾⣿⠋⠀⠀⠀⠀⣀⣀⡀⠀⠀⠀⠀⠙⢦⣄⠉⠻⢿⣿⣷⣦⡀⠀⠈⠙⠛⠛⠋⠀⢰⠟⠁⠀⠀⠈⠻⡿⠛⠁⠀⠀⠀⠈⠳⣄⠀⠸⣧⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⣿⡇⠀⠀⠀⣴⠙⣩⣿⣿⣄⠀⠀⠀⠀⡶⢌⡙⠶⣤⡈⠛⠿⣿⣷⣦⣀⠀⠀⠀⠀⡇⠀⢰⣄⠀⠀⣠⢷⠀⠀⠀⠀⠀⠀⠀⠘⡆⠀⠀⠻⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⣿⡇⠀⠀⢸⣇⢸⣿⣿⣿⣿⠀⠀⠀⠀⡇⠀⠈⠛⠦⣝⡳⢤⣈⠛⠻⣿⣷⣦⣀⠀⠀⠀⠀⠈⠙⠋⠁⠀⠛⠦⢤⡤⠀⠀⠀⠀⢳⠀⠀⠀⠈⠋⠙⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⣿⡇⠀⠀⠈⢿⣄⣿⣿⣿⠏⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠙⠳⢬⣛⠦⠀⠙⢻⣿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⣿⡇⠀⠀⠀⠀⠉⠛⠋⠁⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠈⣿⠉⢻⣿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⣿⡇⠀⠀⠀⠀⠀⣠⣄⠀⠀⢰⠶⠒⠒⢧⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⢸⡇⢸⡇⠀⣿⠙⣿⣿⣉⠉⠙⠿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

    printf("\033[0m"); // Resetando a cor

    printf("\nPressione Enter para continuar...");
    getchar();

    printf("\nContinuando...\n");

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

Celula **inicializarTabuleiro(int linhas, int colunas)
{
    /*
    Alocando memória para um ponteiro de ponteiros (matriz 2D), 
    onde cada ponteiro aponta para uma linha.
    */
    Celula **tabuleiro = malloc(linhas * sizeof(Celula *));

    for (int i = 0; i < linhas; i++)
    {
        // Alocando memória para cada linha da matriz
        tabuleiro[i] = malloc(colunas * sizeof(Celula));

        // Inicializando cada célula do tabuleiro
        for (int j = 0; j < colunas; j++)
        {
            tabuleiro[i][j].gato = ' '; // Inicializa como vazio
            tabuleiro[i][j].cor = NULL; // Sem cor inicial
        }
    }
    return tabuleiro;
}

void liberarTabuleiro(Celula **tabuleiro, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(tabuleiro[i]); // Libera cada linha
    }
    free(tabuleiro); // Libera o ponteiro para as linhas
}

void exibirTabuleiro(Celula **tabuleiro, int linhas, int colunas, char *rotuloColunas, int gatinhosjogador1, int gataojogador1, int gatinhosjogador2, int gataojogador2)
{
    printf("      %s\n", rotuloColunas);
    for (int i = 0; i < linhas; i++)
    {
        printf("%d|", i + 1); // Rótulo das linhas

        for (int j = 0; j < colunas; j++)
        {
            // Aplica a cor se a célula tiver uma cor
            if (tabuleiro[i][j].cor != NULL)
            {
                printf("%s", tabuleiro[i][j].cor);
            }

            if (tabuleiro[i][j].gato == 'g')
            {
                printf("≽^-˕-^≼   ");
            }
            else if (tabuleiro[i][j].gato == 'G')
            {
                printf("/ᐠ - ˕ -マ");
            }
            else if (tabuleiro[i][j].gato == ' ')
            {
                printf("          ");
            }

            // Reseta a cor após cada célula
            printf("\x1b[0m|");
        }
        printf("\n");
    }
    printf("\n");
    printf("\033[31mGatinhos Jogador 1: %d\033[0m\t", gatinhosjogador1);
    printf("\033[31mGatão Jogador 1: %d\033[0m\t", gataojogador1);
    printf("\n\033[34mGatinhos Jogador 2: %d\033[0m\t", gatinhosjogador2);
    printf("\033[34mGatão Jogador 2: %d\033[0m\t", gataojogador2);
    printf("\n");
    printf("\n");
}

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
    if (linha < 0 || linha >= 7 || coluna < 0 || coluna >= 7)
    {
        return 0; // Posição fora dos limites
    }

    if (tabuleiro[linha][coluna].gato == ' ')
    {                           // Dereferenciando
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

    return 0;
}

// Função auxiliar para verificar se uma posição está dentro dos limites do tabuleiro
int posicaoValida(int linha, int coluna, int totalLinhas, int totalColunas)
{
    return linha >= 0 && linha < totalLinhas && coluna >= 0 && coluna < totalColunas;
}

void aplicarBoop(Celula ***tabuleiro, int linha, int coluna, int direcaoLinha, int direcaoColuna,
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

    if (tabuleiro[proxLinha][proxColuna]->gato == ' ')
    {
        return;
    }

    // Gatinhos não empurram gatos
    if (tipoPeca == 'g' && tabuleiro[proxLinha][proxColuna]->gato == 'G')
    {
        return;
    }

    // Calcula a posição anterior ao boop
    int anteriorLinha = linha - direcaoLinha;
    int anteriorColuna = coluna - direcaoColuna;

    // Verifica se a posição anterior está detnro do limite e se forma um trio para graduar
    if (posicaoValida(anteriorLinha, anteriorColuna, totalLinhas, totalColunas) &&
        tabuleiro[anteriorLinha][anteriorColuna] != NULL &&
        tabuleiro[anteriorLinha][anteriorColuna]->gato == tabuleiro[proxLinha][proxColuna]->gato)
    {
        return; // Três peças alinhadas para graduar
    }

    // Calcula a posição seguinte para o boop
    int novaLinha = proxLinha + direcaoLinha;
    int novaColuna = proxColuna + direcaoColuna;

    // Verifica se a nova posição é válida
    if (posicaoValida(novaLinha, novaColuna, totalLinhas, totalColunas))
    {

        if (tabuleiro[novaLinha][novaColuna]->gato == ' ')
        {

            // Move a peça empurrada
            tabuleiro[novaLinha][novaColuna]->gato = tabuleiro[proxLinha][proxColuna]->gato;
            tabuleiro[novaLinha][novaColuna]->cor = tabuleiro[proxLinha][proxColuna]->cor;

            // Limpa a célula anterior
            tabuleiro[proxLinha][proxColuna]->gato = ' ';
            tabuleiro[proxLinha][proxColuna]->cor = NULL;

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

        char gatoRemovido = tabuleiro[proxLinha][proxColuna]->gato;
        const char *corRemovida = tabuleiro[proxLinha][proxColuna]->cor;

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

        tabuleiro[proxLinha][proxColuna]->gato = ' ';
        tabuleiro[proxLinha][proxColuna]->cor = NULL;
    }
}

void fazBoop(
    Celula ***tabuleiro, int linha, int coluna, int totalLinhas, int totalColunas,
    int *gatinhosJogadorAtual, int *gataoJogadorAtual,
    int *gatinhosAdversario, int *gataoAdversario, char tipoPeca, int Jogador, int *gatosAtivos, int playCorreta)
{
    // Verifica jogada válida e atualiza o tabuleiro
    if (playCorreta)
    {
        tabuleiro[linha][coluna]->gato = tipoPeca;
        tabuleiro[linha][coluna]->cor = (Jogador == 1) ? RED : BLUE;
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

//
void graduar(
    Celula ***tabuleiro, int linhas, int colunas,
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
            char pecaAtual = tabuleiro[i][j]->gato;
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
                        char peca1 = tabuleiro[linha1][coluna1]->gato;
                        char peca2 = tabuleiro[linha2][coluna2]->gato;
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
        int(*linhaEscolhida)[2] = linhasEncontradas[0];

        // Remove as peças da linha do tabuleiro (colocando "na caixa")
        for (int k = 0; k < 3; k++)
        {
            int x = linhaEscolhida[k][0];
            int y = linhaEscolhida[k][1];
            tabuleiro[x][y]->gato = ' ';
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
    Celula ***tabuleiro, int linhas, int colunas,
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
            char pecaAtual = tabuleiro[i][j]->gato;

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
                        if (tabuleiro[linha1][coluna1]->gato == pecaAtual &&
                            tabuleiro[linha2][coluna2]->gato == pecaAtual)
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
            tabuleiro[x][y]->gato = ' '; // Remove a peça
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

int verificaVitoria(Celula ***tabuleiro, int linhas, int colunas, int gatosNaCamaJogador1, int gatosNaCamaJogador2)
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
            char pecaAtual = tabuleiro[i][j]->gato;
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
                        char peca1 = tabuleiro[x1][y1]->gato;
                        char peca2 = tabuleiro[x2][y2]->gato;

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

