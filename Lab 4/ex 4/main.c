#include <stdio.h>

void main() {
  int linhasA, colunasA, linhasB, colunasB;

  printf("Digite o numero de linhas da matriz A: ");
  scanf("%d", &linhasA);
  printf("Digite o numero de colunas da matriz A: ");
  scanf("%d", &colunasA);

  printf("Digite o numero de linhas da matriz B: ");
  scanf("%d", &linhasB);
  printf("Digite o numero de colunas da matriz B: ");
  scanf("%d", &colunasB);

  if (colunasA != linhasB) {
    printf("Multiplicacao impossivel!\n");
    return;
  }

  float matrizA[linhasA][colunasA];
  float matrizB[linhasB][colunasB];
  float matrizC[linhasA][colunasB];

  printf("\nDigite os valores da matriz A:\n");
  for (int i = 0; i < linhasA; i++) {
    for (int j = 0; j < colunasA; j++) {
      printf("Elemento [%d][%d]: ", i + 1, j + 1);
      scanf("%f", &matrizA[i][j]);
    }
  }

  printf("\nDigite os valores da matriz B:\n");
  for (int i = 0; i < linhasB; i++) {
    for (int j = 0; j < colunasB; j++) {
      printf("Elemento [%d][%d]: ", i + 1, j + 1);
      scanf("%f", &matrizB[i][j]);
    }
  }

  for (int i = 0; i < linhasA; i++) {
    for (int j = 0; j < colunasB; j++) {
      matrizC[i][j] = 0;
      for (int k = 0; k < colunasA; k++) {
        matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
      }
    }
  }

  printf("\nMatriz Resultante:\n");
  for (int i = 0; i < linhasA; i++) {
    for (int j = 0; j < colunasB; j++) {
      printf("%.2f ", matrizC[i][j]);
    }
    printf("\n");
  }
}
