#ifndef TORRE_RESGATE_H
#define TORRE_RESGATE_H

#include "componente.h"

/**
 * @file torre_resgate.h
 * @brief Interface do sistema da Torre de Resgate
 *
 * Gerencia os componentes necessários para a missão final,
 * permitindo cadastro, ordenação e busca do componente-chave.
 */

/**
 * @brief Inicializa o sistema da torre de resgate
 */
void inicializarTorreResgate();

/**
 * @brief Cadastra um novo componente
 * @return 1 se cadastrado com sucesso, 0 caso contrário
 */
int cadastrarComponente();

/**
 * @brief Lista todos os componentes cadastrados
 */
void listarComponentes();

/**
 * @brief Busca binária por nome (requer ordenação por nome)
 * @param comparacoes Ponteiro para contador de comparações
 * @return 1 se encontrado, 0 caso contrário
 */
int buscaBinariaPorNome(int* comparacoes);

/**
 * @brief Menu de ordenação dos componentes
 */
void menuOrdenacao();

/**
 * @brief Verifica se há componentes cadastrados
 * @return 1 se há componentes, 0 caso contrário
 */
int temComponentes();

/**
 * @brief Exibe status da torre de resgate
 */
void exibirStatusTorre();

/**
 * @brief Retorna quantidade de componentes cadastrados
 * @return Número de componentes
 */
int obterQuantidadeComponentes();

#endif // TORRE_RESGATE_H