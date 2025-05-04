#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

PilhaDocumentos* criarPilha() {
    PilhaDocumentos* novaPilha = (PilhaDocumentos*) malloc(sizeof(PilhaDocumentos));
    novaPilha->topo = NULL;
    return novaPilha;
}

void empilhar(PilhaDocumentos* pilha, Documento doc) {
    Documento* novoDoc = (Documento*) malloc(sizeof(Documento));
    *novoDoc = doc;
    novoDoc->prox = pilha->topo;
    pilha->topo = novoDoc;
}

Documento desempilhar(PilhaDocumentos* pilha) {
    if (pilha->topo != NULL) {
        Documento* temp = pilha->topo;
        Documento doc = *temp;
        pilha->topo = temp->prox;
        free(temp);
        return doc;
    } else {
        Documento doc;
        doc.id = -1;
        strcpy(doc.titulo, "");
        doc.autores = NULL;
        return doc;
    }
}

Documento verTopo(PilhaDocumentos* pilha) {
    if (pilha->topo != NULL) {
        return *pilha->topo;
    } else {
        Documento doc;
        doc.id = -1;
        strcpy(doc.titulo, "");
        doc.autores = NULL;
        return doc;
    }
}

int pilhaVazia(PilhaDocumentos* pilha) {
    return pilha->topo == NULL;
}

void adicionarAutor(Documento* doc, const char* nome) {
    Autor* novoAutor = (Autor*) malloc(sizeof(Autor));
    novoAutor->id = rand(); // Gera um ID aleatório para o autor
    strcpy(novoAutor->nome, nome);
    novoAutor->prox = doc->autores;
    doc->autores = novoAutor;
}

void salvarPilha(PilhaDocumentos* pilha, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }

    Documento* atual = pilha->topo;
    while (atual != NULL) {
        fwrite(atual, sizeof(Documento), 1, arquivo);

        // Salva a lista de autores
        Autor* autorAtual = atual->autores;
        while (autorAtual != NULL) {
            fwrite(autorAtual, sizeof(Autor), 1, arquivo);
            autorAtual = autorAtual->prox;
        }

        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarPilha(PilhaDocumentos* pilha, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para carregar.\n");
        return;
    }

    Documento doc;
    while (fread(&doc, sizeof(Documento), 1, arquivo)) {
        Documento* novoDoc = (Documento*) malloc(sizeof(Documento));
        *novoDoc = doc;
        novoDoc->autores = NULL;
        novoDoc->prox = pilha->topo;
        pilha->topo = novoDoc;

        // Carrega a lista de autores
        Autor autor;
        while (fread(&autor, sizeof(Autor), 1, arquivo)) {
            Autor* novoAutor = (Autor*) malloc(sizeof(Autor));
            *novoAutor = autor;
            novoAutor->prox = novoDoc->autores;
            novoDoc->autores = novoAutor;

            if (feof(arquivo) || autor.prox == NULL) break;
        }
    }

    fclose(arquivo);
}

void liberarPilha(PilhaDocumentos* pilha) {
    while (!pilhaVazia(pilha)) {
        Documento doc = desempilhar(pilha);

        Autor* autorAtual = doc.autores;
        while (autorAtual != NULL) {
            Autor* temp = autorAtual;
            autorAtual = autorAtual->prox;
            free(temp);
        }
    }
    free(pilha);
}
