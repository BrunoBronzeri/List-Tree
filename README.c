//List-Tree
// Implementar um programa em linguagem C em que o usuário informe uma série de números
// inteiros que devem ser armazenados em uma lista encadeada. O usuário poderá informar tantos
// números quanto desejar, na ordem em que desejar, e todos eles devem ser armazenados dentro
// da lista.
// Após o usuário ter informado todos os números, a lista deve ser transformada em uma árvore
// AVL. Ao final, o programa deve imprimir a lista original e árvore gerada a partir dela.

#include <stdio.h>
#include <stdlib.h>

typedef struct lstItem{ //struct da lista
   int dado;
   struct lstItem *next;
} lstNum;

typedef struct node{ //struct da árvore
	int data;
	struct node *left, *right;
	int ht; //para altura da árvore ('height tree')
} node;

/*---------------------Funções-Lista----------------------*/
lstNum *cria_lista();
void imprime_lista(lstNum*);
lstNum *insere_no_fim(lstNum*, int);
int novo_num();

/*--------------------Funções-Árvore----------------------*/
node *insert(node*, int); //inserir na árvore
node *delete(node *, int);
void preorder(node *);
void inorder(node*); //por árvore 'inorder'
int height(node*); //altura árvore
node *rotateRight(node*); //fç rotacionar direita
node *rotateLeft(node*); //fç rotacionar esquerda
node *LR(node*); //joga da esq pra dir
node *RL(node*); //joga dir para esq
int FatBal(node*); //calcular fator de balanceamento
/*--------------------------------------------------------*/

