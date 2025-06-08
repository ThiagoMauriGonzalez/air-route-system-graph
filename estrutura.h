#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "meustipos.h"

#define TAM_CODIGO 4
#define TAM_CIDADE 100

typedef struct{
    char codigo[TAM_CODIGO];
    char cidade[TAM_CIDADE];
} Aeroporto;

typedef struct {
    Aeroporto* aeroportos;  // Vetor dinâmico de aeroportos
    U32** voos;             // Matriz de adjacência (número do voo ou 0)
    U32 qtdAeroportos;      // Quantidade atual de aeroportos
    U32 capacidade;         // Capacidade alocada
} MalhaAerea;

void inicializarMalha(MalhaAerea* malha);
void liberarMalha(MalhaAerea* malha);

#endif

