# Makefile para o projeto JogoBoop
# Uso:
#   make        -> compila o executável 'programa'
#   make run    -> compila e executa o programa
#   make clean  -> remove arquivos objeto e executável

CC := gcc
CFLAGS := -Wall -Wextra -g -I.
LDFLAGS :=

SRCS := main.c funcoes.c \
        graduar/graduar.c \
        jogada/jogada.c \
        tabuleiro/tabuleiro.c \
        vitoria/vencer.c

OBJS := $(SRCS:.c=.o)

PROG := programa

.PHONY: all run clean debug

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(PROG)
	./$(PROG)

debug: CFLAGS += -DDEBUG
debug: clean all

clean:
	rm -f $(OBJS) $(PROG)
