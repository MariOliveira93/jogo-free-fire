#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inventario_vetor.h"

/**
 * @file inventario_vetor.c
 * @brief Implementação do inventário usando VETOR (lista sequencial)
 *
 * Vantagens: acesso direto por índice, cache-friendly, busca binária
 * Desvantagens: tamanho fixo, reorganização custosa em remoções
 */

// Vetor global para armazenar os itens
static Item mochila[MAX_ITENS];
static int totalItens = 0;
static int ordenado = 0; // Flag para indicar se está ordenado

void inicializarInventarioVetor() {
    totalItens = 0;
    ordenado = 0;
    printf("\n=== [VETOR] Inventario inicializado! ===\n");
}

int inserirItemVetor() {
    if (totalItens >= MAX_ITENS) {
        printf("\n[ERRO] Mochila cheia! Capacidade: %d itens.\n", MAX_ITENS);
        return 0;
    }

    Item novoItem;
    printf("\n--- [VETOR] Cadastro de Item ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", novoItem.nome);
    printf("Tipo (arma/municao/cura/ferramenta): ");
    scanf(" %[^\n]", novoItem.tipo);
    printf("Quantidade: ");
    scanf("%d", &novoItem.quantidade);

    if (novoItem.quantidade <= 0) {
        printf("\n[ERRO] Quantidade deve ser > 0!\n");
        return 0;
    }

    mochila[totalItens] = novoItem;
    totalItens++;
    ordenado = 0; // Marca como não ordenado após inserção

    printf("\n[SUCESSO] Item '%s' cadastrado!\n", novoItem.nome);
    return 1;
}

int removerItemVetor() {
    if (totalItens == 0) {
        printf("\n[AVISO] Mochila vazia!\n");
        return 0;
    }

    char nomeItem[MAX_NOME];
    printf("\n--- [VETOR] Remocao de Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", nomeItem);

    int indice = -1;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeItem) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n[ERRO] Item '%s' nao encontrado!\n", nomeItem);
        return 0;
    }

    // Reorganiza o vetor (operação custosa)
    for (int i = indice; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;
    printf("\n[SUCESSO] Item '%s' removido!\n", nomeItem);
    return 1;
}

void listarItensVetor() {
    printf("\n========================================\n");
    printf("      [VETOR] MOCHILA DE LOOT\n");
    printf("========================================\n");

    if (totalItens == 0) {
        printf("  >> Mochila vazia! <<\n");
        printf("========================================\n");
        return;
    }

    printf("Total: %d/%d | Ordenado: %s\n", 
           totalItens, MAX_ITENS, ordenado ? "SIM" : "NAO");
    printf("----------------------------------------\n");
    printf("%-20s %-15s %s\n", "NOME", "TIPO", "QTD");
    printf("----------------------------------------\n");

    for (int i = 0; i < totalItens; i++) {
        printf("%-20s %-15s %d\n", 
               mochila[i].nome, 
               mochila[i].tipo, 
               mochila[i].quantidade);
    }

    printf("========================================\n");
}

int buscarSequencialVetor(int* comparacoes) {
    if (totalItens == 0) {
        printf("\n[AVISO] Mochila vazia!\n");
        return 0;
    }

    char nomeItem[MAX_NOME];
    printf("\n--- [VETOR] Busca Sequencial ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", nomeItem);

    *comparacoes = 0;

    // Busca sequencial: percorre todo o vetor
    for (int i = 0; i < totalItens; i++) {
        (*comparacoes)++;
        if (strcmp(mochila[i].nome, nomeItem) == 0) {
            printf("\n[ITEM ENCONTRADO - Busca Sequencial]\n");
            printf("Nome:       %s\n", mochila[i].nome);
            printf("Tipo:       %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            printf("Posicao:    %d\n", i + 1);
            printf("Comparacoes: %d\n", *comparacoes);
            return 1;
        }
    }

    printf("\n[ERRO] Item '%s' nao encontrado!\n", nomeItem);
    printf("Comparacoes realizadas: %d\n", *comparacoes);
    return 0;
}

void ordenarVetor() {
    if (totalItens == 0) {
        printf("\n[AVISO] Mochila vazia!\n");
        return;
    }

    printf("\n--- [VETOR] Ordenando itens (Bubble Sort) ---\n");

    // Bubble Sort: ordena por nome
    for (int i = 0; i < totalItens - 1; i++) {
        for (int j = 0; j < totalItens - i - 1; j++) {
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                // Troca os itens
                Item temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }

    ordenado = 1;
    printf("[SUCESSO] Itens ordenados alfabeticamente!\n");
}

int buscarBinariaVetor(int* comparacoes) {
    if (totalItens == 0) {
        printf("\n[AVISO] Mochila vazia!\n");
        return 0;
    }

    if (!ordenado) {
        printf("\n[ERRO] Vetor nao ordenado! Execute a ordenacao primeiro.\n");
        return 0;
    }

    char nomeItem[MAX_NOME];
    printf("\n--- [VETOR] Busca Binaria ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", nomeItem);

    *comparacoes = 0;

    // Busca binária: divide e conquista
    int esquerda = 0;
    int direita = totalItens - 1;

    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(mochila[meio].nome, nomeItem);

        if (cmp == 0) {
            // Item encontrado
            printf("\n[ITEM ENCONTRADO - Busca Binaria]\n");
            printf("Nome:       %s\n", mochila[meio].nome);
            printf("Tipo:       %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);
            printf("Posicao:    %d\n", meio + 1);
            printf("Comparacoes: %d\n", *comparacoes);
            return 1;
        } else if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    printf("\n[ERRO] Item '%s' nao encontrado!\n", nomeItem);
    printf("Comparacoes realizadas: %d\n", *comparacoes);
    return 0;
}

int estaOrdenado() {
    return ordenado;
}

int obterQuantidadeItensVetor() {
    return totalItens;
}