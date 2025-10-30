#ifndef INVENTARIO_VETOR_H
#define INVENTARIO_VETOR_H

#include "item.h"

/**
 * @file inventario_vetor.h
 * @brief Interface para gerenciamento do inventário usando VETOR (lista sequencial)
 *
 * Implementação da mochila usando array estático com operações básicas,
 * ordenação e busca binária.
 */

#define MAX_ITENS 10

/**
 * @brief Inicializa o inventário baseado em vetor
 */
void inicializarInventarioVetor();

/**
 * @brief Insere um novo item no vetor
 * @return 1 se inserido com sucesso, 0 caso contrário
 */
int inserirItemVetor();

/**
 * @brief Remove um item do vetor pelo nome
 * @return 1 se removido com sucesso, 0 caso contrário
 */
int removerItemVetor();

/**
 * @brief Lista todos os itens do vetor
 */
void listarItensVetor();

/**
 * @brief Busca sequencial no vetor
 * @param comparacoes Ponteiro para contador de comparações
 * @return 1 se encontrado, 0 caso contrário
 */
int buscarSequencialVetor(int* comparacoes);

/**
 * @brief Ordena os itens do vetor por nome (Bubble Sort)
 */
void ordenarVetor();

/**
 * @brief Busca binária no vetor (requer vetor ordenado)
 * @param comparacoes Ponteiro para contador de comparações
 * @return 1 se encontrado, 0 caso contrário
 */
int buscarBinariaVetor(int* comparacoes);

/**
 * @brief Verifica se o vetor está ordenado
 * @return 1 se ordenado, 0 caso contrário
 */
int estaOrdenado();

/**
 * @brief Retorna a quantidade atual de itens no vetor
 * @return Número de itens
 */
int obterQuantidadeItensVetor();

#endif // INVENTARIO_VETOR_H