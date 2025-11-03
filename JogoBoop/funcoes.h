#ifndef FUNCOES_H
#define FUNCOES_H

// Defini��es de cores para texto
#define RED "\x1b[1;31m"  // Cor vermelha
#define BLUE "\x1b[1;34m" // Cor azul
#define RESET "\x1b[1;0m" // Reset para cor padr�o

// Estrutura que representa uma c�lula do tabuleiro
typedef struct
{
    char gato;       // Tipo de pe�a ('g', 'G' ou ' ' para vazio)
    const char *cor; // String de cor ANSI (NULL se n�o houver cor)
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

// Fun��o que exibe arte ASCII de um gato
void mostrarGato();

// Inicializa o tabuleiro com c�lulas vazias
Celula **inicializarTabuleiro(int linhas, int colunas);

// Exibe o tabuleiro no console com r�tulos de linha e coluna
void exibirTabuleiro(Celula ***tabuleiro, int linhas, int colunas, char *rotuloColunas,
                     int gatinhosjogador1, int gataojogador1, int gatinhosjogador2, int gataojogador2);

// Verifica se uma jogada em uma posi��o espec�fica � v�lida
int verificarJogadaValida(Celula ***tabuleiro, int linha, int coluna, char tipoPeca,
                          int *gatinhosJogadorAtual, int *gataoJogadorAtual);

// Executa uma jogada e aplica o efeito "boop"
void fazBoop(Celula ***tabuleiro, int linha, int coluna, int totalLinhas, int totalColunas,
             int *gatinhosJogadorAtual, int *gataoJogadorAtual,
             int *gatinhosAdversario, int *gataoAdversario, char tipoPeca, int Jogador, int *gatosAtivos, int playCorreta);

// Aplica o movimento "boop" em uma dire��o espec�fica
void aplicarBoop(Celula ***tabuleiro, int linha, int coluna, int direcaoLinha, int direcaoColuna,
                 int totalLinhas, int totalColunas, char tipoPeca,
                 int *gatinhosJogadorAtual, int *gataoJogadorAtual,
                 int *gatinhosAdversario, int *gataoAdversario, int saltando, int *gatosAtivos);

// Realiza a gradua��o dos gatinhos em gat�es quando aplic�vel
void graduar(Celula ***tabuleiro, int linhas, int colunas,
             int *gatinhosJogadorAtual, int *gatosJogadorAtual,
             int *pecasAtivas);

void graduarMultiplasLinhas(
    Celula ***tabuleiro, int linhas, int colunas,
    int *gatinhosJogadorAtual, int *gatosJogadorAtual,
    int *pecasAtivas);

// Verifica se houve uma vit�ria no jogo
int verificaVitoria(Celula ***tabuleiro, int linhas, int colunas, int gatosNaCamaJogador1, int gatosNaCamaJogador2);
void salvarEstado(const char *nomeArquivo, Estado *estado);
int carregarEstado(const char *nomeArquivo, Estado *estado);
void menuSalvarJogo(Estado *estado);
int menuPausa(Estado *estado);
#endif
