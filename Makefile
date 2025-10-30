# Makefile para o projeto Free Fire Inventário
# Compilador e flags

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = jogo_free_fire

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Arquivos fonte
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/inventario.c $(SRC_DIR)/menu.c
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/inventario.o $(BUILD_DIR)/menu.o

# Regra principal
all: $(BUILD_DIR) $(TARGET)

# Cria o diretório build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compila o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Compilacao concluida! Execute com: ./$(TARGET)"

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

# Regras especiais
.PHONY: all clean run