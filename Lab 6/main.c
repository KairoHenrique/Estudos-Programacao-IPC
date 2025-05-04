#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada = fopen("matriz.txt", "r");
    FILE *saida = fopen("transposta.txt", "w");

    if (entrada == NULL || saida == NULL) {
        perror("Erro ao abrir arquivo");
        return EXIT_FAILURE;
    }
    
    int linhas, colunas;
    fscanf(entrada, "%d %d", &linhas, &colunas);

    // Alocando memoria para a matriz original
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    
    // Lendo a matriz do arquivo
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fscanf(entrada, "%d", &matriz[i][j]);
        }
    }

    // Alocando memoria para a matriz transposta
    int **transposta = (int **)malloc(colunas * sizeof(int *));
    for (int i = 0; i < colunas; i++) {
        transposta[i] = (int *)malloc(linhas * sizeof(int));
    }

    // Transpondo a matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    // Escrevendo a matriz transposta no arquivo
    fprintf(saida, "%d %d\n", colunas, linhas);
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            fprintf(saida, "%d ", transposta[i][j]);
        }
        fprintf(saida, "\n");
    }

    // Liberando a memoria da matriz original
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    // Liberando a memoria da matriz transposta
    for (int i = 0; i < colunas; i++) {
        free(transposta[i]);
    }
    free(transposta);

    fclose(entrada);
    fclose(saida);

    return 0;
}
