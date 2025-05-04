#include <stdio.h>

void contarFrequencia(char str[]) {
    int frequencia[256] = {0}; 
    int i, j;

   
    for (i = 0; str[i] != '\0'; i++) {
        frequencia[(int)str[i]]++;
    }

    
    for (i = 0; i < 256; i++) {
        if (frequencia[i] > 0) {
            printf("%c %d\n", i, frequencia[i]);
        }
    }
}

int main() {
    char str[100]; 
    int i;

    printf("Digite: ");
    fgets(str, sizeof(str), stdin); 

    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    contarFrequencia(str);
    return 0;
}