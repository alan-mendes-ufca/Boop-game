# 🐱 Boop - Jogo de Tabuleiro em C

Implementação em C do jogo de tabuleiro **Boop**, um jogo estratégico de dois jogadores onde gatos adoráveis competem pelo domínio do tabuleiro através do efeito "boop" (empurrão).

## 📋 Regras do Jogo

### Objetivo
Ser o primeiro jogador a conseguir **três gatos adultos (gatões)** alinhados consecutivamente (horizontal, vertical ou diagonal) no tabuleiro.

### Componentes
- **Tabuleiro**: 6x6 células
- **Peças por jogador**:
  - 8 gatinhos (representados por 'g')
  - Gatões (representados por 'G') - obtidos através de graduação

### Como Jogar

1. **Colocação de Peças**
   - Em cada turno, o jogador coloca um gatinho ou gatão em uma célula vazia do tabuleiro
   - Formato de entrada: `[tipo] [linha] [coluna]` (ex: `g 3 B`)

2. **Efeito Boop (Empurrão)**
   - Quando uma peça é colocada, ela "boopa" (empurra) todas as peças adjacentes em 8 direções
   - **Regras do Boop**:
     - Gatinhos **não podem** empurrar gatões
     - Gatões **podem** empurrar qualquer peça
     - Peças empurradas movem-se uma casa na direção do empurrão
     - Se uma peça for empurrada para fora do tabuleiro, ela retorna ao inventário do jogador
     - Peças **não** são empurradas se:
       - Já existe uma peça na posição de destino
       - Formam uma linha de 3 para graduação

3. **Graduação**
   - Quando **3 peças iguais** do mesmo jogador ficam alinhadas consecutivamente, elas "se graduam"
   - As 3 peças são removidas do tabuleiro e retornam à caixa
   - O jogador recebe **3 gatões** (gatos adultos) no inventário
   - Limite: cada jogador pode ter no máximo **8 peças ativas** no tabuleiro

4. **Condições de Vitória**
   - **Vitória Principal**: Formar uma linha de 3 **gatões** consecutivos
   - **Vitória Alternativa**: Ter os 8 gatos do jogador no tabuleiro ("cama cheia")
   - **Empate**: Ambos os jogadores ficam sem peças para jogar

## 🏗️ Estrutura do Projeto

```
JogoBoop/
├── main.c              # Loop principal do jogo
├── funcoes.c/h         # Funções auxiliares e entrada de dados
├── Makefile            # Build system avançado
├── graduar/            # Lógica de graduação de peças
│   ├── graduar.c
│   └── graduar.h
├── jogada/             # Validação e efeito boop
│   ├── jogada.c
│   └── jogada.h
├── tabuleiro/          # Inicialização e exibição do tabuleiro
│   ├── tabuleiro.c
│   └── tabuleiro.h
└── vitoria/            # Verificação de condições de vitória
    ├── vencer.c
    └── vencer.h
```

## 🚀 Como Compilar e Executar

### Compilação

```bash
# Build padrão (release mode)
make

# Build com símbolos de debug
make debug

# Limpar arquivos objeto
make clean

# Limpar tudo (incluindo binário e pasta build/)
make dist-clean
```

### Execução

```bash
# Executar o jogo
./programa

# Ou compilar e executar em um comando
make run
```

### Instalação (opcional)

```bash
# Instalar no sistema (pode precisar de sudo)
sudo make install

# Desinstalar
sudo make uninstall
```

## ✅ Pontos Fortes da Implementação

### Estrutura e Organização
- ✅ **Modularização clara**: Código separado por funcionalidades (jogada, tabuleiro, vitória, graduação)
- ✅ **Headers bem definidos**: Interfaces públicas claras com guards de inclusão
- ✅ **Makefile avançado**: Build out-of-source, dependências automáticas, modos debug/release
- ✅ **Tipos definidos**: Structs `Celula` e `Jogador` encapsulam bem os dados

