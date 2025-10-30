#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inventario_lista.h"

/**
 * @file inventario_lista.c
 * @brief Implementação do inventário usando LISTA ENCADEADA
 *
 * Vantagens: tamanho dinâmico, inserção/remoção eficiente
 * Desvantagens: acesso sequencial, uso adicional de memória para ponteiros
 */

// Ponteiro para o início da lista
static No* inicio = NULL;
static int totalItens = 0;

void inicializarInventarioLista() {
    // Libera memória se já houver itens
    liberarInventarioLista();
    inicio = NULL;
    totalItens = 0;
    printf("\n=== [LISTA] Inventario inicializado! ===\n");
}

int inserirItemLista() {
    Item novoItem;
    printf("\n--- [LISTA] Cadastro de Item ---\n");
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

    // Aloca memória para novo nó
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("\n[ERRO] Falha ao alocar memoria!\n");
        return 0;
    }

    novoNo->dados = novoItem;
    novoNo->proximo = NULL;

    // Insere no final da lista
    if (inicio == NULL) {
        inicio = novoNo;
    } else {
        No* atual = inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }

    totalItens++;
    printf("\n[SUCESSO] Item '%s' cadastrado!\n", novoItem.nome);
    return 1;
}

int removerItemLista() {
    if (inicio == NULL) {
        printf("\n[AVISO] Mochila vazia!\n");
        return 0;
    }

    char nomeItem[MAX_NOME];
    printf("\n--- [LISTA] Remocao de Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", nomeItem);

    No* atual = inicio;
    No* anterior = NULL;

    // Busca o item na lista
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nomeItem) == 0) {
            // Remove o nó
            if (anterior == NULL) {
                // Remove o primeiro nó
                inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual); // Libera memória
            totalItens--;
            printf("\n[SUCESSO] Item '%s' removido!\n", nomeItem);
            return 1;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("\n[ERRO] Item '%s' nao encontrado!\n", nomeItem);
    return 0;
}

void listarItensLista() {
    printf("\n========================================\n");
    printf("      [LISTA] MOCHILA DE LOOT\n");
    printf("========================================\n");

    if (inicio == NULL) {
        printf("  >> Mochila vazia! <<\n");
        printf("========================================\n");
        return;
    }

    printf("Total de itens: %d\n", totalItens);
    printf("----------------------------------------\n");
    printf("%-20s %-15s %s\n", "NOME", "TIPO", "QTD");
    printf("----------------------------------------\n");

    No* atual = inicio;
    while (atual != NULL) {
        printf("%-20s %-15s %d\n", 
               atual->dados.nome, 
               atual->dados.tipo, 
               atual->dados.quantidade);
        atual = atual->proximo;
    }

    printf("========================================\n");
}

int buscarSequencialLista(int* comparacoes) {
    if (inicio == NULL) {
        printf("\n[AVISO] Mochila vazia!\n");
        return 0;
    }

    char nomeItem[MAX_NOME];
    printf("\n--- [LISTA] Busca Sequencial ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", nomeItem);

    *comparacoes = 0;
    No* atual = inicio;
    int posicao = 1;

    // Percorre a lista encadeada
    while (atual != NULL) {
        (*comparacoes)++;
        if (strcmp(atual->dados.nome, nomeItem) == 0) {
            printf("\n[ITEM ENCONTRADO - Lista Encadeada]\n");
            printf("Nome:       %s\n", atual->dados.nome);
            printf("Tipo:       %s\n", atual->dados.tipo);
            printf("Quantidade: %d\n", atual->dados.quantidade);
            printf("Posicao:    %d\n", posicao);
            printf("Comparacoes: %d\n", *comparacoes);
            return 1;
        }
        atual = atual->proximo;
        posicao++;
    }

    printf("\n[ERRO] Item '%s' nao encontrado!\n", nomeItem);
    printf("Comparacoes realizadas: %d\n", *comparacoes);
    return 0;
}

int obterQuantidadeItensLista() {
    return totalItens;
}

void liberarInventarioLista() {
    No* atual = inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    inicio = NULL;
    totalItens = 0;
}