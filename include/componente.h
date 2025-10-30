#ifndef COMPONENTE_H
#define COMPONENTE_H

/**
 * @file componente.h
 * @brief Definição da estrutura Componente para a Torre de Resgate
 *
 * Representa os componentes necessários para montar a torre de fuga
 * na missão final do jogo.
 */

#define MAX_NOME_COMP 30
#define MAX_TIPO_COMP 20
#define MAX_COMPONENTES 20

/**
 * @struct Componente
 * @brief Representa um componente da torre de resgate
 *
 * @var Componente::nome
 * Nome do componente (ex: "chip central", "propulsor")
 *
 * @var Componente::tipo
 * Tipo do componente (ex: "controle", "suporte", "propulsao")
 *
 * @var Componente::prioridade
 * Prioridade de montagem (1 a 10, onde 10 é crítico)
 */
typedef struct {
    char nome[MAX_NOME_COMP];
    char tipo[MAX_TIPO_COMP];
    int prioridade;
} Componente;

#endif // COMPONENTE_H