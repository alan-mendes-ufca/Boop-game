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

typedef struct
{
    int coordenadas[2][10];
    char cor[10];
    int turno;
    int qtde_gatinhosJogador1;
    int qtde_gatoJogador1;
    int qtde_gatinhosJogador2;
    int qtde_gatoJogador2;
    int gatosAtivosPlayer1;
    int gatosAtivosPlayer2;

    Celula ***tabuleiro;
    int tamanhoTabuleiro;

} Estado;

// Função que exibe arte ASCII de um gato
void mostrarGato();

// Inicializa o tabuleiro com células vazias
Celula ***inicializarTabuleiro(int linhas, int colunas);

// Exibe o tabuleiro no console com rótulos de linha e coluna
void exibirTabuleiro(Celula ***tabuleiro, int linhas, int colunas, char *rotuloColunas,
                     int gatinhosjogador1, int gataojogador1, int gatinhosjogador2, int gataojogador2);

// Verifica se uma jogada em uma posição específica é válida
int verificarJogadaValida(Celula ***tabuleiro, int linha, int coluna, char tipoPeca,
                          int *gatinhosJogadorAtual, int *gataoJogadorAtual);

// Executa uma jogada e aplica o efeito "boop"
void fazBoop(Celula ***tabuleiro, int linha, int coluna, int totalLinhas, int totalColunas,
             int *gatinhosJogadorAtual, int *gataoJogadorAtual,
             int *gatinhosAdversario, int *gataoAdversario, char tipoPeca, int Jogador, int *gatosAtivos, int playCorreta);

// Aplica o movimento "boop" em uma direção específica
void aplicarBoop(Celula ***tabuleiro, int linha, int coluna, int direcaoLinha, int direcaoColuna,
                 int totalLinhas, int totalColunas, char tipoPeca,
                 int *gatinhosJogadorAtual, int *gataoJogadorAtual,
                 int *gatinhosAdversario, int *gataoAdversario, int saltando, int *gatosAtivos);

// Realiza a graduação dos gatinhos em gatões quando aplicável
void graduar(Celula ***tabuleiro, int linhas, int colunas,
             int *gatinhosJogadorAtual, int *gatosJogadorAtual,
             int *pecasAtivas);

void graduarMultiplasLinhas(
    Celula ***tabuleiro, int linhas, int colunas,
    int *gatinhosJogadorAtual, int *gatosJogadorAtual,
    int *pecasAtivas);

// Verifica se houve uma vitória no jogo
int verificaVitoria(Celula ***tabuleiro, int linhas, int colunas, int gatosNaCamaJogador1, int gatosNaCamaJogador2);
void salvarEstado(const char *nomeArquivo, Estado *estado);
int carregarEstado(const char *nomeArquivo, Estado *estado);
void menuSalvarJogo(Estado *estado);
int menuPausa(Estado *estado);
#endif
