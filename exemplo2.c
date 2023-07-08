#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f = NULL;
  int idade = 25;

  f = fopen("meuArquivo.txt", "r"); //nome do arquivo, tipo de abertura(read)
  //f = fopen("meuArquivo.txt", "w"); //se ja existir o arquivo ele será sobrescrito
  
  if(f == NULL)
  {
    printf("Falha ao abrir arquivo\n");
    exit(1);
  }

  fprintf(f, "Hello World\n");
  //cat arquivo no terminal -- mostra conteudo do arq

  fprintf(f, "%d\n", idade);

  fclose(f);
  return 0;
}