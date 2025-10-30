
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/**
 * @file main.c
 * @brief Ponto de entrada do programa
 *
 * Sistema de Inventário - Free Fire (Nível 2)
 * Comparação entre Vetor e Lista Encadeada
 *
 * @version 2.0
 *
 * Funcionalidades:
 * - Implementação com VETOR (lista sequencial)
 * - Implementação com LISTA ENCADEADA
 * - Ordenação (Bubble Sort)
 * - Busca Sequencial (ambas estruturas)
 * - Busca Binária (apenas vetor ordenado)
 * - Análise comparativa de desempenho
 *
 * Estruturas de dados:
 * - Struct Item: dados do item
 * - Struct No: nó da lista encadeada
 * - Vetor estático: array de 10 itens
 * - Lista dinâmica: alocação com malloc/free
 */

int main() {
    executarMenu();
    return 0;
}