#ifndef PILHA_H
#define PILHA_H

typedef struct Autor {
    int id;
    char nome[100];
    struct Autor* prox;
} Autor;

typedef struct Documento {
    int id;
    char titulo[100];
    Autor* autores;
    struct Documento* prox;
} Documento;

typedef struct PilhaDocumentos {
    Documento* topo;
} PilhaDocumentos;

PilhaDocumentos* criarPilha();
void empilhar(PilhaDocumentos* pilha, Documento doc);
Documento desempilhar(PilhaDocumentos* pilha);
Documento verTopo(PilhaDocumentos* pilha);
int pilhaVazia(PilhaDocumentos* pilha);
void adicionarAutor(Documento* doc, const char* nome);
void salvarPilha(PilhaDocumentos* pilha, const char* nomeArquivo);
void carregarPilha(PilhaDocumentos* pilha, const char* nomeArquivo);
void liberarPilha(PilhaDocumentos* pilha);

#endif