### Funcionalidades Implementadas
- ✅ **Sistema de cores**: Diferenciação visual entre jogadores com ANSI colors
- ✅ **Detecção de vitória**: Verifica alinhamentos e condição de "cama cheia"
- ✅ **Graduação**: Detecta e processa linhas de 3 peças
- ✅ **Efeito boop**: Implementação das 8 direções de empurrão
- ✅ **Interface visual**: ASCII art do gato e tabuleiro formatado

### Boas Práticas
- ✅ **Constantes definidas**: `TAMANHO_TABULEIRO`, `RED`, `BLUE` em vez de magic numbers
- ✅ **Separação de concerns**: Cada módulo tem responsabilidade bem definida
- ✅ **Alocação dinâmica**: Tabuleiro alocado dinamicamente (preparado para diferentes tamanhos)

## 🐛 Problemas Identificados e Bugs

### 🔴 Críticos (Impedem o Jogo de Funcionar)

2. **Comparação de Cores Incorreta**
   - **Causa**: Comparação de ponteiros (`corRemovida == RED`) em vez de valores
   - **Local**: `jogada/jogada.c` linhas 122, 124, 129, 131
   - **Problema**: Compara endereços de memória, não o conteúdo das strings

3. **Limites do Tabuleiro Incorretos**
   - **Causa**: Verifica `linha >= 7` em vez de `>= 6`
   - **Local**: `jogada/jogada.c` linha 18
   - **Problema**: Aceita coordenadas inválidas (linha 7 não existe em tabuleiro 6x6)

4. **Lógica de Vitória por Cor Errada**
   - **Causa**: Assume que 'g' é sempre Jogador 1 e 'G' é Jogador 2
   - **Local**: `vitoria/vencer.c` linhas 48-51
   - **Problema**: Deveria verificar a **cor** da peça, não o tipo

### 🟡 Moderados (Funcionalidade Parcial)

5. **Validação de Entrada Fraca**
   - **Problema**: `scanf()` não valida entrada malformada (ex: "abc", números negativos)
   - **Impacto**: Comportamento indefinido com entradas inválidas
   - **Local**: `funcoes.c` linha 8

6. **Buffer Overflow em `scanf()`**
   - **Problema**: `scanf()` não verifica tamanho do buffer
   - **Risco**: Entrada muito grande pode corromper memória
   - **Local**: `funcoes.c` linha 8

7. **Graduação Pode Processar Mesma Linha Múltiplas Vezes**
   - **Problema**: Lógica em `graduarMultiplasLinhas` pode detectar linhas duplicadas
   - **Impacto**: Jogador pode ganhar gatões extras incorretamente
   - **Local**: `graduar/graduar.c` função `graduarMultiplasLinhas`

8. **Falta Verificar Retorno de `malloc()`**
   - **Problema**: Se `malloc()` falhar, programa continua com ponteiro NULL
   - **Risco**: Segfault garantido em caso de falta de memória
   - **Local**: `tabuleiro/tabuleiro.c` função `inicializarTabuleiro`

### 🟢 Menores (Melhorias de Qualidade)

9. **Warnings do Compilador**
   - `scanf()` e `system()` retornos ignorados
   - Parâmetro `saltando` não utilizado em `aplicarBoop`
   - Conversões implícitas de tipo

10. **Falta de Documentação de Funções**
    - Nenhuma função tem comentários explicando parâmetros e retorno
    - Dificulta manutenção

11. **Magic Numbers no Código**
    - Alguns valores hardcoded (ex: 8 peças, 100 combinações máximas)

12. **Falta Função de Liberação de Memória**
    - `liberarTabuleiro()` existe mas nunca é chamada
    - Memory leak ao encerrar programa

## 📝 TODO List - Roadmap de Melhorias

### 🔥 Prioridade ALTA - Consertar Bugs Críticos

#### TODO #3: Corrigir Limites do Tabuleiro
**Arquivo**: `jogada/jogada.c` linha 18  
**Problema**: Valida `linha >= 7` permitindo linha 6 em tabuleiro 6x6 (índices 0-5)  
**Solução**:
```c
// ❌ ERRADO
if (linha < 0 || linha >= 7 || coluna < 0 || coluna >= 6)

// ✅ CORRETO
if (linha < 0 || linha >= TAMANHO_TABULEIRO || 
    coluna < 0 || coluna >= TAMANHO_TABULEIRO)
```

