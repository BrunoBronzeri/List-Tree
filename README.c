//List-Tree
// Implementar um programa em linguagem C em que o usuário informe uma série de números
// inteiros que devem ser armazenados em uma lista encadeada. O usuário poderá informar tantos
// números quanto desejar, na ordem em que desejar, e todos eles devem ser armazenados dentro
// da lista.
// Após o usuário ter informado todos os números, a lista deve ser transformada em uma árvore
// AVL. Ao final, o programa deve imprimir a lista original e árvore gerada a partir dela.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int numero;
} numList;

struct tree{
	numList *dado;
	struct tree *left, *right;
}typedef Tree;


lista *create_lista(){
   return NULL;
}

Tree *create_tree(){
	return NULL;
}

int main(void)
{  
   int auxiliar = 9;
   lista *LST = cria_lista();

   while(auxiliar != 0){
      printf("Especifique o comando:\n");
      printf("2 -> Imprimir lista\n");
      printf("3 -> Inserir no inicio\n");
      printf("4 -> Inverter lista\n");
      printf("0 -> Parar\n");

      scanf("%d" ,&auxiliar);

      if(auxiliar == 2){
         imprime_lista(LST);
         printf("\n");
      }
         
      if(auxiliar == 3){
         pessoa *p = novo_dado();
         LST = insere_no_inicio(LST, *p);
      }

      if(auxiliar == 4){
         LST = inverte(LST);
      }
   }
   return 0;
}
