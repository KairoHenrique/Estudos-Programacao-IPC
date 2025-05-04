#ifndef FILA_H
#define FILA_H

typedef struct Pessoa {
    char Nome[50];
    char CPF[12];
    struct Pessoa *prox;
} Pessoa;

typedef struct Fila {
    Pessoa *inicio;
    Pessoa *fim;
} Fila;

Fila* criarFila();
void enfileirar(Fila *f, char nome[], char cpf[]);
void desenfileirar(Fila *f, char nome[], char cpf[]);
void mostrarFila(Fila *f);
int filaVazia(Fila *f);
void liberarFila(Fila *f);

#endif
