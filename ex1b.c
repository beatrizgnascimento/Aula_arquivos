#include <stdio.h>
int main()
{
  int conta;
  char nome[100];
  float saldo;
  FILE *arq = NULL;

  arq = fopen("banco.txt", "r");

  
  while( fscanf(arq, "%d\t%[^\t] %f", &conta, nome, &saldo) == 3 ) //enquanto nao chegar ao fim do arquivo
  {
    printf("%d %s %.2f", conta, nome, saldo);
  }

  /*
  fscanf(arq, "%d\t%[^\t] %f", &conta, nome, &saldo);

  while( !feof(arq) ) //enquanto nao chegar ao fim do arquivo
  {
    printf("%d %s %.2f", conta, nome, saldo);
    
    fscanf(arq, "%d\t%[^\t] %f", &conta, nome, &saldo); //tem que estar na ultima linha do while

  }
  */

  fclose(arq);

  return 0;
}