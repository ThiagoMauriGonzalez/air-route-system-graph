#include "meustipos.h"
#include "estrutura.h"
#include "aeroporto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void limpar_buffer();
void exibir_menu();
void cadastrar_aeroporto_menu(MalhaAerea* malha);
void cadastrar_voo_menu(MalhaAerea* malha);
void remover_voo_menu(MalhaAerea* malha);
void listar_voos_menu(MalhaAerea* malha);
void listar_trajetos_menu(MalhaAerea* malha);

I32 main() {
    int opcao;
    MalhaAerea malha;

    inicializarMalha(&malha);

    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                cadastrar_aeroporto_menu(&malha);
                break;
           /* case 2:
                cadastrar_voo_menu(&malha);
                break;
            case 3:
                remover_voo_menu(&malha);
                break;
            case 4:
                listar_voos_menu(&malha);
                break;
            case 5:
                listar_trajetos_menu(&malha);
                break; */
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Por favor, tente novamente.\n");
        }
    } while (opcao != 0);

    // Libera memoria alocada
    liberarMalha(&malha);
    return 0;
}

void limpar_buffer() {
    I32 c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibir_menu() {
    printf("\n=== MENU ===\n");
    printf("1. Cadastrar novo aeroporto\n");
    printf("2. Cadastrar voo entre aeroportos\n");
    printf("3. Remover voo\n");
    printf("4. Listar voos que saem de um aeroporto\n");
    printf("5. Listar trajetos possiveis entre dois aeroportos\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void cadastrar_aeroporto_menu(MalhaAerea* malha) {
    char codigo[4];
    char cidade[100];

    printf("\n=== Cadastro de Aeroporto ===\n");
    printf("Codigo (3 letras): ");
    scanf("%3s", codigo);
    limpar_buffer();

    printf("Cidade: ");
    scanf("%99[^\n]", cidade);
    limpar_buffer();

    if (cadastrarAeroporto(malha, codigo, cidade)) {
        printf("\nAeroporto cadastrado com sucesso.\n");
    } else {
        printf("\nErro: aeroporto com esse codigo ja existe.\n");
    }
}


void cadastrar_voo_menu(MalhaAerea* malha) {
    printf("\nFuncao 'Cadastrar Voo' ainda nao implementada.\n");
}

void remover_voo_menu(MalhaAerea* malha) {
    printf("\nFuncao 'Remover Voo' ainda nao implementada.\n");
}

void listar_voos_menu(MalhaAerea* malha) {
    printf("\nFuncao 'Listar Voos' ainda nao implementada.\n");
}

void listar_trajetos_menu(MalhaAerea* malha) {
    printf("\nFuncao 'Listar Trajetos' ainda nao implementada.\n");
}
