#ifndef AEROPORTO_H
#define AEROPORTO_H

#include "meustipos.h"
#include "estrutura.h"

boolean cadastrarAeroporto(MalhaAerea* malha, const char* codigo, const char* cidade);

// Retorna o índice do aeroporto pelo código, ou -1 se não encontrado
I32 buscarIndiceAeroporto(MalhaAerea* malha, const char* codigo);

#endif