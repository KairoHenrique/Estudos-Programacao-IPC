#include <stdio.h>
#include <string.h>

int main() {
    char frase[1024], resultado[2048];
    char palavra[] = "teclado";
    char substituto[] = "teclado ou mouse";
    int i = 0, j = 0, k = 0;
    int comprimentoString;

    printf("Digite uma frase: ");
    fgets(frase, 1024, stdin);

    comprimentoString = strlen(frase);
    if (comprimentoString > 0 && frase[comprimentoString - 1] == '\n') {
        frase[comprimentoString - 1] = '\0';
    }

    while (frase[i] != '\0') {
        if (strncmp(&frase[i], palavra, strlen(palavra)) == 0) {
            while (substituto[k] != '\0') {
                resultado[j] = substituto[k];
                k++;
                j++;
            }
            i += strlen(palavra);
            k = 0;
        } else {
            resultado[j] = frase[i];
            i++;
            j++;
        }
    }
    resultado[j] = '\0';

    printf("Resposta: %s\n", resultado);

    return 0;
}
