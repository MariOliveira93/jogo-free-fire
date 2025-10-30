
#ifndef MEDIDOR_PERFORMANCE_H
#define MEDIDOR_PERFORMANCE_H

#include <time.h>

/**
 * @file medidor_performance.h
 * @brief Interface para medição de desempenho
 *
 * Fornece ferramentas para medir tempo de execução e
 * número de operações dos algoritmos.
 */

/**
 * @brief Estrutura para armazenar resultados de performance
 */
typedef struct {
    int comparacoes;
    double tempo_ms;
    char algoritmo[30];
} ResultadoPerformance;

/**
 * @brief Inicia a medição de tempo
 * @return Timestamp inicial
 */
clock_t iniciarMedicao();

/**
 * @brief Finaliza a medição e retorna tempo decorrido
 * @param inicio Timestamp inicial
 * @return Tempo em milissegundos
 */
double finalizarMedicao(clock_t inicio);

/**
 * @brief Exibe comparativo de desempenho entre algoritmos
 * @param resultados Array de resultados
 * @param quantidade Número de resultados
 */
void exibirComparativoAlgoritmos(ResultadoPerformance resultados[], int quantidade);

/**
 * @brief Exibe análise da complexidade dos algoritmos
 */
void exibirAnaliseComplexidade();

#endif // MEDIDOR_PERFORMANCE_H