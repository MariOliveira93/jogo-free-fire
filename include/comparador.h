#ifndef COMPARADOR_H
#define COMPARADOR_H

/**
 * @file comparador.h
 * @brief Interface para comparação de desempenho entre estruturas
 *
 * Fornece ferramentas para análise empírica das diferenças entre
 * vetor e lista encadeada em operações críticas.
 */

/**
 * @brief Exibe comparativo de desempenho entre busca sequencial e binária
 * @param compSeq Número de comparações na busca sequencial
 * @param compBin Número de comparações na busca binária
 */
void exibirComparativo(int compSeq, int compBin);

/**
 * @brief Exibe análise das características de cada estrutura
 */
void exibirAnaliseEstruturas();

#endif // COMPARADOR_H