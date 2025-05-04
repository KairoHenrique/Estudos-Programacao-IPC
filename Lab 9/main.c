#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pilha.h"

int main() {
    PilhaDocumentos* minhaPilha = criarPilha();
    int opcao;
    Documento documento;
    char buffer[100];

    // Semente para geração de números aleatórios
    srand(time(NULL));

    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Empilhar documento\n");
        printf("2 - Desempilhar documento\n");
        printf("3 - Mostrar documento do topo\n");
        printf("4 - Verificar se a pilha esta vazia\n");
        printf("5 - Salvar pilha em arquivo\n");
        printf("6 - Carregar pilha de arquivo\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                // Solicitar ID e título do documento
                printf("Digite o ID do documento: ");
                scanf("%d", &documento.id);
                getchar(); // Limpar o buffer de entrada

                printf("Digite o titulo do documento: ");
                fgets(documento.titulo, sizeof(documento.titulo), stdin);
                documento.titulo[strcspn(documento.titulo, "\n")] = '\0'; 

                printf("Digite o nome do autor: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; 
                adicionarAutor(&documento, buffer);

                empilhar(minhaPilha, documento);
                printf("Documento empilhado com sucesso!\n");
                break;

            case 2:
                if (!pilhaVazia(minhaPilha)) {
                    Documento removido = desempilhar(minhaPilha);
                    printf("Documento removido: ID=%d, Titulo=%s\n", removido.id, removido.titulo);
                } else {
                    printf("A pilha esta vazia, nada para desempilhar.\n");
                }
                break;

            case 3:
                if (!pilhaVazia(minhaPilha)) {
                    Documento topo = verTopo(minhaPilha);
                    printf("Documento no topo: ID=%d, Titulo=%s\n", topo.id, topo.titulo);
                } else {
                    printf("A pilha esta vazia.\n");
                }
                break;

            case 4:
                if (pilhaVazia(minhaPilha)) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("A pilha nao esta vazia.\n");
                }
                break;

            case 5:
                salvarPilha(minhaPilha, "pilha_documentos.bin");
                printf("Pilha salva com sucesso!\n");
                break;

            case 6:
                carregarPilha(minhaPilha, "pilha_documentos.bin");
                printf("Pilha carregada com sucesso!\n");
                break;

            case 0:
                liberarPilha(minhaPilha);
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
