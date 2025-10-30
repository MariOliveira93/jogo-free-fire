#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/**
 * @file main.c
 * @brief Ponto de entrada do programa
 * 
 * Sistema de Inventário - Free Fire
 * Simula a mochila de loot inicial do jogador
 * 
 * @author Seu Nome
 * @date 2025
 * @version 1.0
 * 
 * Funcionalidades:
 * - Cadastro de itens (nome, tipo, quantidade)
 * - Remoção de itens por nome
 * - Listagem completa do inventário
 * - Busca sequencial de itens
 * 
 * Estruturas de dados utilizadas:
 * - Struct Item: armazena dados de cada item
 * - Vetor sequencial: lista de até 10 itens
 */

int main() {
    // Inicia o sistema de menu
    executarMenu();
    
    return 0;
}