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
   char nome[30];
   float preco; 
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
void print(lstProduto *lista){
   /* "atual" é um ponteiro para o elemento da lista que está sendo examinado. Inicialmente, aponta para o primeiro elemento */
   lstProduto *atual = lista; 

   while(atual!=NULL){
      printf(">>Nome: %s; Preco: %f\n", (*atual).dado.nome, atual->dado.preco);
      atual = atual->next;
   }
}


lstProduto *insere_no_fim(lstProduto *lista, produto dado){
	
	lstProduto *novo = malloc(sizeof(lstProduto));
	
	novo->dado = dado;
	novo->next = NULL;
	
	if(lista = NULL)
		lista = novo;
	else{
		lstProduto *ultimo = lista;
		while(ultimo->next != NULL)
			ultimo=ultimo->next;
		ultimo->next = novo;
		novo->prev = ultimo;
	}
	return lista;
}
			
// void adicionar(Lista* lista, No var){
//    No* new = malloc(sizeof(No));

//    new->number = var.number;

//    if (lista->first == NULL){
//       lista->first = new;
//    }
//    else{
// 	No* atual = Lista->first; //começar no primeiro
//     	while (atual->next != NULL){ //navegar até ao fim
//         	atual = atual->next;
//     }

//     atual->prox = novo; //colocar o novo nó no fim
// }

produto *novo_produto(){
   produto *novo = malloc(sizeof(produto));
   printf("Nome do produto: ");
   scanf("%s",((*novo).nome));
   printf("Preço: ");
   scanf("%f",&((*novo).preco));
   return novo;
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
         produto *novo = novo_produto(); 
         lista = insere_no_fim(lista, *novo);
      }
      if(auxiliar == 4){
         LST = inverte(LST);
      }
   }
   return 0;
}
