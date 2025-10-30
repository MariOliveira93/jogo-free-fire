
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "inventario_vetor.h"
#include "inventario_lista.h"
#include "comparador.h"
#include "torre_resgate.h"
#include "medidor_performance.h"

/**
 * @file menu.c
 * @brief Implementação do sistema de menu interativo - Versão 3.0 FINAL
 *
 * Sistema completo com três níveis de desafio e menu da Torre de Resgate
 */

// ============================================================================
// FUNÇÕES DE EXIBIÇÃO DE MENUS
// ============================================================================

void exibirMenuPrincipal() {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║              FREE FIRE - ESTRUTURAS DE DADOS               ║\n");
    printf("║                    MISSAO COMPLETA                         ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("  [1] Nivel 1: VETOR (Lista Sequencial)\n");
    printf("  [2] Nivel 1: LISTA ENCADEADA\n");
    printf("  [3] Nivel 2: Analise Comparativa\n");
    printf("  [4] Nivel 3: TORRE DE RESGATE (Missao Final)\n");
    printf("  [5] Analise de Complexidade\n");
    printf("  [0] Sair\n");
    printf("────────────────────────────────────────────────────────────\n");
    printf("  Escolha uma opcao: ");
}

void exibirMenuVetor() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║      [VETOR] INVENTARIO DE LOOT        ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("  [1] Cadastrar item\n");
    printf("  [2] Remover item\n");
    printf("  [3] Listar itens\n");
    printf("  [4] Buscar (Sequencial)\n");
    printf("  [5] Ordenar itens\n");
    printf("  [6] Buscar (Binaria)\n");
    printf("  [7] Comparar buscas\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------\n");
    printf("  Escolha uma opcao: ");
}

void exibirMenuLista() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║      [LISTA] INVENTARIO DE LOOT        ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("  [1] Cadastrar item\n");
    printf("  [2] Remover item\n");
    printf("  [3] Listar itens\n");
    printf("  [4] Buscar (Sequencial)\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------\n");
    printf("  Escolha uma opcao: ");
}

void exibirMenuTorreResgate() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║      TORRE DE RESGATE - NIVEL 3        ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("  [1] Cadastrar componente\n");
    printf("  [2] Listar componentes\n");
    printf("  [3] Ordenar componentes\n");
    printf("  [4] Buscar componente-chave (binaria)\n");
    printf("  [5] Status da torre\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------\n");
    printf("  Escolha uma opcao: ");
}

// ============================================================================
// FUNÇÕES DE EXECUÇÃO DOS SUBMENUS
// ============================================================================

void executarMenuVetor() {
    int opcao;
    int executando = 1;

    inicializarInventarioVetor();

    while (executando) {
        exibirMenuVetor();
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                inserirItemVetor();
                listarItensVetor();
                break;

            case 2:
                removerItemVetor();
                listarItensVetor();
                break;

            case 3:
                listarItensVetor();
                break;

            case 4: {
                int comp = 0;
                buscarSequencialVetor(&comp);
                break;
            }

            case 5:
                ordenarVetor();
                listarItensVetor();
                break;

            case 6: {
                int comp = 0;
                buscarBinariaVetor(&comp);
                break;
            }

            case 7: {
                if (!estaOrdenado()) {
                    printf("\n[AVISO] Execute a ordenacao primeiro!\n");
                } else {
                    printf("\n[INFO] Use as opcoes 4 e 6 separadamente\n");
                    printf("para comparar as buscas no mesmo item.\n");
                }
                break;
            }

            case 0:
                printf("\n[INFO] Voltando ao menu principal...\n");
                executando = 0;
                break;

            default:
                printf("\n[ERRO] Opcao invalida!\n");
                break;
        }

        if (executando && opcao >= 0 && opcao <= 7) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
    }
}

void executarMenuLista() {
    int opcao;
    int executando = 1;

    inicializarInventarioLista();

    while (executando) {
        exibirMenuLista();
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                inserirItemLista();
                listarItensLista();
                break;

            case 2:
                removerItemLista();
                listarItensLista();
                break;

            case 3:
                listarItensLista();
                break;

            case 4: {
                int comp = 0;
                buscarSequencialLista(&comp);
                break;
            }

            case 0:
                printf("\n[INFO] Voltando ao menu principal...\n");
                liberarInventarioLista();
                executando = 0;
                break;

            default:
                printf("\n[ERRO] Opcao invalida!\n");
                break;
        }

        if (executando && opcao >= 0 && opcao <= 4) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
    }
}

void executarMenuTorreResgate() {
    int opcao;
    int executando = 1;

    inicializarTorreResgate();

    while (executando) {
        exibirMenuTorreResgate();
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrarComponente();
                break;

            case 2:
                listarComponentes();
                break;

            case 3:
                menuOrdenacao();
                break;

            case 4: {
                int comp = 0;
                buscaBinariaPorNome(&comp);
                break;
            }

            case 5:
                exibirStatusTorre();
                break;

            case 0:
                printf("\n[INFO] Voltando ao menu principal...\n");
                executando = 0;
                break;

            default:
                printf("\n[ERRO] Opcao invalida!\n");
                break;
        }

        if (executando && opcao >= 0 && opcao <= 5) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
    }
}

// ============================================================================
// FUNÇÃO PRINCIPAL DO MENU
// ============================================================================

void executarMenu() {
    int opcao;
    int executando = 1;

    while (executando) {
        exibirMenuPrincipal();
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                executarMenuVetor();
                break;

            case 2:
                executarMenuLista();
                break;

            case 3:
                exibirAnaliseEstruturas();
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;

            case 4:
                executarMenuTorreResgate();
                break;

            case 5:
                exibirAnaliseComplexidade();
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;

            case 0:
                printf("\n");
                printf("╔════════════════════════════════════════════════════════════╗\n");
                printf("║            MISSAO COMPLETA! PARABENS!                      ║\n");
                printf("║         Obrigado por jogar! Ate a proxima!                ║\n");
                printf("╚════════════════════════════════════════════════════════════╝\n");
                executando = 0;
                break;

            default:
                printf("\n[ERRO] Opcao invalida!\n");
                break;
        }
    }
}