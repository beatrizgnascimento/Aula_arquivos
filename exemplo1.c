#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f = NULL;
  //system("mkdir x") -- criação do arq


  f = fopen("meuArquivo.txt", "r"); //nome do arquivo, tipo de abertura(read)
  //f = fopen("meuArquivo.txt", "w"); //se ja existir o arquivo ele será sobrescrito

  if(f == NULL)
  {
    printf("Falha ao abrir arquivo\n");
    exit(1);
  }

  fclose(f);
  return 0;
}