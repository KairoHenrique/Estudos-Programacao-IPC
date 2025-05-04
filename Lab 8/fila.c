#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila* criarFila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileirar(Fila *f, char nome[], char cpf[]) {
    Pessoa *novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));
    if (novaPessoa == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }
    strcpy(novaPessoa->Nome, nome);
    strcpy(novaPessoa->CPF, cpf);
    novaPessoa->prox = NULL;

    if (filaVazia(f)) {
        f->inicio = novaPessoa;
        f->fim = novaPessoa;
    } else {
        f->fim->prox = novaPessoa;
        f->fim = novaPessoa;
    }
}

void desenfileirar(Fila *f, char nome[], char cpf[]) {
    if (!filaVazia(f)) {
        Pessoa *pessoaRemovida = f->inicio;
        strcpy(nome, pessoaRemovida->Nome);
        strcpy(cpf, pessoaRemovida->CPF);

        f->inicio = f->inicio->prox;
        if (f->inicio == NULL) {
            f->fim = NULL;
        }

        free(pessoaRemovida);
    } else {
        nome[0] = '\0';
        cpf[0] = '\0';
    }
}

void mostrarFila(Fila *f) {
    if (!filaVazia(f)) {
        Pessoa *aux = f->inicio;
        printf("Fila:\n");
        while (aux != NULL) {
            printf("Nome: %s, CPF: %s\n", aux->Nome, aux->CPF);
            aux = aux->prox;
        }
    } else {
        printf("Fila vazia.\n");
    }
}

int filaVazia(Fila *f) {
    return f->inicio == NULL;
}

void liberarFila(Fila *f) {
    while (!filaVazia(f)) {
        char nome[50];
        char cpf[12];
        desenfileirar(f, nome, cpf);
    }
    free(f);
}
