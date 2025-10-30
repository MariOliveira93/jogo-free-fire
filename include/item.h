#ifndef ITEM_H
#define ITEM_H

/**
 * @file item.h
 * @brief Definição da estrutura de dados para itens do inventário
 *
 * Este arquivo contém a definição da struct Item, que representa
 * cada objeto coletado pelo jogador no jogo.
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

#endif // ITEM_H