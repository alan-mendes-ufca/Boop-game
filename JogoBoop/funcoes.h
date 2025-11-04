#ifndef FUNCOES_H
#define FUNCOES_H

// Definições de cores para texto
#define RED "\x1b[1;31m"  // Cor vermelha
#define BLUE "\x1b[1;34m" // Cor azul
#define RESET "\x1b[1;0m" // Reset para cor padrão

// Estrutura que representa uma célula do tabuleiro
typedef struct
{
    char gato;       // Tipo de peça ('g', 'G' ou ' ' para vazio)
    const char *cor; // String de cor ANSI (NULL se não houver cor)
} Celula;

// typedef struct
// {
//     int coordenadas[2][10];
//     char cor[10];
//     int turno;
//     int qtde_gatinhosJogador1;
//     int qtde_gatoJogador1;
//     int qtde_gatinhosJogador2;
//     int qtde_gatoJogador2;
//     int gatosAtivosPlayer1;
//     int gatosAtivosPlayer2;

//     Celula **tabuleiro;
//     int tamanhoTabuleiro;

// } Estado;

typedef struct
{
    int quantidadeGatinhos;
    int quantidadeGatos;
    int quantidadePecasAtivas;
} Jogador;

#endif // FUNCOES_H