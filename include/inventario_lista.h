
#ifndef INVENTARIO_LISTA_H
#define INVENTARIO_LISTA_H

#include "item.h"

/**
 * @file inventario_lista.h
 * @brief Interface para gerenciamento do inventário usando LISTA ENCADEADA
 *
 * Implementação da mochila usando estrutura dinâmica com alocação de memória,
 * permitindo maior flexibilidade nas operações.
 */

/**
 * @brief Inicializa o inventário baseado em lista encadeada
 */
void inicializarInventarioLista();

/**
 * @brief Insere um novo item na lista encadeada
 * @return 1 se inserido com sucesso, 0 caso contrário
 */
int inserirItemLista();

/**
 * @brief Remove um item da lista pelo nome
 * @return 1 se removido com sucesso, 0 caso contrário
 */
int removerItemLista();

/**
 * @brief Lista todos os itens da lista encadeada
 */
void listarItensLista();

/**
 * @brief Busca sequencial na lista encadeada
 * @param comparacoes Ponteiro para contador de comparações
 * @return 1 se encontrado, 0 caso contrário
 */
int buscarSequencialLista(int* comparacoes);

/**
 * @brief Retorna a quantidade atual de itens na lista
 * @return Número de itens
 */
int obterQuantidadeItensLista();

/**
 * @brief Libera toda a memória alocada pela lista encadeada
 */
void liberarInventarioLista();

#endif // INVENTARIO_LISTA_H