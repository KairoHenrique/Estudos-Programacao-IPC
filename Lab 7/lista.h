#ifndef LISTA_H
#define LISTA_H

// Estrutura para armazenar os dados de uma pessoa
struct Pessoa {
    char nome[100];
    char cpf[15];
    struct Pessoa *prox;
};

// Estrutura para a lista encadeada
struct ListaSimplesEnc {
    struct Pessoa *prim;
};

// Funcoes para manipulacao da lista
void criarLista(struct ListaSimplesEnc *pList);
int estaVazia(struct ListaSimplesEnc *pList);
void inserirPessoa(struct ListaSimplesEnc *pList, char nome[], char cpf[]);
void removerPessoa(struct ListaSimplesEnc *pList);
void mostrarLista(struct ListaSimplesEnc *pList);
void inserirPessoaPrioritaria(struct ListaSimplesEnc *pList, char nome[], char cpf[]);

#endif
