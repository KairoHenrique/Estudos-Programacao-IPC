#include <stdio.h>
#include <string.h>

void substituirPalavras(char frase[], char resultado[]) {
    int i = 0, j = 0;
    int comprimentoFrase = 0;
    char temp[1000]; 

    
    while (frase[comprimentoFrase] != '\0') {
        comprimentoFrase++;
    }

    while (i < comprimentoFrase) {
        
        if (i + 5 < comprimentoFrase && frase[i] == 'a' && frase[i+1] == 'l' && frase[i+2] == 'u' && frase[i+3] == 'n' && frase[i+4] == 'o') {
            
            for (int k = 0; k < 9; k++) {
                temp[j++] = "estudante"[k];
            }
            i += 5; 
        } 
        
        else if (i + 6 < comprimentoFrase && frase[i] == 'e' && frase[i+1] == 's' && frase[i+2] == 'c' && frase[i+3] == 'o' && frase[i+4] == 'l' && frase[i+5] == 'a') {
            
            for (int k = 0; k < 12; k++) {
                temp[j++] = "universidade"[k];
            }
            i += 6;
        } 
        else {
            
            temp[j++] = frase[i];
            i++;
        }
    }
    
    temp[j] = '\0'; 
    for (i = 0; temp[i] != '\0'; i++) {
        resultado[i] = temp[i];
    }
    resultado[i] = '\0';
}

int main() {
    char frase[1000];
    char resultado[1000];

    printf("Digite uma frase: ");
    fgets(frase, 1000, stdin);

    
    int comprimento = 0;
    while (frase[comprimento] != '\0') {
        comprimento++;
    }
    if (comprimento > 0 && frase[comprimento - 1] == '\n') {
        frase[comprimento - 1] = '\0';
    }

    substituirPalavras(frase, resultado);

    printf("Frase modificada: %s\n", resultado);

    return 0;
}
