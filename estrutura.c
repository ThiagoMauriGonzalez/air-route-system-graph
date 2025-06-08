#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

#define CAPACIDADE_INICIAL 5

void inicializarMalha(MalhaAerea* malha) {
    malha->qtdAeroportos = 0;
    malha->capacidade = CAPACIDADE_INICIAL;

    malha->aeroportos = (Aeroporto*) malloc(sizeof(Aeroporto) * malha->capacidade);

    malha->voos = (U32**) malloc(sizeof(U32*) * malha->capacidade);
    for (U32 i = 0; i < malha->capacidade; i++) {
        malha->voos[i] = (U32*) calloc(malha->capacidade, sizeof(U32));
    }
}

void liberarMalha(MalhaAerea* malha) {
    for (U32 i = 0; i < malha->capacidade; i++) {
        free(malha->voos[i]);
    }
    free(malha->voos);
    free(malha->aeroportos);
}
