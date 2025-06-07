#include <stdio.h>
#include <stdlib.h>

void cadastrarAeroporto();
void cadastrarVoo();
void removerVoo();
void listarVoos();
void listarTrajetos();

void menu(){
    int opcao;

    do {
        printf("\nSISTEMA DE MALHA AÉREA:\n");
        printf("1. Cadastrar novo aeroporto\n");
        printf("2. Cadastrar novo voo entre aeroportos\n");
        printf("3. Remover voo\n");
        printf("4. Listar voos que saem de um aeroporto\n");
        printf("5. Listar trajetos possíveis entre aeroportos\n");
    
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarAeroporto();
                break;
            case 2:
                cadastrarVoo();
                break;
            case 3:
                removerVoo();
                break;
            case 4:
                listarVoos();
                break;
            case 5:
                listarTrajetos();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

int main(){
    menu();
    return 0;
}