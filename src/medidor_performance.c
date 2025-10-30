
#include <stdio.h>
#include <time.h>
#include "medidor_performance.h"

/**
 * @file medidor_performance.c
 * @brief Implementação das ferramentas de medição de desempenho
 */

clock_t iniciarMedicao() {
    return clock();
}

double finalizarMedicao(clock_t inicio) {
    clock_t fim = clock();
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0; // Converte para ms
}

void exibirComparativoAlgoritmos(ResultadoPerformance resultados[], int quantidade) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║         COMPARATIVO DE DESEMPENHO - ORDENACAO              ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("┌──────────────────────┬──────────────┬────────────────────┐\n");
    printf("│ ALGORITMO            │ COMPARACOES  │ TEMPO (ms)         │\n");
    printf("├──────────────────────┼──────────────┼────────────────────┤\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("│ %-20s │ %12d │ %18.6f │\n",
               resultados[i].algoritmo,
               resultados[i].comparacoes,
               resultados[i].tempo_ms);
    }
    
    printf("└──────────────────────┴──────────────┴────────────────────┘\n");
    printf("\n");
    
    // Encontra o mais eficiente
    if (quantidade > 1) {
        int maisRapido = 0;
        for (int i = 1; i < quantidade; i++) {
            if (resultados[i].comparacoes < resultados[maisRapido].comparacoes) {
                maisRapido = i;
            }
        }
        printf("  >> Algoritmo mais eficiente: %s\n", resultados[maisRapido].algoritmo);
        printf("     (%d comparacoes)\n", resultados[maisRapido].comparacoes);
    }
    printf("\n");
}

void exibirAnaliseComplexidade() {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║        ANALISE DE COMPLEXIDADE - ALGORITMOS                ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("┌──────────────────┬──────────┬──────────┬──────────────────┐\n");
    printf("│ ALGORITMO        │ MELHOR   │ MEDIO    │ PIOR             │\n");
    printf("├──────────────────┼──────────┼──────────┼──────────────────┤\n");
    printf("│ Bubble Sort      │ O(n)     │ O(n²)    │ O(n²)            │\n");
    printf("│ Insertion Sort   │ O(n)     │ O(n²)    │ O(n²)            │\n");
    printf("│ Selection Sort   │ O(n²)    │ O(n²)    │ O(n²)            │\n");
    printf("│ Busca Binaria    │ O(1)     │ O(log n) │ O(log n)         │\n");
    printf("└──────────────────┴──────────┴──────────┴──────────────────┘\n");
    printf("\n");
    printf("  [CARACTERISTICAS]\n");
    printf("\n");
    printf("  BUBBLE SORT:\n");
    printf("    - Simples de implementar\n");
    printf("    - Compara pares adjacentes\n");
    printf("    - Eficiente em dados quase ordenados\n");
    printf("    - Estavel (mantem ordem de elementos iguais)\n");
    printf("\n");
    printf("  INSERTION SORT:\n");
    printf("    - Bom para pequenos conjuntos\n");
    printf("    - Eficiente para dados parcialmente ordenados\n");
    printf("    - Ordenacao in-place\n");
    printf("    - Estavel\n");
    printf("\n");
    printf("  SELECTION SORT:\n");
    printf("    - Sempre O(n²) comparacoes\n");
    printf("    - Minimo de trocas (n-1)\n");
    printf("    - Bom quando a troca é custosa\n");
    printf("    - Nao estavel\n");
    printf("\n");
    printf("  BUSCA BINARIA:\n");
    printf("    - Requer dados ORDENADOS\n");
    printf("    - Muito eficiente: O(log n)\n");
    printf("    - Divide o espaco de busca pela metade\n");
    printf("    - Ideal para buscas frequentes\n");
    printf("\n");
}