#include <stdio.h>
#include <string.h>
#include <time.h>
#include "torre_resgate.h"
#include "algoritmos_ordenacao.h"
#include "medidor_performance.h"

/**
 * @file torre_resgate.c
 * @brief Implementação do sistema da Torre de Resgate
 *
 * Sistema final do jogo que utiliza múltiplos algoritmos de ordenação
 * e busca binária para organizar componentes críticos.
 */

// Array global de componentes
static Componente componentes[MAX_COMPONENTES];
static int totalComponentes = 0;
static int ordenadoPorNome = 0;

void inicializarTorreResgate() {
    totalComponentes = 0;
    ordenadoPorNome = 0;
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║              TORRE DE RESGATE INICIALIZADA                 ║\n");
    printf("║                   MISSAO FINAL                             ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("  >> Colete e organize os componentes para escapar da ilha!\n");
    printf("  >> Capacidade maxima: %d componentes\n", MAX_COMPONENTES);
    printf("\n");
}

int cadastrarComponente() {
    if (totalComponentes >= MAX_COMPONENTES) {
        printf("\n[ERRO] Limite de componentes atingido! (%d)\n", MAX_COMPONENTES);
        return 0;
    }

    Componente novo;
    
    printf("\n--- Cadastro de Componente ---\n");
    printf("Nome do componente: ");
    fgets(novo.nome, MAX_NOME_COMP, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0; // Remove newline
    
    printf("Tipo (controle/suporte/propulsao): ");
    fgets(novo.tipo, MAX_TIPO_COMP, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = 0;
    
    printf("Prioridade (1-10, onde 10 é crítico): ");
    scanf("%d", &novo.prioridade);
    while (getchar() != '\n'); // Limpa buffer
    
    // Validação
    if (novo.prioridade < 1 || novo.prioridade > 10) {
        printf("\n[ERRO] Prioridade deve estar entre 1 e 10!\n");
        return 0;
    }
    
    componentes[totalComponentes] = novo;
    totalComponentes++;
    ordenadoPorNome = 0;
    
    printf("\n[SUCESSO] Componente '%s' cadastrado!\n", novo.nome);
    printf("         Tipo: %s | Prioridade: %d\n", novo.tipo, novo.prioridade);
    
    return 1;
}

void listarComponentes() {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║            COMPONENTES DA TORRE DE RESGATE                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    if (totalComponentes == 0) {
        printf("\n  >> Nenhum componente cadastrado! <<\n");
        printf("\n");
        return;
    }
    
    printf("\n  Total: %d/%d componentes\n", totalComponentes, MAX_COMPONENTES);
    printf("  Ordenado por nome: %s\n", ordenadoPorNome ? "SIM" : "NAO");
    printf("\n");
    printf("┌──────────────────────────┬──────────────────┬────────────┐\n");
    printf("│ NOME                     │ TIPO             │ PRIORIDADE │\n");
    printf("├──────────────────────────┼──────────────────┼────────────┤\n");
    
    for (int i = 0; i < totalComponentes; i++) {
        printf("│ %-24s │ %-16s │ %10d │\n",
               componentes[i].nome,
               componentes[i].tipo,
               componentes[i].prioridade);
    }
    
    printf("└──────────────────────────┴──────────────────┴────────────┘\n");
    printf("\n");
}

int buscaBinariaPorNome(int* comparacoes) {
    if (totalComponentes == 0) {
        printf("\n[AVISO] Nenhum componente cadastrado!\n");
        return 0;
    }
    
    if (!ordenadoPorNome) {
        printf("\n[ERRO] Componentes nao ordenados por nome!\n");
        printf("Execute a ordenacao por nome (Bubble Sort) primeiro.\n");
        return 0;
    }
    
    char nomeBusca[MAX_NOME_COMP];
    printf("\n--- Busca Binaria por Nome ---\n");
    printf("Nome do componente-chave: ");
    fgets(nomeBusca, MAX_NOME_COMP, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    
    *comparacoes = 0;
    int esquerda = 0;
    int direita = totalComponentes - 1;
    
    clock_t inicio = iniciarMedicao();
    
    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(componentes[meio].nome, nomeBusca);
        
        if (cmp == 0) {
            double tempo = finalizarMedicao(inicio);
            
            // Componente encontrado!
            printf("\n");
            printf("╔════════════════════════════════════════════════════════════╗\n");
            printf("║          COMPONENTE-CHAVE ENCONTRADO!                      ║\n");
            printf("╚════════════════════════════════════════════════════════════╝\n");
            printf("\n");
            printf("  Nome:       %s\n", componentes[meio].nome);
            printf("  Tipo:       %s\n", componentes[meio].tipo);
            printf("  Prioridade: %d\n", componentes[meio].prioridade);
            printf("  Posicao:    %d\n", meio + 1);
            printf("\n");
            printf("  [DESEMPENHO]\n");
            printf("  Comparacoes: %d\n", *comparacoes);
            printf("  Tempo:       %.6f ms\n", tempo);
            printf("\n");
            printf("  >> Torre de Resgate pronta para ativacao! <<\n");
            printf("\n");
            
            return 1;
        } else if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    double tempo = finalizarMedicao(inicio);
    
    printf("\n[ERRO] Componente '%s' nao encontrado!\n", nomeBusca);
    printf("Comparacoes: %d | Tempo: %.6f ms\n", *comparacoes, tempo);
    
    return 0;
}

void menuOrdenacao() {
    if (totalComponentes == 0) {
        printf("\n[AVISO] Nenhum componente para ordenar!\n");
        return;
    }
    
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║      ESCOLHA O CRITERIO DE ORDENACAO   ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("  [1] Por NOME (Bubble Sort)\n");
    printf("  [2] Por TIPO (Insertion Sort)\n");
    printf("  [3] Por PRIORIDADE (Selection Sort)\n");
    printf("  [4] Comparar todos os algoritmos\n");
    printf("  [0] Cancelar\n");
    printf("----------------------------------------\n");
    printf("  Escolha: ");
    
    int opcao;
    scanf("%d", &opcao);
    while (getchar() != '\n');
    
    int comparacoes = 0;
    clock_t inicio;
    double tempo;
    
    // Cria cópia para não perder dados originais
    Componente copia[MAX_COMPONENTES];
    memcpy(copia, componentes, sizeof(Componente) * totalComponentes);
    
    switch (opcao) {
        case 1:
            printf("\n--- Ordenando por NOME (Bubble Sort) ---\n");
            inicio = iniciarMedicao();
            bubbleSortNome(componentes, totalComponentes, &comparacoes);
            tempo = finalizarMedicao(inicio);
            ordenadoPorNome = 1;
            
            printf("\n[SUCESSO] Componentes ordenados por nome!\n");
            printf("Comparacoes: %d\n", comparacoes);
            printf("Tempo: %.6f ms\n", tempo);
            printf("\n>> Busca binaria agora disponivel! <<\n");
            listarComponentes();
            break;
            
        case 2:
            printf("\n--- Ordenando por TIPO (Insertion Sort) ---\n");
            inicio = iniciarMedicao();
            insertionSortTipo(componentes, totalComponentes, &comparacoes);
            tempo = finalizarMedicao(inicio);
            ordenadoPorNome = 0;
            
            printf("\n[SUCESSO] Componentes ordenados por tipo!\n");
            printf("Comparacoes: %d\n", comparacoes);
            printf("Tempo: %.6f ms\n", tempo);
            listarComponentes();
            break;
            
        case 3:
            printf("\n--- Ordenando por PRIORIDADE (Selection Sort) ---\n");
            inicio = iniciarMedicao();
            selectionSortPrioridade(componentes, totalComponentes, &comparacoes);
            tempo = finalizarMedicao(inicio);
            ordenadoPorNome = 0;
            
            printf("\n[SUCESSO] Componentes ordenados por prioridade!\n");
            printf("Comparacoes: %d\n", comparacoes);
            printf("Tempo: %.6f ms\n", tempo);
            printf("\n>> Componentes criticos aparecem primeiro! <<\n");
            listarComponentes();
            break;
            
        case 4: {
            printf("\n--- Comparando todos os algoritmos ---\n");
            ResultadoPerformance resultados[3];
            
            // Bubble Sort
            Componente temp1[MAX_COMPONENTES];
            memcpy(temp1, copia, sizeof(Componente) * totalComponentes);
            strcpy(resultados[0].algoritmo, "Bubble Sort (nome)");
            inicio = iniciarMedicao();
            bubbleSortNome(temp1, totalComponentes, &resultados[0].comparacoes);
            resultados[0].tempo_ms = finalizarMedicao(inicio);
            
            // Insertion Sort
            Componente temp2[MAX_COMPONENTES];
            memcpy(temp2, copia, sizeof(Componente) * totalComponentes);
            strcpy(resultados[1].algoritmo, "Insertion Sort (tipo)");
            inicio = iniciarMedicao();
            insertionSortTipo(temp2, totalComponentes, &resultados[1].comparacoes);
            resultados[1].tempo_ms = finalizarMedicao(inicio);
            
            // Selection Sort
            Componente temp3[MAX_COMPONENTES];
            memcpy(temp3, copia, sizeof(Componente) * totalComponentes);
            strcpy(resultados[2].algoritmo, "Selection Sort (prior)");
            inicio = iniciarMedicao();
            selectionSortPrioridade(temp3, totalComponentes, &resultados[2].comparacoes);
            resultados[2].tempo_ms = finalizarMedicao(inicio);
            
            exibirComparativoAlgoritmos(resultados, 3);
            
            // Mantém dados originais
            memcpy(componentes, copia, sizeof(Componente) * totalComponentes);
            break;
        }
            
        case 0:
            printf("\n[INFO] Operacao cancelada.\n");
            break;
            
        default:
            printf("\n[ERRO] Opcao invalida!\n");
            break;
    }
}

int temComponentes() {
    return totalComponentes > 0;
}

void exibirStatusTorre() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║     STATUS DA TORRE DE RESGATE         ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n");
    printf("  Componentes: %d/%d\n", totalComponentes, MAX_COMPONENTES);
    printf("  Ordenado:    %s\n", ordenadoPorNome ? "SIM (por nome)" : "NAO");
    printf("\n");
    
    if (totalComponentes >= 5) {
        printf("  >> Status: PRONTO PARA MONTAGEM <<\n");
    } else if (totalComponentes > 0) {
        printf("  >> Status: EM PROGRESSO (%d faltam) <<\n", 5 - totalComponentes);
    } else {
        printf("  >> Status: AGUARDANDO COMPONENTES <<\n");
    }
    printf("\n");
}

int obterQuantidadeComponentes() {
    return totalComponentes;
}