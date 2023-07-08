#include <stdio.h>
#include <stdlib.h>
int main()
{
  int conta;
  char nome[100];
  float saldo;
  FILE *arq = NULL;

  arq = fopen("banco.txt", "a");

  if(arq == NULL)
  {
    printf("Erro ao abrir arquivo");
    exit(1);
  }

  scanf("%d", &conta);
  while(conta != 0)
  {
    scanf(" %[^\n]", nome);
    scanf(" %f", &saldo);

    fprintf(arq, "%d\t%s\t%f\n", conta, nome, saldo);
    scanf("%d", &conta);

  }

  fclose(arq);

  return 0;
}