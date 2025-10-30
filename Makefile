# Makefile para o projeto Free Fire Inventário - Nível 2
# Compilador e flags

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = jogo_free_fire

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Arquivos fonte e objetos
SOURCES = $(SRC_DIR)/main.c \
          $(SRC_DIR)/inventario_vetor.c \
          $(SRC_DIR)/inventario_lista.c \
          $(SRC_DIR)/comparador.c \
          $(SRC_DIR)/menu.c

OBJECTS = $(BUILD_DIR)/main.o \
          $(BUILD_DIR)/inventario_vetor.o \
          $(BUILD_DIR)/inventario_lista.o \
          $(BUILD_DIR)/comparador.o \
          $(BUILD_DIR)/menu.o

# Regra principal
all: $(BUILD_DIR) $(TARGET)

# Cria o diretório build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compila o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "=========================================="
	@echo "Compilacao concluida com sucesso!"
	@echo "Execute com: ./$(TARGET)"
	@echo "=========================================="

# Compila os arquivos objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos compilados
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "Arquivos de build removidos!"

# Executa o programa
run: all
	./$(TARGET)

# Informações do projeto
info:
	@echo "=========================================="
	@echo "Projeto: Free Fire - Inventario de Loot"
	@echo "Versao: 2.0 (Nivel 2)"
	@echo "=========================================="
	@echo "Estruturas implementadas:"
	@echo "  - Vetor (lista sequencial)"
	@echo "  - Lista encadeada"
	@echo ""
	@echo "Algoritmos:"
	@echo "  - Busca Sequencial"
	@echo "  - Busca Binaria"
	@echo "  - Ordenacao (Bubble Sort)"
	@echo "=========================================="

# Regras especiais
.PHONY: all clean run info