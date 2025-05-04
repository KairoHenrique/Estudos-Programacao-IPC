#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lista.h"

void criarLista(struct ListaSimplesEnc *pList) {
    pList->prim = NULL;
}

int estaVazia(struct ListaSimplesEnc *pList) {
    return pList->prim == NULL;
}

void inserirPessoa(struct ListaSimplesEnc *pList, char nome[], char cpf[]) {
    struct Pessoa *nova = (struct Pessoa*)malloc(sizeof(struct Pessoa));
    strcpy(nova->nome, nome);
    strcpy(nova->cpf, cpf);
    nova->prox = pList->prim;
    pList->prim = nova;

    printf("Pessoa inserida: %s, CPF: %s\n", nome, cpf);
}

void removerPessoa(struct ListaSimplesEnc *pList) {
    if (estaVazia(pList)) {
        printf("A lista esta vazia!\n");
        return;
    }

    struct Pessoa *pAux = pList->prim;
    printf("Pessoa removida: %s\n", pAux->nome);
    pList->prim = pAux->prox;
    free(pAux);
}

void mostrarLista(struct ListaSimplesEnc *pList) {
    struct Pessoa *p = pList->prim;
    if (p == NULL) {
        printf("A lista esta vazia!\n");
    } else {
        while (p != NULL) {
            printf("Nome: %s, CPF: %s\n", p->nome, p->cpf);
            p = p->prox;
        }
    }
}

void inserirPessoaPrioritaria(struct ListaSimplesEnc *pList, char nome[], char cpf[]) {
    struct Pessoa *nova = (struct Pessoa*)malloc(sizeof(struct Pessoa));
    strcpy(nova->nome, nome);
    strcpy(nova->cpf, cpf);
    nova->prox = NULL;

    if (estaVazia(pList)) {
        pList->prim = nova;
    } else {
        struct Pessoa *p = pList->prim;
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = nova;
    }

    printf("Pessoa prioritaria inserida: %s, CPF: %s\n", nome, cpf);
}

int main() {
    struct ListaSimplesEnc lista;
    criarLista(&lista);

    int opcao;
    char nome[100];
    char cpf[15];

    do {
        printf("\nMenu:\n");
        printf("1. Inserir pessoa na lista\n");
        printf("2. Remover pessoa da lista\n");
        printf("3. Mostrar lista\n");
        printf("4. Verificar se a lista esta vazia\n");
        printf("5. Inserir pessoa com atendimento prioritario\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("CPF: ");
                fgets(cpf, 15, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';
                inserirPessoa(&lista, nome, cpf);
                break;
            case 2:
                removerPessoa(&lista);
                break;
            case 3:
                mostrarLista(&lista);
                break;
            case 4:
                if (estaVazia(&lista)) {
                    printf("A lista esta vazia!\n");
                } else {
                    printf("A lista nao esta vazia!\n");
                }
                break;
            case 5:
                printf("Nome: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("CPF: ");
                fgets(cpf, 15, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';
                inserirPessoaPrioritaria(&lista, nome, cpf);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
                
        }
        sleep(4); //para ficar mais bonitinho no terminal :)
    } while (opcao != 6);

    return 0;
}
