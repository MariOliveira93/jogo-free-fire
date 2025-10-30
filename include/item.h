
#ifndef ITEM_H
#define ITEM_H

/**
 * @file item.h
 * @brief Definição das estruturas de dados para itens do inventário
 *
 * Este arquivo contém a definição da struct Item e da struct No
 * para uso em lista encadeada.
 */

#define MAX_NOME 30
#define MAX_TIPO 20

/**
 * @struct Item
 * @brief Representa um item do inventário do jogador
 *
 * @var Item::nome
 * Nome do item (ex: "M4A1", "Kit Médico")
 *
 * @var Item::tipo
 * Categoria do item (ex: "arma", "munição", "cura")
 *
 * @var Item::quantidade
 * Quantidade do item no inventário
 */
typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
} Item;

/**
 * @struct No
 * @brief Representa um nó da lista encadeada
 *
 * Estrutura usada para implementar a mochila como lista dinâmica,
 * permitindo inserções e remoções mais eficientes.
 *
 * @var No::dados
 * Item armazenado no nó
 *
 * @var No::proximo
 * Ponteiro para o próximo nó da lista
 */
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

#endif // ITEM_H