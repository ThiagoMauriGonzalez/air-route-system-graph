#ifndef VOO_H
#define VOO_H

#include <stdlib.h>
#include <string.h>

#include "estrutura.h"
#include "meustipos.h"
#include "aeroporto.h"

// Cadastra um voo entre dois aeroportos com o número fornecido
// Retorna false se origem ou destino não existirem, ou se o voo já existir
boolean cadastrarVoo(MalhaAerea* malha, const char* origem, const char* destino, U32 numeroVoo);

// Remove um voo pelo número de voo
// Retorna true se removeu com sucesso, false se não encontrou o voo
boolean removerVoo(MalhaAerea* malha, U32 numeroVoo);

// Estrutura para informação de voos de saída
typedef struct {
    I32 origemIdx;    // índice do aeroporto de origem  
    U32 numero;        // número do voo
    I32 destinoIdx;    // índice do aeroporto de destino
} VooInfo;

// Obtém todos os voos que saem de um aeroporto
// Retorna false se o aeroporto não for encontrado, senão true e preenche *voos (malloc) e *qtd
boolean obterVoosSaida(MalhaAerea* malha, const char* origem, VooInfo** voos, U32* qtd);

#endif
