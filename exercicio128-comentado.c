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
tipo_lista* inicializar_lista()
{
	tipo_lista *ptr_lista;//cria um ponteiro para o tipo lista
	ptr_lista = (tipo_lista*)malloc(sizeof(tipo_lista));//aloca memoria
	ptr_lista->inicio = NULL;//inicializa inicio
	ptr_lista->fim = NULL;//inicializa fim
	
	return ptr_lista;//retorna a lista inicializada
}

int verificar_lista_vazia(tipo_lista *ptr_lista)
{
	if(ptr_lista->inicio == NULL)
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

int excluir_elemento(tipo_lista *ptr_lista)//excluir elemento do inicio
{
	tipo_no *ptr_auxiliar;//ponteiro auxiliar para o tipo de estrutura tipo_no
	ptr_auxiliar = ptr_lista->inicio;
	
	if(ptr_lista->inicio != NULL)//se a lista nao estiver vazia
	{
		ptr_lista->inicio = ptr_lista->inicio->proximo;
		free(ptr_auxiliar);
		if(ptr_lista->inicio == NULL)//verifica se o inicial tem nulo, ou seja, se n tem mais elemento na lista
		{
			ptr_lista->fim = NULL;//bota o final para apontar pra nulo, ja que n tem nada na lista
		}
		return 0;//sucesso
	}
	return 1;//lista vazia
}

int verificar_tamanho_lista(tipo_lista *ptr_lista)
{
	tipo_no *ptr_atual;
	ptr_atual = ptr_lista->inicio;
	int tamanho=0;
	
	if(ptr_lista->inicio != NULL)//verifica se a lista esta preenchida
	{
		while(ptr_atual != NULL)
		{
			tamanho++;//incrementa o tamanho da lista
			ptr_atual = ptr_atual->proximo;//incrementa o valor de ptr_atual para percorrer a lista	
		}
		return tamanho;
	}
	return 0;	
}

int calcular_media_lista(tipo_lista *ptr_lista)
{
	int somatorio=0, tamanho=0;
	tipo_no *ptr_atual;
	ptr_atual = ptr_lista->inicio;//faz ptr_atual começar com o valor do inicio da lista
	
	if(ptr_lista->inicio != NULL)//se a lista estiver preenchida
	{
		while(ptr_atual != NULL)
		{
			somatorio = somatorio + ptr_atual->numero;//faz o somatorio dos elementos na lista
			tamanho++;//conta o tamanho da lista;
			ptr_atual = ptr_atual->proximo;//faz o ponteiro atual andar a lista
		}
		return somatorio/tamanho;
	}
	return 0;//retorno de erro de lista vazia
}

void desalocar_tds_elementos(tipo_lista *ptr_lista)
{
	int erro;
	if(ptr_lista->inicio != NULL)//verifica se a lista esta preenchida
	{
		while(ptr_lista->inicio != NULL)//enquanto ela estiver preenchida excluir elemento
		{ 
			erro = excluir_elemento(ptr_lista);
		}
		printf("Ptr_lista->inicio: %p \n", ptr_lista->inicio);//print para mostrar o valor do inicio da lista
	}
	else
	{
		printf("Lista vazia. \n");
	}

}

void imprimir_lista(tipo_lista *ptr_lista)
{
	tipo_no *ptr_atual;
	ptr_atual = ptr_lista->inicio;
	while(ptr_atual!=NULL)
	{
		printf("Numero: %d \n", ptr_atual->numero);
		ptr_atual = ptr_atual->proximo;
	}
}
//--------------------------------------------------------------------MAIN------------------------------------------------------------------------------------
int main()
{
	tipo_lista *ptr_lista;
	int opcao, valor, erro, tamanho_lista, media;
	ptr_lista = inicializar_lista();//retorna a lista inicializada para o main.
	do
	{
		printf("1- Verificar lista vazia. \n");
		printf("2- Inserir na lista. \n");
		printf("3- Remover elemento da lista. \n");
		printf("4- Verificar tamanho da lista. \n");
		printf("5- Media simples dos elementos da lista. \n");
		printf("6- Desalocar todos os elementos da lista. \n");
		printf("7- Imprimir lista. \n");
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
				inserir_valor(valor,ptr_lista);
				break;
			case 3:
				erro = excluir_elemento(ptr_lista);
				if(erro==1)
				{
					printf("Lista vazia. \n");
				}
			break;
			case 4:
				tamanho_lista = verificar_tamanho_lista(ptr_lista);
				if(tamanho_lista == 0)
				{
					printf("A lista esta vazia. \n");
				}
				else
				{
					printf("Tamanho da lista: %d \n", tamanho_lista);
				}
			break;
			case 5:
				media = calcular_media_lista(ptr_lista);
				if(media == 0)
				{
					printf("A lista esta vazia. \n");
				}
				else
				{
					printf("A media dos elementos da lista e: %d \n", media);
				}
			break;
			case 6:
				desalocar_tds_elementos(ptr_lista);
			break;
			case 7:
				imprimir_lista(ptr_lista);
			break;
		}	
	}while(opcao!=0);
	
	return 0;
}
