#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main() {
    int escolha=0;
    int num;
    do{
        printf("Digite qual exercicio deseja realizar 1, 2, 3, 4 ou (0) para sair\nQual deseja?: ");
        scanf("%d",&escolha);
        switch(escolha){
            //exercicio 1
            case 1:{
                printf("Exercicio 1 escolhido!\nDigite um numero, para que eu mostre a tabuada de tal!\nNumero escolhido: ");
                scanf("%d",&num);
                printf("\nTabuada do numero %d:\n",num);
                for(int n=1;n<=10;n++){
                    printf("%d X %d = %d\n",num,n,num*n);
                }
            }
            break;
            case 2:{
                //variaveis
                int fatorial=1;
                int n=1;
                
                printf("\nExercicio 2 escolhido!\nDigite um numero, para que eu mostre o fatorial de tal!\nNumero escolhido: ");
                scanf("%d",&num);
                do{
                    fatorial*=n;
                    n++;
                }while(n<=num);
                printf("O fatorial de %d e: %d\n",num,fatorial);
            }
            break;
            case 3:{
                //variaveis
                int invertido=0;
                int resto;
                
                printf("\nExercicio 3 escolhido!\nEscreva um numero inteiro para que eu coloque de tras pra frente!\nNumero escolhido: ");
                scanf("%d",&num);
                while (num!=0){
                    resto=num%10;
                    invertido=invertido*10+resto;
                    num/=10;
                }
                printf("O numero invertido e: %d\n",invertido);
            }
            break;
            case 4:{
                //variaveis
                int n,primo=1;
                
                printf("\nExercicio 4 escolhido!\nEscolha um numero que eu direi se ele é primo ou nao!\nNumero escolhido: ");
                scanf("%d",&num);
                for(n=2;n<=num/2;++n){
                    if(num%n==0){
                        primo=0;
                        break;
                    }
                }
                if(primo==1)
                    printf("%d é um número primo.\n",num);
                else
                    printf("%d não é um número primo.\n",num);
            }
            break;
            default:
                if(escolha!=0){
                    printf("\nOpcao invalida, recomece!\n");
                    sleep(1);
                }
                break;
        }
    }while(escolha>=1);
    printf("Ate a proxima!");
    sleep(2);
    return 0;
}