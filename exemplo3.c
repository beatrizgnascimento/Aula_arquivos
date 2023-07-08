#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f = NULL;
  char msg[100];
  int idade = 25;
  int i;

  f = fopen("meuArquivo.txt", "r"); //nome do arquivo, tipo de abertura(read)
  //f = fopen("meuArquivo.txt", "w"); //se ja existir o arquivo ele será sobrescrito
  
  if(f == NULL)
  {
    printf("Falha ao abrir arquivo\n");
    exit(1);
  }

  for(i = 0; i < 4; i++)
  {
    fscanf(f, "%[^\t]", msg);
  //Le a string ate o tab e depois separa
  //msg:Beatriz Nascimento
  //idade: 19
    fscanf(f, "%d", &idade);
    printf("Msg: %s\nIdade: %d\n", msg, idade); //leitura da memória e não do arq

  }
  
  
  fclose(f);
  return 0;
}