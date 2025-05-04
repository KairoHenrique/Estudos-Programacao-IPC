#include <stdio.h>
#include <unistd.h>
#include "fila.h"

int main() {
    Fila *filaAtendimento = criarFila();
    int opcaoMenu;
    char nome[50];
    char cpf[12];

    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir na fila\n");
        printf("2 - Remover da fila\n");
        printf("3 - Imprimir a fila\n");
        printf("4 - Verificar se a fila esta vazia\n");
        printf("0 - Sair\n");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                printf("Digite o nome: ");
                scanf("%s", nome);
                printf("Digite o CPF: ");
                scanf("%s", cpf);
                enfileirar(filaAtendimento, nome, cpf);
                printf("Pessoa inserida na fila.\n");
                sleep(2);
                break;

            case 2:
                if (!filaVazia(filaAtendimento)) {
                    desenfileirar(filaAtendimento, nome, cpf);
                    printf("Pessoa removida: %s, CPF: %s\n", nome, cpf);
                } else {
                    printf("Fila vazia, nao ha ninguem para remover.\n");
                }
                sleep(2);
                break;

            case 3:
                mostrarFila(filaAtendimento);
                sleep(2);
                break;

            case 4:
                if (filaVazia(filaAtendimento)) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila nao esta vazia.\n");
                }
                sleep(2);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcaoMenu != 0);

    liberarFila(filaAtendimento);
    return 0;
}
