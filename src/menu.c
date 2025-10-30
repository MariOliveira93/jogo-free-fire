#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "inventario.h"

/**
 * @file menu.c
 * @brief Implementação do sistema de menu interativo
 * 
 * Controla o fluxo de execução do programa através de um menu
 * com opções claras e orientativas.
 */

void exibirMenu() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║     FREE FIRE - INVENTARIO DE LOOT     ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("  [1] Cadastrar item\n");
    printf("  [2] Remover item\n");
    printf("  [3] Listar itens\n");
    printf("  [4] Buscar item\n");
    printf("  [0] Sair\n");
    printf("----------------------------------------\n");
    printf("  Escolha uma opcao: ");
}

void executarMenu() {
    int opcao;
    int executando = 1;
    
    // Inicializa o sistema de inventário
    inicializarInventario();
    
    // Loop principal do programa
    while (executando) {
        exibirMenu();
        scanf("%d", &opcao);
        
        // Limpa o buffer de entrada
        while (getchar() != '\n');
        
        switch (opcao) {
            case 1:
                inserirItem();
                listarItens(); // Lista itens após cadastro
                break;
                
            case 2:
                removerItem();
                listarItens(); // Lista itens após remoção
                break;
                
            case 3:
                listarItens();
                break;
                
            case 4:
                buscarItem();
                break;
                
            case 0:
                printf("\n");
                printf("╔════════════════════════════════════════╗\n");
                printf("║   Obrigado por jogar! Ate a proxima!  ║\n");
                printf("╚════════════════════════════════════════╝\n");
                executando = 0;
                break;
                
            default:
                printf("\n[ERRO] Opcao invalida! Escolha entre 0 e 4.\n");
                break;
        }
        
        // Pausa para o usuário visualizar as mensagens
        if (executando && opcao >= 0 && opcao <= 4) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
    }
}