#include <string.h>
#include "algoritmos_ordenacao.h"

/**
 * @file algoritmos_ordenacao.c
 * @brief Implementação dos algoritmos de ordenação
 *
 * Três algoritmos clássicos: Bubble Sort, Insertion Sort e Selection Sort
 * Cada um otimizado para um critério diferente (nome, tipo, prioridade)
 */

void bubbleSortNome(Componente componentes[], int n, int* comparacoes) {
    *comparacoes = 0;
    
    // Bubble Sort: compara pares adjacentes e troca se necessário
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (strcmp(componentes[j].nome, componentes[j + 1].nome) > 0) {
                // Troca os componentes
                Componente temp = componentes[j];
                componentes[j] = componentes[j + 1];
                componentes[j + 1] = temp;
            }
        }
    }
}

void insertionSortTipo(Componente componentes[], int n, int* comparacoes) {
    *comparacoes = 0;
    
    // Insertion Sort: insere cada elemento na posição correta
    for (int i = 1; i < n; i++) {
        Componente chave = componentes[i];
        int j = i - 1;
        
        // Move elementos maiores uma posição à frente
        while (j >= 0) {
            (*comparacoes)++;
            if (strcmp(componentes[j].tipo, chave.tipo) > 0) {
                componentes[j + 1] = componentes[j];
                j--;
            } else {
                break;
            }
        }
        componentes[j + 1] = chave;
    }
}

void selectionSortPrioridade(Componente componentes[], int n, int* comparacoes) {
    *comparacoes = 0;
    
    // Selection Sort: seleciona o maior elemento e coloca no final
    // Ordenação DECRESCENTE (prioridade maior primeiro)
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        
        // Encontra o elemento de maior prioridade
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (componentes[j].prioridade > componentes[maxIdx].prioridade) {
                maxIdx = j;
            }
        }
        
        // Troca se necessário
        if (maxIdx != i) {
            Componente temp = componentes[i];
            componentes[i] = componentes[maxIdx];
            componentes[maxIdx] = temp;
        }
    }
}