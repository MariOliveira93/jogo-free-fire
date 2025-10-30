#include <stdio.h>
#include "comparador.h"

/**
 * @file comparador.c
 * @brief Implementação de ferramentas de análise de desempenho
 */

void exibirComparativo(int compSeq, int compBin) {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║      COMPARATIVO DE DESEMPENHO         ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n");
    printf("  Busca Sequencial: %d comparacoes\n", compSeq);
    printf("  Busca Binaria:    %d comparacoes\n", compBin);
    printf("\n");
    
    if (compBin < compSeq) {
        int ganho = ((compSeq - compBin) * 100) / compSeq;
        printf("  >> Busca binaria foi %d%% mais eficiente!\n", ganho);
    }
    
    printf("\n");
    printf("  [ANALISE]\n");
    printf("  - Busca Sequencial: O(n) - percorre todos\n");
    printf("  - Busca Binaria: O(log n) - divide e conquista\n");
    printf("  - Busca binaria requer dados ORDENADOS\n");
    printf("\n");
}

void exibirAnaliseEstruturas() {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║           ANALISE: VETOR vs LISTA ENCADEADA               ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("┌────────────────────┬──────────────────┬──────────────────┐\n");
    printf("│ OPERACAO           │ VETOR            │ LISTA ENCADEADA  │\n");
    printf("├────────────────────┼──────────────────┼──────────────────┤\n");
    printf("│ Acesso por indice  │ O(1) - Rapido    │ O(n) - Lento     │\n");
    printf("│ Insercao no fim    │ O(1)             │ O(n)             │\n");
    printf("│ Insercao no inicio │ O(n) - Reorgan.  │ O(1) - Direto    │\n");
    printf("│ Remocao            │ O(n) - Reorgan.  │ O(n) - Busca     │\n");
    printf("│ Busca Sequencial   │ O(n)             │ O(n)             │\n");
    printf("│ Busca Binaria      │ O(log n) *       │ Nao aplicavel    │\n");
    printf("│ Uso de memoria     │ Fixo             │ Dinamico +ptr    │\n");
    printf("│ Cache-friendly     │ SIM              │ NAO              │\n");
    printf("└────────────────────┴──────────────────┴──────────────────┘\n");
    printf("\n");
    printf("  * Busca binaria requer vetor ORDENADO\n");
    printf("\n");
    printf("  [QUANDO USAR VETOR]\n");
    printf("  - Tamanho maximo conhecido\n");
    printf("  - Acesso frequente por indice\n");
    printf("  - Necessidade de busca binaria\n");
    printf("  - Poucas insercoes/remocoes\n");
    printf("\n");
    printf("  [QUANDO USAR LISTA]\n");
    printf("  - Tamanho variavel/desconhecido\n");
    printf("  - Muitas insercoes/remocoes\n");
    printf("  - Insercao no inicio frequente\n");
    printf("  - Memoria limitada\n");
    printf("\n");
}