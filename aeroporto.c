#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aeroporto.h"


boolean cadastrarAeroporto(MalhaAerea* malha, const char* codigo, const char* cidade) {
    // Verifica se já existe um aeroporto com o mesmo código
    if (buscarIndiceAeroporto(malha, codigo) != -1) {
        return false;
    }

    // Redimensiona se necessário
    if (malha->qtdAeroportos >= malha->capacidade) {
        U32 novaCapacidade = malha->capacidade * 2;

        malha->aeroportos = realloc(malha->aeroportos, novaCapacidade * sizeof(Aeroporto));

        // Redimensiona linhas existentes
        for (U32 i = 0; i < malha->capacidade; i++) {
            malha->voos[i] = realloc(malha->voos[i], novaCapacidade * sizeof(U32));
            for (U32 j = malha->capacidade; j < novaCapacidade; j++) {
                malha->voos[i][j] = 0;
            }
        }

        // Cria novas linhas
        malha->voos = realloc(malha->voos, novaCapacidade * sizeof(U32*));
        for (U32 i = malha->capacidade; i < novaCapacidade; i++) {
            malha->voos[i] = calloc(novaCapacidade, sizeof(U32));
        }

        malha->capacidade = novaCapacidade;
    }

    // Cadastra o novo aeroporto
    strncpy(malha->aeroportos[malha->qtdAeroportos].codigo, codigo, 4);
    strncpy(malha->aeroportos[malha->qtdAeroportos].cidade, cidade, 100);
    malha->qtdAeroportos++;

    return true;
}

I32 buscarIndiceAeroporto(MalhaAerea* malha, const char* codigo) {
    for (U32 i = 0; i < malha->qtdAeroportos; i++) {
        if (strncmp(malha->aeroportos[i].codigo, codigo, 3) == 0) {
            return i;
        }
    }
    return -1;
}