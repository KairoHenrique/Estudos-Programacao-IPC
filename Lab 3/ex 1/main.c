#include <stdio.h>

int main() {
  int num1, num2;

  while (1) {
    printf("Digite dois números ou 0 0 para Terminar: ");
    scanf("%d %d", &num1, &num2);

    if (num1 == 0 && num2 == 0) {
      break;
    }

    if (num1 > num2) {
      int temp = num1;
      num1 = num2;
      num2 = temp;
    }

    int SomaCubos = 0;

    for (int numero = num1; numero <= num2; numero++) {
      if (numero % 2 == 0) {
        SomaCubos += numero * numero * numero;
      }
    }

    printf("Intervalo: %d, %d\n", num1, num2);
    printf("Soma dos cubos dos pares: %d\n", SomaCubos);
  }

  printf("\nPrograma Terminado!");

  return 0;
}
