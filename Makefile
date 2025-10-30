# Makefile para o projeto Free Fire - Versão Final (Nível 3)
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
          $(SRC_DIR)/torre_resgate.c \
          $(SRC_DIR)/algoritmos_ordenacao.c \
          $(SRC_DIR)/medidor_performance.c \
          $(SRC_DIR)/menu.c

OBJECTS = $(BUILD_DIR)/main.o \
          $(BUILD_DIR)/inventario_vetor.o \
          $(BUILD_DIR)/inventario_lista.o \
          $(BUILD_DIR)/comparador.o \
          $(BUILD_DIR)/torre_resgate.o \
          $(BUILD_DIR)/algoritmos_ordenacao.o \
          $(BUILD_DIR)/medidor_performance.o \
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
	@echo "============================================================="
	@echo "Projeto: Free Fire - Sistema Completo"
	@echo "Versao: 3.0 FINAL (Nivel 3)"
	@echo "============================================================="
	@echo ""
	@echo "NIVEL 1 - Estruturas Basicas:"
	@echo "  - Vetor (lista sequencial)"
	@echo "  - Lista encadeada"
	@echo ""
	@echo "NIVEL 2 - Comparacao:"
	@echo "  - Busca Sequencial"
	@echo "  - Busca Binaria"
	@echo "  - Analise de desempenho"
	@echo ""
	@echo "NIVEL 3 - Torre de Resgate (FINAL):"
	@echo "  - Bubble Sort (ordenacao por nome)"
	@echo "  - Insertion Sort (ordenacao por tipo)"
	@echo "  - Selection Sort (ordenacao por prioridade)"
	@echo "  - Busca Binaria otimizada"
	@echo "  - Medicao de tempo (clock)"
	@echo "  - Contador de comparacoes"
	@echo "  - Analise comparativa completa"
	@echo ""
	@echo "============================================================="

# Regras especiais
.PHONY: all clean run info