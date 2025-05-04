#include <stdio.h>
#include <math.h>

int Calcular(long long cpf, int size, int factor) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        int digit = cpf / (int)pow(10, size - i - 1) % 10;
        sum += digit * (factor - i);
    }
    int result = 11 - (sum % 11);
    return result < 10 ? result : 0;
}

int main() {
    long long cpf;
    printf("Digite o CPF: ");
    scanf("%lld", &cpf);

    int primeiro = Calcular(cpf, 9, 10);
    int segundo = Calcular(cpf * 10 + primeiro, 10, 11);

    printf("CPF com digitos verificadores: %lld%d%d\n", cpf, primeiro, segundo);
    return 0;
}