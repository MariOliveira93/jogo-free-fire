
#ifndef MENU_H
#define MENU_H

/**
 * @file menu.h
 * @brief Interface do menu principal do sistema
 *
 * Gerencia a interação com o usuário através de menus hierárquicos
 * para as três fases do jogo.
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
 * @brief Exibe o menu da torre de resgate (Nível 3)
 */
void exibirMenuTorreResgate();

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

/**
 * @brief Executa o submenu da torre de resgate
 */
void executarMenuTorreResgate();

#endif // MENU_H