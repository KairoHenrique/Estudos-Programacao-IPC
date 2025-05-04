#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main(){
int exercicio;

printf("Digite qual exercicio deseja realizar 1,2,3 ou 4: ");
scanf ("%d",&exercicio);   

    switch(exercicio){
        
        //exercicio 1
        case 1: {
            /*Variaveis exercicio 1*/
             double m,a,b,c,result;
            printf("Exercicio 1 escolhido!\nDigite 3 numeros para a media e o desvio padrão destes 3 numeros ser mostrada\n");
            printf("Escreva o primeiro numero: ");
            scanf("%lf",&a);
            printf("Escreva o segundo numero: ");
            scanf("%lf",&b);
            printf("Escreva o terceiro numero: ");
            scanf("%lf",&c);
            m=(a+b+c)/3;
            result=pow((a-m),2);
            a=result;
            result=pow((b-m),2);
            b=result;
            result=pow((c-m),2);
            c=result;
            result=sqrt((a+b+c)/2);
            printf ("Media: %.2lf",m);
            printf ("\ndesvio: %.2lf",result);

            
        }
        break;  
        
        //exercicio 2
        case 2:{
            /*Variaveis exercicio 2*/
            double x,result;
            printf("Exercicio 2 escolhido!\nParamque eu te diga se o resultado se satisfaz na inequeacao");
            printf("\nEscreva um numero: ");
            scanf("%lf",&x);
            result=(x+1)/(-2*x+3);
            if(result<=0){
                printf("resultado satisfaz");
                printf("\nResultado:%.2lf",result);
            } else{
               printf("Resultado não satisfaz"); 
               printf("\nResultado:%.2lf",result);
            }
            
       
        } 
        break;
        
        //exercicio 3
        case 3:{
            printf("Exercicio 3 escolhido!");
            printf("\nescolha o tipo de média que voce deseja calcular a partir de 3 notas");
            printf("\nMedia Aritmetica (A)\nPonderada (P)\nHarmonica (H)");
            printf("\nQual deseja?: ");
             /*Variaveis exercicio 3*/
            char exercicio3;
            double m,a,b,c;
            
            scanf(" %c",&exercicio3);
            if(exercicio3=='a'||exercicio3=='A'){
                printf("\nEscreva 3 numeros para realizar media aritmetica: ");
                printf("\nEscreva o primeiro numero: ");
                scanf("%lf",&a);
                printf("Escreva o segundo numero: ");
                scanf("%lf",&b);
                printf("Escreva o terceiro numero: ");
                scanf("%lf",&c);
                m=(a+b+c)/3;
                printf ("Media Aritmetica: %.2lf",m);
            }
            else if(exercicio3=='p'||exercicio3=='P'){
                printf("\nEscreva 3 numeros para realizar a media ponderada de peso 3,3,4: ");
                printf("\nEscreva o primeiro numero: ");
                scanf("%lf",&a);
                printf("Escreva o segundo numero: ");
                scanf("%lf",&b);
                printf("Escreva o terceiro numero: ");
                scanf("%lf",&c);
                m=(a*3+b*3+c*4)/10;
                printf ("Media Ponderada: %.2lf",m);
            }
            else if(exercicio3=='h'||exercicio3=='H'){
                printf("\nEscreva 3 numeros para realizar a media harmonica: ");
                printf("\nEscreva o primeiro numero: ");
                scanf("%lf",&a);
                printf("Escreva o segundo numero: ");
                scanf("%lf",&b);
                printf("Escreva o terceiro numero: ");
                scanf("%lf",&c);
                m=3/((1/a)+(1/b)+(1/c));
                printf ("Media Harmonica: %.2lf",m);
            }    
                
        
        }
        break;
       
        //exercicio 4
        case 4:{
            /*Variaveis exercicio 4*/
            char sexo;
            int ano;
            double salario,bonus,total;
        printf("Exercicio 4 escolhido!\nPara saber seu bonus de natal me diga");
        printf(" Qual seu sexo, Masculino (M) ou Femenino (F)? ");  
        scanf(" %c",&sexo);
        printf("\nQuanto tempo vc trabalha na empresa? ");
        scanf("%d",&ano);
        printf("\nQual seu salario? ");
        scanf("%lf",&salario);
       
        if(sexo=='m'||sexo=='M'){
            if(ano>15){
            bonus=salario*0.20;
        }
        else{
            bonus=100;
        }
    }
        else if(sexo=='f'||sexo=='F'){
        if(ano>10){
            bonus=salario*0.25;
        }
        else{
            bonus=100;
        }
    }else{
        printf("Sexo Invalido, nao a como verificar o bonus\n");
    }
    total=bonus+salario;
    printf("O valor do bonus de Natal: R$%.2lf",bonus);
    printf("\nO valor total do salario+bonus: R$%.2lf",total);
}
 	//opcao invalida
        break;
		default:
        printf("\nOpcao invalida, recomece!");
    }
    sleep(3);
    return 0;
}
