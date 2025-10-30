
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inventario.h"

/**
 * @file inventario.c
 * @brief Implementação das funções de gerenciamento do inventário
 * 
 * Este arquivo contém a lógica de manipulação da mochila de itens,
 * incluindo inserção, remoção, listagem e busca.
 */

// Vetor global para armazenar os itens do inventário
static Item mochila[MAX_ITENS];

// Contador de itens atualmente no inventário
static int totalItens = 0;

void inicializarInventario() {
    totalItens = 0;
    printf("\n=== Inventario inicializado com sucesso! ===\n");
}

int inserirItem() {
    // Verifica se há espaço disponível na mochila
    if (totalItens >= MAX_ITENS) {
        printf("\n[ERRO] Mochila cheia! Capacidade maxima: %d itens.\n", MAX_ITENS);
        return 0;
    }

    Item novoItem;
    
    printf("\n--- Cadastro de Novo Item ---\n");
    
    // Leitura do nome do item
    printf("Nome do item: ");
    scanf(" %[^\n]", novoItem.nome);
    
    // Leitura do tipo do item
    printf("Tipo (arma/municao/cura/ferramenta): ");
    scanf(" %[^\n]", novoItem.tipo);
    
    // Leitura da quantidade
    printf("Quantidade: ");
    scanf("%d", &novoItem.quantidade);
    
    // Validação da quantidade
    if (novoItem.quantidade <= 0) {
        printf("\n[ERRO] Quantidade deve ser maior que zero!\n");
        return 0;
    }
    
    // Adiciona o item ao vetor
    mochila[totalItens] = novoItem;
    totalItens++;
    
    printf("\n[SUCESSO] Item '%s' cadastrado com sucesso!\n", novoItem.nome);
    return 1;
}

int removerItem() {
    if (totalItens == 0) {
        printf("\n[AVISO] Mochila vazia! Nenhum item para remover.\n");
        return 0;
    }
    
    char nomeItem[MAX_NOME];
    
    printf("\n--- Remocao de Item ---\n");
    printf("Nome do item a remover: ");
    scanf(" %[^\n]", nomeItem);
    
    // Busca sequencial pelo item
    int indiceEncontrado = -1;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeItem) == 0) {
            indiceEncontrado = i;
            break;
        }
    }
    
    // Verifica se o item foi encontrado
    if (indiceEncontrado == -1) {
        printf("\n[ERRO] Item '%s' nao encontrado na mochila!\n", nomeItem);
        return 0;
    }
    
    // Remove o item reorganizando o vetor
    for (int i = indiceEncontrado; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    
    totalItens--;
    
    printf("\n[SUCESSO] Item '%s' removido com sucesso!\n", nomeItem);
    return 1;
}

void listarItens() {
    printf("\n");
    printf("========================================\n");
    printf("         MOCHILA DE LOOT INICIAL        \n");
    printf("========================================\n");
    
    if (totalItens == 0) {
        printf("  >> Mochila vazia! Colete itens! <<\n");
        printf("========================================\n");
        return;
    }
    
    printf("Total de itens: %d/%d\n", totalItens, MAX_ITENS);
    printf("----------------------------------------\n");
    printf("%-20s %-15s %s\n", "NOME", "TIPO", "QTD");
    printf("----------------------------------------\n");
    
    // Percorre e exibe todos os itens
    for (int i = 0; i < totalItens; i++) {
        printf("%-20s %-15s %d\n", 
               mochila[i].nome, 
               mochila[i].tipo, 
               mochila[i].quantidade);
    }
    
    printf("========================================\n");
}

int buscarItem() {
    if (totalItens == 0) {
        printf("\n[AVISO] Mochila vazia! Nenhum item para buscar.\n");
        return 0;
    }
    
    char nomeItem[MAX_NOME];
    
    printf("\n--- Busca de Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", nomeItem);
    
    // Implementação de busca sequencial
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeItem) == 0) {
            printf("\n[ITEM ENCONTRADO]\n");
            printf("----------------------------------------\n");
            printf("Nome:       %s\n", mochila[i].nome);
            printf("Tipo:       %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            printf("Posicao:    %d\n", i + 1);
            printf("----------------------------------------\n");
            return 1;
        }
    }
    
    printf("\n[ERRO] Item '%s' nao encontrado na mochila!\n", nomeItem);
    return 0;
}

int obterQuantidadeItens() {
    return totalItens;
}