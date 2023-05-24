# Makefile base - Matheus Jandre
COMP = gcc
CFLAGS = -Wall -std=c99

PROGRAM_NAME = pontoscriticos

DEP = 

TMP = ./tmp
OBJ = ./obj

all: $(DEP)
	@$(COMP) $(CFLAGS) $(OBJ)/* main.c -o $(PROGRAM_NAME)
	@echo "O executável foi gerado."
	@echo "Executar: ./$(PROGRAM_NAME) -o <arquivo_de_saida>"

# OBJETOS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#lib.o: lib.h
#	$(COMP) $(CFLAGS) -c lib.c

# COMANDOS PARA LIMPEZA -=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

temp:
	@rm -rf $(TMP)/*
	@echo "Todos os arquivos temporários foram removidos."

purge:
	@rm $(PROGRAM_NAME)
	@echo "O executável do programa foi removido."