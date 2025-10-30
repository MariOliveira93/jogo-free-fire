#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/**
 * @file main.c
 * @brief Ponto de entrada do programa
 *
 * Sistema de Inventário - Free Fire (COMPLETO)
 * Três Níveis de Desafio
 *
 * @version 3.0 - FINAL
 *
 * NIVEL 1: Estruturas Básicas
 * - Vetor (lista sequencial)
 * - Lista encadeada
 * - Operações CRUD básicas
 *
 * NIVEL 2: Comparação e Análise
 * - Busca sequencial vs binária
 * - Análise de desempenho
 * - Ordenação com Bubble Sort
 *
 * NIVEL 3: Torre de Resgate (FINAL)
 * - Múltiplos algoritmos de ordenação
 * - Bubble Sort (por nome)
 * - Insertion Sort (por tipo)
 * - Selection Sort (por prioridade)
 * - Busca binária otimizada
 * - Medição de tempo e comparações
 * - Análise comparativa completa
 *
 * Estruturas de dados:
 * - Item: inventário básico
 * - Componente: torre de resgate
 * - No: lista encadeada
 *
 * Algoritmos implementados:
 * - Busca sequencial
 * - Busca binária
 * - Bubble Sort
 * - Insertion Sort
 * - Selection Sort
 */

int main() {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                                                            ║\n");
    printf("║              FREE FIRE - JOGO COMPLETO                     ║\n");
    printf("║           ESTRUTURAS DE DADOS EM C                         ║\n");
    printf("║                                                            ║\n");
    printf("║  Desenvolvido como projeto educacional                    ║\n");
    printf("║  Demonstrando conceitos fundamentais de:                  ║\n");
    printf("║    - Estruturas de dados                                  ║\n");
    printf("║    - Algoritmos de ordenacao                              ║\n");
    printf("║    - Algoritmos de busca                                  ║\n");
    printf("║    - Analise de complexidade                              ║\n");
    printf("║                                                            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");

    executarMenu();

    return 0;
}