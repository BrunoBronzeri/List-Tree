
//List-Tree
// Implementar um programa em linguagem C em que o usuário informe uma série de números
// inteiros que devem ser armazenados em uma lista encadeada. O usuário poderá informar tantos
// números quanto desejar, na ordem em que desejar, e todos eles devem ser armazenados dentro
// da lista.
// Após o usuário ter informado todos os números, a lista deve ser transformada em uma árvore
// AVL. Ao final, o programa deve imprimir a lista original e árvore gerada a partir dela.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
   int number; 
} produto;


typedef struct lstItem{
   produto dado;
   struct lstItem *next;
} lstProduto;


/* Criação da lista: retorna uma lista vazia */
lstProduto *cria_lista(){
   return NULL;
}

/* 
   Imprime a lista.
   Esta função é um exemplo de como percorrer uma lista encadeada.
*/
void imprime_lista(lstProduto *lista){
   /* "atual" é um ponteiro para o elemento da lista que está sendo examinado. Inicialmente, aponta para o primeiro elemento */
   lstProduto *atual = lista; 

   while(atual!=NULL){
      printf(">>%d", (*atual).dado);
      atual = atual->next;
   }
}


lstProduto *insere_no_fim(lstProduto *lista, produto dado){
	
	lstProduto *novo = malloc(sizeof(lstProduto));
	
	novo->dado = dado;
	novo->next = NULL;
	
	if(lista == NULL)
		lista = novo;
	else{
		lstProduto *ultimo = lista;
		while(ultimo->next != NULL){
			ultimo=ultimo->next;
		}
		ultimo->next = novo;
	}
	return lista;
}
			
produto *novo_produto(){
   produto *novo = malloc(sizeof(produto));
   printf("Digite um número: ");
   scanf("%d",((*novo).number));
   return novo;
}

int main(void)
{  
   int auxiliar = 9;
   lstProduto *LST = cria_lista();

   while(auxiliar != 0){
      printf("Especifique o comando:\n");
      printf("2 -> Imprimir lista\n");
      printf("3 -> Inserir no inicio\n");
      printf("0 -> Parar\n");

      scanf("%d" ,&auxiliar);

      if(auxiliar == 2){
         imprime_lista(LST);
         printf("/n");
      }
         
      if(auxiliar == 3){
         produto *novo = novo_produto(); 
         LST = insere_no_fim(LST, *novo);
      }
   }
   return 0;
}
