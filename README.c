//List-Tree
// Implementar um programa em linguagem C em que o usu´ario informe uma s´erie de n´umeros
// inteiros que devem ser armazenados em uma lista encadeada. O usu´ario poder´a informar tantos
// n´umeros quanto desejar, na ordem em que desejar, e todos eles devem ser armazenados dentro
// da lista.
// Ap´os o usu´ario ter informado todos os n´umeros, a lista deve ser transformada em uma ´arvore
// AVL. Ao final, o programa deve imprimir a lista original e ´arvore gerada a partir dela.

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
