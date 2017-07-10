#include<stdio.h>
#include<stdlib.h>

struct reg_no
{
    int numero;
    struct reg_no *proximo;
};

struct reg_lista
{
	struct reg_no *inicio;//ponteiro para apontar pra o inicio da estrutura reg no
	struct reg_no *fim;//ponteiro para apontar para o fim
};

typedef struct reg_no tipo_no;
typedef struct reg_lista tipo_lista;
//---------------------------------------------------------------------FUNCOES-------------------------------------------------------------------------------
void inserir_elemento(int numero, tipo_lista *lista)//inserir no inicio
{
	tipo_no *ptr_novo;
	ptr_novo = (tipo_no*)malloc(sizeof(tipo_no));
	ptr_novo->numero = numero;
	
	if(lista->inicio == NULL)//lista vazia
	{
		ptr_novo->proximo = NULL;	
		lista->fim = ptr_novo;
	}
	else
	{
		ptr_novo->proximo = lista->inicio;
	}
	lista->inicio=ptr_novo;
}

void imprimir_lista(tipo_lista *lista)
{
	tipo_no *ptr_atual;
	ptr_atual = lista->inicio;
	
	while(ptr_atual != NULL)
	{
		printf("Numero: %d \n", ptr_atual->numero);
		ptr_atual = ptr_atual->proximo;
	}
}

void inserir_final(int numero, tipo_lista *lista)
{
	tipo_no *ptr_novo;
	ptr_novo = (tipo_no*) malloc(sizeof(tipo_no));
	ptr_novo->numero = numero;
	ptr_novo->proximo = NULL;
	
	if(lista->inicio == NULL)//nenhum elemento inserido
	{
		lista->inicio = ptr_novo;
	}
	else
	{
		lista->fim->proximo = ptr_novo;
	}
	lista->fim = ptr_novo;
}

int excluir_elemento(tipo_lista *lista)//exclusao no inicio
{
	tipo_no *ptr_auxiliar;
	ptr_auxiliar = lista->inicio;
	if(lista->inicio != NULL)//se a lista estiver preenchida
	{
		lista->inicio = lista->inicio->proximo;
		free(ptr_auxiliar);
		if(lista->inicio == NULL)
		{
			lista->fim = NULL;
		}
		return 0;
	}
	return 1;
}

void concatenar_listas(tipo_lista *lista1, tipo_lista *lista2)
{
	
	while(lista2->inicio != NULL)
	{
		inserir_final(lista2->inicio->numero, lista1);
		excluir_elemento(lista2);
	}
}



int main()
{
	tipo_lista lista1, lista2;
	int opcao, numero;
	lista1.inicio = NULL;
    lista1.fim = NULL;
    
    lista2.inicio = NULL;
    lista2.fim = NULL;
    
    do
	{
    	printf("1- Inserir elemento na lista 1. \n");
		printf("2- Inserir elemento na lista 2. \n");
		printf("3- Concatenar listas. \n");
		printf("4- Imprimir lista 1. \n");
		printf("5- Imprimir lista 2. \n");
		printf("6- Imprimir lista concatenada \n");
		scanf("%d", &opcao);
		switch(opcao)
		{
			case 1:
				printf("Digite o valor a ser inserido na lista 1: \n");
				scanf("%d", &numero);
				inserir_elemento(numero,&lista1);
			break;
			case 2:
				printf("Digite o valor a ser inserido na lista 2: \n");
				scanf("%d", &numero);
				inserir_elemento(numero,&lista2);
			break;
			case 3:
				concatenar_listas(&lista1, &lista2);
			break;
			case 4:
				imprimir_lista(&lista1);
			break;
			case 5:
				imprimir_lista(&lista2);
			break;
			case 6:
				imprimir_lista(&lista1);
			break;
		}	
	}while(opcao!=0);
	
	
	return 0;
}