int main(void){  

   int auxiliar = 9;
   node *tree = NULL;
   lstNum *LST = cria_lista();

   while(auxiliar != 0){
   	system("CLS");
      printf("Especifique o comando:\n");
      printf("1 -> Inserir na lista\n");
      printf("2 -> Imprimir lista\n");
      printf("3 -> Imprimir arvore\n");
      printf("4 -> Delete/n"); //commit
      printf("0 -> Parar\n");

      scanf("%d" , &auxiliar);
    	system("CLS");
    	
      switch(auxiliar){
      	case 1:{
			int novo = novo_num(); 
         	LST = insere_no_fim(LST, novo);
      	 	break;
			} 
	
      	case 2:{
			printf("Lista: ");
        	imprime_lista(LST);
         	printf("\n");
         	system("PAUSE");
        	break;
			}
         
    	case 3:{
			printf("Arvore Inorder: ");
      		int i;
      		while(LST!=NULL){ //alimentar a árvore com a lista
      		tree = insert(tree, LST->dado);
      		LST = LST->next;
      	    }
      		inorder(tree);
	    	printf("\n");
	    	system("PAUSE");
	    	break;	
			} 
	      case 4:{
		      printf("\nEnter a data:");
		scanf("%d",& x);
		root = Delete(root, x);
		break;
	    }
	}
   return 0;
}

// Criação da lista: retorna uma lista vazia
lstNum *cria_lista(){
   return NULL;
}

//    Imprime a lista.
//    Esta função é um exemplo de como percorrer uma lista encadeada.
void imprime_lista(lstNum *lista){
//    "atual" é um ponteiro para o elemento da lista que está sendo examinado. Inicialmente, aponta para o primeiro elemento
   lstNum *atual = lista; 

   while(atual!=NULL){
      printf("%d; ", atual->dado);
      atual = atual->next;
   }
}

lstNum *insere_no_fim(lstNum *lista, int dado){
	
	lstNum *novo = malloc(sizeof(lstNum));
	
	novo->dado = dado;
	novo->next = NULL;
	
	if(lista == NULL)
		lista = novo;
	else{
		lstNum *ultimo = lista;
		while(ultimo->next != NULL){
			ultimo = ultimo->next;
		}
		ultimo->next = novo;
	}
	return lista;
}
			
int novo_num(){
   int novo = 0;
   printf("Digite um número: ");
   scanf("%d", &novo);
   return novo;
}

/*-----------------------------Funções-Árovre------------------------------*/
node *insert(node *Tree, int x)
{
	if (Tree == NULL){
		Tree = (node*)malloc(sizeof(node));
		Tree->data = x;
		Tree->left = NULL;
		Tree->right = NULL;
	}
	
	else if (x > Tree->data) { // inserir na sub-árvore da direita
			Tree->right = insert(Tree->right, x);
			if (FatBal(Tree) == -2)
				if (x > Tree->right->data)
					Tree = rotateLeft(Tree);
				else
					Tree = rotateRight(Tree);
		}
		
		else if (x < Tree->data){ // inserir na sub-árvore da esquerda
				Tree->left = insert(Tree->left, x);
				if (FatBal(Tree) == 2)
					if (x < Tree->left->data)
						Tree = rotateRight(Tree);
					else
						Tree = LR(Tree);
			}
	Tree->ht = height(Tree);
	return Tree;
}

node * Delete(node * T, int x)
{
	node * p;
	if (Tree == NULL) {
		return NULL;
	}
	else
		if (x > T -> data) // inserir na sub-árvore da esquerda
		{
			T -> right=Delete(Tree -> right, x);
			if (FatBal(Tree) == 2)
				if (Fatbal(Tree -> left) >= 0)
					Tree = LL(Tree);
				else
					Tree = LR(Tree);
		}
		else
			if (x < Tree -> data) {
				Tree -> left=Delete(Tree -> left, x);
				if (FatBal(Tree) == -2) //Rebalance during windup
					if (FatBal(Tree -> right) <= 0)
						Tree = RR(Tree);
					else
						Tree = RL(Tree);
			}
			else {
				//data to be deleted is found
				if (Tree -> right != NULL) { //delete its inorder succesor
					p = Tree -> right;
					while (p -> left != NULL)
						p = p -> left;
					Tree -> data=p -> data;
					Tree -> right=Delete(Tree -> right, p -> data);
					if (FatBal(Tree) == 2)//Rebalance during windup
						if (FatBal(Tree -> left) >= 0)
							Tree = LL(Tree);
						else
							Tree = LR(Tree); \
				}
				else
					return (Tree -> left);
			}
	Tree -> ht=height(Tree);
	return (Tree);
}

	
int height(node *Tree) //altura da árvore
{
	int lh, rh;
	if(Tree == NULL)
		return 0;
	if(Tree->left == NULL)
		lh = 0;
	else
		lh = 1 + Tree->left->ht;
	if(Tree->right == NULL)
		rh = 0;
	else
		rh = 1 + Tree->right->ht;
	if(lh > rh)
		return lh;
	return rh;
}

node *rotateRight(node *Tree)
{
	node *newTree;
	newTree = Tree->left;
	Tree->left = newTree->right;
	newTree->right = Tree;
	Tree->ht = height(Tree);
	newTree->ht = height(newTree);
	return newTree;
}

node *rotateLeft(node *Tree)
{
	node *newTree;
	newTree = Tree->right;
	Tree->right = newTree->left;
	newTree->left = Tree;
	Tree->ht = height(Tree);
	newTree->ht = height(newTree);
	return newTree;
}

node *LR(node *Tree)
{
	Tree->left = rotateLeft(Tree->left);
	Tree = rotateRight(Tree);
	return Tree;
}

node *RL(node *Tree)
{
	Tree->right = rotateRight(Tree->right);
	Tree = rotateLeft(Tree);
	return Tree;
}

int FatBal(node *Tree) //fator de balanceamento
{
	int lh, rh; //altura esq / altura dir
	if(Tree == NULL)
		return 0;

	if(Tree->left == NULL)
		lh = 0;
	else
		lh = 1 + Tree->left->ht;

	if(Tree->right == NULL)
		rh = 0;
	else
		rh = 1 + Tree->right->ht;

	return (lh - rh);
}

void inorder(node *Tree)
{
	if (Tree != NULL) {
		inorder(Tree->left);
		printf("%d(FB=%d); ", Tree->data, FatBal(Tree));
		inorder(Tree -> right);
	}
	preorder();
}

void preorder(node * Tree)
{
	if (Tree != NULL) {
		printf("%d(FB=%d)", Tree -> data, FatBal(Tree));
		preorder(Tree -> left);
		preorder(Tree -> right);
	}
}
