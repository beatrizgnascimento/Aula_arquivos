#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno
{
  int matr;
  char nome[50];
}aluno;

int main()
{
  FILE *arq = NULL;
  int x = 2;
  int vet[5] = {11, 6, 1, 4, 21};
  aluno a;
  int i;

  a.matr = 1010;
  strcpy(a.nome, "Augusto");

  arq = fopen("meu.Arquivo.bin", "rb");
  if(arq == NULL)
  {
    printf("Falha ao abrir arquivo");
    exit(1);
  }

 fread(&x, sizeof(x), 1, arq);
 fread(&a, sizeof(aluno), 1 , arq);
 fread(vet, sizeof(int), 5, arq);

  fclose(arq);

  printf("X = %d\n", x);
  printf("Aluno (matricula: %d), (Nome: %s)\n", a.matr, a.nome);
  printf("Vetor: \n");

  for(i = 0; i < 5; i++)
  {
    printf("%d\n", vet[i]);
  }

  return 0;
}