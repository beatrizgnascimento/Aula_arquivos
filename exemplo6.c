#include <stdio.h>
#include <stdlib.h>

typedef struct conta
{
  int num;
  char nome[50];
  float saldo;
}conta; 

int main()
{
  conta c;
  int op, idx; //opcao
  FILE *arq = NULL;

  scanf("%d", &op);

  while(op != 9) //9 sera a saida
  {

     if(op ==1)//inserir uma conta
    {
        printf("Numero : ");
        printf("Nome: ");
        printf("Saldo: ");
        scanf(" %d", &c.num);
        scanf(" %s", c.nome);
        scanf(" %f", &c.saldo);

        arq = fopen("banco.txt", "ab");

        fwrite(&c, sizeof(conta), 1, arq);

        fclose(arq);
    } 
    else if(op == 2) //alterar saldo
   {
      printf("Numero do registro: ");
      scanf("%d", &idx);

    //ler a informação antiga
      arq = fopen("banco.txt", "r+b");

     //posicionar o ponteiro no registro (indicado por idx)desejado para modificá-lo
      fseek(arq, (idx - 1) * sizeof(conta) ,SEEK_SET);

      
    //leitura do registro
      fread(&c, sizeof(conta), 1, arq);

     //ler o novo saldo
      printf("Digite o novo saldo: ");
     scanf(" %f", &c.saldo );

      //reposiciona o ponteiro no mesmo local do incio do registro
      fseek(arq, (idx - 1) * sizeof(conta) ,SEEK_SET);

    //grava a atualização
    fwrite(&c, sizeof(conta), 1, arq);

      fclose(arq);

   }
   else if(op == 3) //exibir todas as contas
   {
      printf("\n===================\n");

      arq = fopen("banco.txt", "rb");

      fread(&c, sizeof(conta), 1, arq);

      while(! feof(arq)){
        printf("%d\t%s\t%2.f\n", c.num, c.nome, c.saldo);
        fread(&c, sizeof(conta), 1, arq);
      }

      fclose(arq);
      printf("\n");
   }
   scanf("%d", &op);
  }
 
  return 0;
}