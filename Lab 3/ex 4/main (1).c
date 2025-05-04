#include <stdio.h>
#include <math.h>
int main(){
  long long cnpj, CNPJModificado, somaCNPJ = 0, somaCNPJ2 = 0, ResultadoCNPJ = 0, ResultadoCNPJ2 = 0, cnpj2 = 0;

  int peso[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
  int peso2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

  printf("Informe seu CNPJ:\n");
  scanf("%lld", &cnpj);

  printf("Seu CNPJ: %lld\n", cnpj);

  CNPJModificado = cnpj;

  for (int i = 11; i >= 0; i--)
  {
    somaCNPJ += (CNPJModificado % 10) * peso[i];
    CNPJModificado /= 10;
  }

  if (somaCNPJ % 11 < 2)
  {
    ResultadoCNPJ = 0;
  }
  else
  {
    ResultadoCNPJ = 11 - (somaCNPJ % 11);
  }
  
  cnpj = cnpj * 10 + ResultadoCNPJ;

  CNPJModificado = cnpj;
  

  for (int i = 12; i >= 0; i--)
  {
    somaCNPJ2 += (CNPJModificado % 10) * peso2[i];
    CNPJModificado /= 10;
  }

  if (somaCNPJ2 % 11 < 2)
  {
    ResultadoCNPJ2 = 0;
  }
  else
  {
    ResultadoCNPJ2 = 11 - (somaCNPJ2 % 11);
  }
  cnpj2 = cnpj * 10 + ResultadoCNPJ2;

  printf("O seu CNPJ completo com os digitos verificadores: %lld\n", cnpj2);
  return 0;
}