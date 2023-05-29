# Makefile base - Matheus Jandre
COMP = gcc
CCFLAGS = -Wall -std=c99 -lm

TARGET = pontoscriticos

LIB = ./libs
TMP = ./tmp
OBJ = ./obj

SOURCES = $(wildcard *.c $(LIB)/*.c $(LIB)/*/*.c)
OBJECTS = $(SOURCES: .c=.o) 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(COMP) $(CCFLAGS) -o $@ $^

# OBJETOS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

%.o: %.c %.h
	@$(COMP) $(CCFLAGS) -c $<

# %.o: %.c @$(COMP) $(CCFLAGS) -c $<

# COMANDOS PARA LIMPEZA -=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

temp:
	@rm -rf $(TMP)/*
	@echo "Todos os arquivos temporários foram removidos."

purge:
	@rm $(TARGET)
	@echo "O executável do programa foi removido."