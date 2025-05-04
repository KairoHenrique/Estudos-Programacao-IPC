#include <stdio.h>
#include <math.h>

int main(){
    double x;
    printf("Digite um Valor: ");
    scanf("%lf", &x);
    double exp_x = exp(x);
    double serie = 1;
    int n = 1;
    double precisao = 0.0001;
    double termo = 1;

    while (fabs(exp_x - serie) >= precisao) {
        termo *= x / n;
        serie += termo;
        n++;
    }

    printf("São necessários %d termos para obter a precisão de 4 casas decimais.\n", n);
    return 0;
}