#include <stdio.h>
#include <string.h>
#include "voo.h"

// Cadastra um voo entre dois aeroportos
boolean cadastrarVoo(MalhaAerea* malha, const char* origem, const char* destino, U32 numeroVoo) {
    I32 indiceOrigem = buscarIndiceAeroporto(malha, origem);
    I32 indiceDestino = buscarIndiceAeroporto(malha, destino);

    // Verifica se os aeroportos existem
    if (indiceOrigem == -1 || indiceDestino == -1) {
        return false; // Um dos aeroportos não existe
    }

    // Verifica se o voo já existe
    if (malha->voos[indiceOrigem][indiceDestino] != 0) {
        return false; // Voo já cadastrado
    }

    // Cadastra o voo na matriz de adjacência
    malha->voos[indiceOrigem][indiceDestino] = numeroVoo;
    return true;
}

// Remove um voo pelo número
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

// Obtém todos os voos que saem de um aeroporto
boolean obterVoosSaida(MalhaAerea* malha, const char* origem, VooInfo** voos, U32* qtd) {
    I32 idxOrig = buscarIndiceAeroporto(malha, origem);
    if (idxOrig < 0) {
        *voos = NULL;
        *qtd = 0;
        return false;
    }
    // Conta quantos voos saem do aeroporto
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
    // Aloca e preenche a lista de voos de saída
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

// Libera memória alocada para lista de voos
void liberarVoos(VooInfo* voos) {
    free(voos);
}

// Obtém voos de conexão (com uma escala) entre dois aeroportos
boolean obterVoosConexao(MalhaAerea* malha, const char* origem, const char* destino, VooInfo** voos, U32* qtd) {
    I32 idxOrig = buscarIndiceAeroporto(malha, origem);
    I32 idxDest = buscarIndiceAeroporto(malha, destino);
    if (idxOrig < 0 || idxDest < 0) {
        *voos = NULL;
        *qtd = 0;
        return false;
    }

    // Conta quantos voos de conexão existem
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

    // Aloca e preenche a lista de voos de conexão
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

// Função recursiva para listar todos os caminhos entre dois aeroportos
void listarTodosCaminhosRec(MalhaAerea* malha, I32 atual, I32 destino, boolean* visitado, I32* caminho, U32 nivel, U32* total) {
    visitado[atual] = true;
    caminho[nivel] = atual;

    // Se chegou ao destino, imprime o caminho encontrado
    if (atual == destino && nivel > 0) {
        printf("Caminho %u: ", ++(*total));
        for (U32 i = 0; i < nivel; i++) {
            printf("%s (%u) -> ", malha->aeroportos[caminho[i]].codigo, malha->voos[caminho[i]][caminho[i+1]]);
        }
        printf("%s\n", malha->aeroportos[caminho[nivel]].codigo);
    } else {
        // Tenta todos os próximos aeroportos não visitados e com voo direto
        for (U32 prox = 0; prox < malha->qtdAeroportos; prox++) {
            if (!visitado[prox] && malha->voos[atual][prox] != 0) {
                listarTodosCaminhosRec(malha, prox, destino, visitado, caminho, nivel + 1, total);
            }
        }
    }
    visitado[atual] = false;
}

// Função principal para listar todos os caminhos entre dois aeroportos
void listarTodosCaminhos(MalhaAerea* malha, const char* origem, const char* destino) {
    I32 idxOrig = buscarIndiceAeroporto(malha, origem);
    I32 idxDest = buscarIndiceAeroporto(malha, destino);
    if (idxOrig < 0 || idxDest < 0) {
        printf("Erro: um ou ambos os aeroportos nao existem.\n");
        return;
    }
    boolean visitado[malha->qtdAeroportos];
    I32 caminho[malha->qtdAeroportos];
    memset(visitado, 0, sizeof(visitado));
    U32 total = 0;
    printf("\nTodos os caminhos de %s para %s:\n", origem, destino);
    listarTodosCaminhosRec(malha, idxOrig, idxDest, visitado, caminho, 0, &total);
    if (total == 0) {
        printf("Nenhum caminho encontrado.\n");
    }
}