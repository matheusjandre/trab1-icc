# Makefile base - Matheus Jandre
COMP = gcc
CFLAGS = -Wall -std=c99 -lm -DLIKWID_PERFMON -I /usr/local/include -L /usr/local/lib -llikwid

TARGET = pontoscriticos

LIB = ./libs
TMP = ./tmp
OBJ = ./obj

SOURCES = $(wildcard *.c $(LIB)/*.c)
OBJECTS = $(SOURCES: .c=.o) 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(COMP) $(CCFLAGS) -o $@ $^

# all: $(DEP)
# @$(COMP) $(CFLAGS) $(OBJ)/* main.c -o $(PROGRAM_NAME)
# @echo "O executável foi gerado."
# @echo "Executar: ./$(PROGRAM_NAME) -o <arquivo_de_saida>"

# OBJETOS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#lib.o: lib.h
#	$(COMP) $(CFLAGS) -c lib.c

%.o: %.c %.h
	$(COMP) $(CCFLAGS) -c $<

%.o: %.c
	$(COMP) $(CCFLAGS) -c $<

# COMANDOS PARA LIMPEZA -=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

temp:
	@rm -rf $(TMP)/*
	@echo "Todos os arquivos temporários foram removidos."

purge:
	@rm $(PROGRAM_NAME)
	@echo "O executável do programa foi removido."