#include <stdio.h>
#include <string.h>
#include "voo.h"

boolean cadastrarVoo(MalhaAerea* malha, const char* origem, const char* destino, U32 numeroVoo) {
    I32 indiceOrigem = buscarIndiceAeroporto(malha, origem);
    I32 indiceDestino = buscarIndiceAeroporto(malha, destino);

    if (indiceOrigem == -1 || indiceDestino == -1) {
        return false; // Um dos aeroportos não existe
    }

    if (malha->voos[indiceOrigem][indiceDestino] != 0) {
        return false; // Voo já cadastrado
    }

    malha->voos[indiceOrigem][indiceDestino] = numeroVoo;
    return true;
}

boolean removerVoo(MalhaAerea* malha, U32 numeroVoo) {
    for (U32 i = 0; i < malha->qtdAeroportos; i++) {
        for (U32 j = 0; j < malha->qtdAeroportos; j++) {
            if (malha->voos[i][j] == numeroVoo) {
                malha->voos[i][j] = 0; // Remove o voo
                return true;
            }
        }
    }
    return false;
}

boolean obterVoosSaida(MalhaAerea* malha, const char* origem, VooInfo** voos, U32* qtd) {
    I32 idxOrig = buscarIndiceAeroporto(malha, origem);
    if (idxOrig < 0) {
        *voos = NULL;
        *qtd = 0;
        return false;
    }
    // Conta quantos voos
    U32 count = 0;
    for (U32 j = 0; j < malha->qtdAeroportos; j++) {
        if (malha->voos[idxOrig][j] != 0) {
            count++;
        }
    }
    *qtd = count;
    if (count == 0) {
        *voos = NULL;
        return true;
    }
    VooInfo* lista = (VooInfo*) malloc(sizeof(VooInfo) * count);
    U32 k = 0;
    for (U32 j = 0; j < malha->qtdAeroportos; j++) {
        if (malha->voos[idxOrig][j] != 0) {
            lista[k].numero = malha->voos[idxOrig][j];
            lista[k].destinoIdx = j;
            k++;
        }
    }
    *voos = lista;
    return true;
}
void liberarVoos(VooInfo* voos) {
    free(voos);
}

boolean obterVoosConexao(MalhaAerea* malha, const char* origem, const char* destino, VooInfo** voos, U32* qtd) {
    I32 idxOrig = buscarIndiceAeroporto(malha, origem);
    I32 idxDest = buscarIndiceAeroporto(malha, destino);
    if (idxOrig < 0 || idxDest < 0) {
        *voos = NULL;
        *qtd = 0;
        return false;
    }

    // Conta quantos voos de origem a destino
    U32 count = 0;
    for (U32 j = 0; j < malha->qtdAeroportos; j++) {
        if (malha->voos[idxOrig][j] != 0 && malha->voos[j][idxDest] != 0) {
            count++;
        }
    }
    
    *qtd = count;
    if (count == 0) {
        *voos = NULL;
        return true;
    }

    VooInfo* lista = (VooInfo*) malloc(sizeof(VooInfo) * count);
    U32 k = 0;
    for (U32 j = 0; j < malha->qtdAeroportos; j++) {
        if (malha->voos[idxOrig][j] != 0 && malha->voos[j][idxDest] != 0) {
            lista[k].numero = malha->voos[idxOrig][j];
            lista[k].origemIdx = idxOrig;
            lista[k].destinoIdx = j;
            k++;
        }
    }
    
    *voos = lista;
    return true;
    
}   