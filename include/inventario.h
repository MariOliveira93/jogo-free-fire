#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "item.h"

/**
 * @file inventario.h
 * @brief Interface para gerenciamento do inventário do jogador
 *
 * Este arquivo contém as declarações das funções responsáveis
 * por manipular a mochila de itens do jogador.
 */

#define MAX_ITENS 10

/**
 * @brief Inicializa o sistema de inventário
 *
 * Configura o vetor de itens e define a quantidade inicial como zero.
 */
void inicializarInventario();

/**
 * @brief Insere um novo item no inventário
 *
 * Cadastra um item informando nome, tipo e quantidade.
 * Valida se há espaço disponível na mochila.
 *
 * @return 1 se o item foi inserido com sucesso, 0 caso contrário
 */
int inserirItem();

/**
 * @brief Remove um item do inventário pelo nome
 *
 * Busca o item pelo nome e o remove da mochila,
 * reorganizando os elementos restantes.
 *
 * @return 1 se o item foi removido com sucesso, 0 caso contrário
 */
int removerItem();

/**
 * @brief Lista todos os itens cadastrados no inventário
 *
 * Exibe uma tabela formatada com nome, tipo e quantidade
 * de cada item presente na mochila.
 */
void listarItens();

/**
 * @brief Busca um item no inventário pelo nome
 *
 * Implementa busca sequencial para localizar um item
 * específico e exibir seus dados completos.
 *
 * @return 1 se o item foi encontrado, 0 caso contrário
 */
int buscarItem();

/**
 * @brief Retorna a quantidade atual de itens no inventário
 *
 * @return Número de itens cadastrados
 */
int obterQuantidadeItens();

#endif // INVENTARIO_H