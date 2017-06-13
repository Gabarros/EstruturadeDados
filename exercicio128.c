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
//--------------------------------------------------------------------------------FUNÇOES--------------------------------------------------------------------------------------------------------------------//
void inicializar_lista(tipo_lista *ptr_lista)
{
	ptr_lista = (tipo_lista*)malloc(sizeof(tipo_lista));
	ptr_lista->inicio = NULL;
	ptr_lista->fim = NULL;
}

int verificar_lista_vazia(tipo_lista *ptr_lista)
{
	tipo_no *ptr_atual;
	ptr_atual = ptr_lista->inicio;
	if(ptr_atual == NULL)
	{
		return 0;//lista nula
	}
	return 1;
	
}

void inserir_valor(int numero, tipo_lista *ptr_lista)//insercao escolhida: incluir inicio
{
	tipo_no *ptr_novo;
	ptr_novo = (tipo_no*)malloc(sizeof(tipo_no));//aloca memoria para o ponteiro novo
	
	ptr_novo->numero = numero;//ponteiro novo recebe o valor que o usuario digitou
	
	if(ptr_lista->inicio == NULL)//verifica se a lista é nula
	{
		ptr_novo->proximo = NULL;//faz o campo proximo do ponteiro novo receber nulo, uma vez que só tem ele na lista
		ptr_lista->fim = ptr_novo;//faz o fim apontar para o unico elemento da lista
	}
	else//trata o caso de a lista nao estar vazia
	{
		ptr_novo->proximo = ptr_lista->inicio;//faz o proximo do ponteiro novo, apontar para onde o inicio da lista aponta
	}
	ptr_lista->inicio = ptr_novo;//faz o inicio apontar sempre para o primeiro elemento que está sendo inserido
}
int main()
{
	tipo_lista *ptr_lista;
	int opcao, valor;
	inicializar_lista(ptr_lista);//passo o ponteiro que aponta para o tipo_lista
	
	printf("1- Verificar lista vazia. \n");
	printf("2- Inserir na lista. \n");
	
	scanf("%d", &opcao);
	switch(opcao)
	{
		case 1:
			if(verificar_lista_vazia(ptr_lista)==0)
			{
				printf("Lista esta vazia. \n");
			}
			else
			{
				printf("Lista nao esta vazia. \n");
			}
		break;
		case 2:
			printf("Digite o valor a ser inserido: \n");
			scanf("%d", &valor);
			
			inserir_lista(valor,ptr_lista);
	}
	
	
	return 0;
}