**O que estudar**:
- Indexação de arrays em C (começam em 0)
- Off-by-one errors (erro comum em loops e validações)
- [Artigo: Common C errors](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)CommonErrors.html)

---

#### TODO #4: Corrigir Lógica de Vitória
**Arquivo**: `vitoria/vencer.c` linhas 48-51  
**Problema**: Vitória baseada em tipo de peça ('g'/'G') em vez de jogador (cor)  
**Solução**:
```c
// Precisamos verificar a COR da peça, não o tipo
// Se usar enum de cor:
if (pecaAtual == peca1 && pecaAtual == peca2) {
    CorJogador corVencedora = tabuleiro[i][j].cor;
    if (corVencedora == COR_JOGADOR1) return 1;
    if (corVencedora == COR_JOGADOR2) return 2;
}
```

**O que estudar**:
- Lógica de domínio vs implementação técnica
- Como estruturar dados para representar regras de jogo
- Design de sistemas de pontuação/vitória

---

### ⚡ Prioridade MÉDIA - Melhorar Robustez

#### TODO #5: Implementar Validação de Entrada Robusta
**Arquivo**: `funcoes.c` função `get_input`  
**Problema**: `scanf()` não lida com entradas malformadas  
**Solução**:
```c
void get_input(char *tipoPeca, int *linha, char *coluna) {
    int result;
    do {
        printf("\nDigite tipo e coordenada (ex: g 1 A): ");
        
        // Limpa buffer antes de ler
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        result = scanf(" %c %d %c", tipoPeca, linha, coluna);
        
        if (result != 3) {
            printf("Entrada inválida! Tente novamente.\n");
        }
    } while (result != 3);
}
```

