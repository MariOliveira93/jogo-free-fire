#ifndef ALGORITMOS_ORDENACAO_H
#define ALGORITMOS_ORDENACAO_H

#include "componente.h"

/**
 * @file algoritmos_ordenacao.h
 * @brief Interface dos algoritmos de ordenação
 *
 * Implementa três algoritmos clássicos de ordenação para diferentes
 * critérios de organização dos componentes.
 */

/**
 * @brief Ordena componentes por NOME usando Bubble Sort
 * @param componentes Array de componentes
 * @param n Quantidade de componentes
 * @param comparacoes Ponteiro para contador de comparações
 */
void bubbleSortNome(Componente componentes[], int n, int* comparacoes);

/**
 * @brief Ordena componentes por TIPO usando Insertion Sort
 * @param componentes Array de componentes
 * @param n Quantidade de componentes
 * @param comparacoes Ponteiro para contador de comparações
 */
void insertionSortTipo(Componente componentes[], int n, int* comparacoes);

/**
 * @brief Ordena componentes por PRIORIDADE usando Selection Sort
 * @param componentes Array de componentes
 * @param n Quantidade de componentes
 * @param comparacoes Ponteiro para contador de comparações
 */
void selectionSortPrioridade(Componente componentes[], int n, int* comparacoes);

#endif // ALGORITMOS_ORDENACAO_H