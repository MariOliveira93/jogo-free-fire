#ifndef MENU_H
#define MENU_H

/**
 * @file menu.h
 * @brief Interface do menu principal do sistema
 *
 * Gerencia a interação com o usuário, permitindo escolher entre
 * implementação com vetor ou lista encadeada.
 */

/**
 * @brief Exibe o menu de seleção de estrutura de dados
 */
void exibirMenuPrincipal();

/**
 * @brief Exibe o menu de operações do vetor
 */
void exibirMenuVetor();

/**
 * @brief Exibe o menu de operações da lista encadeada
 */
void exibirMenuLista();

/**
 * @brief Executa o loop principal do programa
 */
void executarMenu();

/**
 * @brief Executa o submenu do inventário com vetor
 */
void executarMenuVetor();

/**
 * @brief Executa o submenu do inventário com lista encadeada
 */
void executarMenuLista();

#endif // MENU_H