**O que estudar**:
- Validação de entrada em C
- Problemas com `scanf()` e alternativas (`fgets()`, `getline()`)
- Limpeza de buffer de entrada
- [Tutorial: Input validation](https://stackoverflow.com/questions/3302255/input-validation-in-c)
- [Artigo: Why scanf is problematic](https://stackoverflow.com/questions/58403537/why-is-scanf-dangerous)

---

#### TODO #6: Adicionar Verificação de `malloc()`
**Arquivo**: `tabuleiro/tabuleiro.c` função `inicializarTabuleiro`  
**Problema**: Não verifica se alocação foi bem-sucedida  
**Solução**:
```c
Celula **inicializarTabuleiro(int linhas, int colunas) {
    Celula **tabuleiro = malloc(linhas * sizeof(Celula *));
    if (tabuleiro == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para tabuleiro\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < linhas; i++) {
        tabuleiro[i] = malloc(colunas * sizeof(Celula));
        if (tabuleiro[i] == NULL) {
            // Libera memória já alocada
            for (int j = 0; j < i; j++) {
                free(tabuleiro[j]);
            }
            free(tabuleiro);
            fprintf(stderr, "Erro: falha ao alocar linha %d\n", i);
            exit(EXIT_FAILURE);
        }
        // ... resto da inicialização
    }
    return tabuleiro;
}
```

**O que estudar**:
- Gerenciamento de memória em C
- Error handling (tratamento de erros)
- RAII pattern (Resource Acquisition Is Initialization)
- [Tutorial: Dynamic memory](https://www.learn-c.org/en/Dynamic_allocation)
- [Artigo: Checking malloc return](https://stackoverflow.com/questions/1938570/is-it-necessary-to-check-for-null-after-malloc)

---

#### TODO #7: Corrigir Graduação de Linhas Duplicadas
**Arquivo**: `graduar/graduar.c` função `graduarMultiplasLinhas`  
**Problema**: Mesma linha pode ser detectada múltiplas vezes  
**Solução**:
```c
// Após detectar linha, marcar células como processadas
// Ou usar estrutura auxiliar para rastrear linhas já graduadas
typedef struct {
    int posicoes[3][2];
    int processada;
} LinhaGraduacao;

// Antes de graduar, verificar se linha já foi processada
```

**O que estudar**:
- Algoritmos de detecção de padrões
- Estruturas de dados auxiliares (hash set, boolean array)
- Como evitar processamento duplicado
- [Tutorial: Pattern matching](https://www.geeksforgeeks.org/pattern-searching-algorithms/)

---

#### TODO #8: Adicionar Liberação de Memória ao Sair
**Arquivo**: `main.c` fim da função `main`  
**Problema**: Memory leak - memória não é liberada antes de sair  
**Solução**:
```c
int main() {
    // ... código existente ...
    
    // Antes de sair, liberar memória
    liberarTabuleiro(tabuleiro, TAMANHO_TABULEIRO);
    
    return 0;  // Adicionar return explícito
}
```

**O que estudar**:
- Memory leaks e como detectá-los
- Ferramentas: Valgrind, AddressSanitizer
- Boas práticas de cleanup
- [Tutorial: Valgrind](https://valgrind.org/docs/manual/quick-start.html)
- Comando: `valgrind --leak-check=full ./programa`

---

### 🎯 Prioridade BAIXA - Polimento e Features

#### TODO #9: Adicionar Sistema de Undo/Redo
**Complexidade**: Alta  
**Benefício**: Permite desfazer jogadas  
**Implementação**:
- Criar struct `Estado` que salva estado completo do jogo
- Implementar pilha (stack) de estados
- Adicionar comando 'u' para undo

**O que estudar**:
- Estruturas de dados: pilhas (stacks)
- Design pattern: Memento
- Serialização de estado
- [Tutorial: Stack implementation](https://www.geeksforgeeks.org/stack-data-structure/)

---

#### TODO #10: Implementar IA (Computador vs Humano)
**Complexidade**: Alta  
**Benefício**: Jogar contra o computador  
**Implementação**:
```c
// Opções de IA por dificuldade:

// 1. IA Aleatória (fácil)
void ia_aleatoria(Celula **tabuleiro, Jogador *ia) {
    // Escolhe posição válida aleatória
}

// 2. IA Heurística (médio)
void ia_heuristica(Celula **tabuleiro, Jogador *ia) {
    // Prioriza: formar linhas > bloquear oponente > centro
}

// 3. IA Minimax (difícil)
int minimax(Estado *estado, int profundidade, int alpha, int beta) {
    // Algoritmo minimax com alpha-beta pruning
}
```

**O que estudar**:
- Teoria dos jogos
- Algoritmo Minimax
- Alpha-beta pruning
- Funções de avaliação heurística
- [Tutorial: Minimax](https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/)
- [Vídeo: AI for games](https://www.youtube.com/watch?v=trKjYdBASyQ)

---

#### TODO #11: Salvar e Carregar Jogo
**Complexidade**: Média  
**Benefício**: Continuar jogo depois  
**Implementação**:
```c
// Salvar estado em arquivo
void salvarJogo(const char *arquivo, Celula **tabuleiro, 
                Jogador j1, Jogador j2, int turno) {
    FILE *f = fopen(arquivo, "wb");
    // Escrever dados binários
    fwrite(&turno, sizeof(int), 1, f);
    fwrite(&j1, sizeof(Jogador), 1, f);
    // ... resto dos dados
    fclose(f);
}

// Carregar estado
void carregarJogo(const char *arquivo, /* parâmetros */) {
    FILE *f = fopen(arquivo, "rb");
    fread(&turno, sizeof(int), 1, f);
    // ... ler resto
    fclose(f);
}
```

**O que estudar**:
- File I/O em C (`fopen`, `fwrite`, `fread`)
- Serialização binária vs texto
- Formato de arquivo (JSON, binário customizado)
- [Tutorial: File I/O](https://www.cprogramming.com/tutorial/cfileio.html)

---

#### TODO #12: Interface Gráfica (Opcional - Avançado)
**Complexidade**: Muito Alta  
**Benefício**: Visual mais atraente  
**Opções**:
1. **Terminal melhorado** (mais fácil): 
   - Biblioteca `ncurses` para interface TUI
2. **GUI nativa** (médio):
   - GTK+ ou SDL2
3. **Web** (interessante):
   - Backend em C + Frontend HTML/JS
   - WebAssembly (compilar C para navegador)

**O que estudar**:
- Biblioteca ncurses (terminal UI)
- SDL2 (gráficos 2D simples)
- GTK+ (GUI nativa Linux)
- [Tutorial: ncurses](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
- [Tutorial: SDL2](https://lazyfoo.net/tutorials/SDL/)

---

#### TODO #13: Adicionar Testes Unitários
**Complexidade**: Média  
**Benefício**: Garantir que código funciona  
**Implementação**:
```c
// Usar framework de testes: Unity, Check, ou CUnit

// Exemplo com asserts simples:
void test_verificarJogada() {
    Celula **tab = inicializarTabuleiro(6, 6);
    int gatinhos = 5;
    int gatos = 0;
    
    // Teste: jogada válida
    int resultado = verificarJogada(tab, 0, 0, 'g', &gatinhos, &gatos);
    assert(resultado == 1);
    assert(gatinhos == 4);
    
    // Teste: célula ocupada
    tab[0][0].gato = 'g';
    resultado = verificarJogada(tab, 0, 0, 'g', &gatinhos, &gatos);
    assert(resultado == 0);
    
    liberarTabuleiro(tab, 6);
}
```

**O que estudar**:
- Testes unitários (unit testing)
- Framework de testes em C
- TDD (Test-Driven Development)
- [Tutorial: Unit testing in C](https://github.com/ThrowTheSwitch/Unity)

---

#### TODO #14: Melhorar Visualização do Tabuleiro
**Complexidade**: Baixa  
**Benefício**: Interface mais clara  
**Ideias**:
- Destacar última jogada com cor diferente
- Mostrar células válidas para jogada
- Animação do efeito boop (limpar tela e redesenhar)
- Emoji de gatos reais (🐱 🐈) se terminal suportar UTF-8

**O que estudar**:
- ANSI escape codes (cores, posicionamento cursor)
- UTF-8 encoding
- Terminal capabilities
- [Referência: ANSI codes](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797)

---

#### TODO #15: Adicionar Modo de Replay
**Complexidade**: Média  
**Benefício**: Rever partida depois  
**Implementação**:
- Salvar todas as jogadas em arquivo de log
- Criar modo de replay que lê o log e executa jogadas
- Adicionar controles: avançar, voltar, pausar

**O que estudar**:
- Formato de log (texto simples ou estruturado)
- Parsing de arquivos
- State machine para controle de replay

---

## 📚 Recursos de Estudo Recomendados

### Livros
- **"The C Programming Language"** - Kernighan & Ritchie (K&R)
- **"C Programming: A Modern Approach"** - K. N. King
- **"Expert C Programming: Deep C Secrets"** - Peter van der Linden

### Cursos Online
- [CS50 - Harvard](https://cs50.harvard.edu/) - Introdução à Ciência da Computação
- [Learn-C.org](https://www.learn-c.org/) - Tutorial interativo
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) - Guia completo gratuito

### Ferramentas Úteis
- **Valgrind**: Detectar memory leaks
- **GDB**: Debugger para C
- **AddressSanitizer**: Detectar bugs de memória em tempo de compilação
- **Clang-Tidy**: Linter/analisador estático

### Compilar com Sanitizers (Debugar Bugs)
```bash
# AddressSanitizer (detecta buffer overflow, use-after-free, etc)
gcc -fsanitize=address -g -O1 *.c ... -o programa

# UndefinedBehaviorSanitizer
gcc -fsanitize=undefined -g *.c ... -o programa

# Executar com Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./programa
```

## 🤝 Contribuindo

Ao trabalhar nos TODOs:
1. Crie um branch para cada TODO (`git checkout -b todo-5-validacao`)
2. Teste exaustivamente antes de commitar
3. Compile com warnings habilitados: `gcc -Wall -Wextra -Werror`
4. Execute com Valgrind para verificar memory leaks
5. Documente mudanças no código com comentários

## 📜 Licença

Projeto educacional - Use livremente para aprender!

---

**Última atualização**: Novembro 2025  
**Versão**: 0.1 (Alpha - Em Desenvolvimento)
