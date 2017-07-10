#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct reg_no
{
	char string[30];
	struct reg_no *proximo;
};

struct reg_lista
{
	struct reg_no *inicio;//ponteiro para apontar pra o inicio da estrutura reg no
	struct reg_no *fim;//ponteiro para apontar para o fim
};

typedef struct reg_no tipo_no;
typedef struct reg_lista tipo_lista;

void ler_arquivo(tipo_lista *lista, FILE *arquivo)
{
	while(!feof(arquivo))//enquanto nao chegar ao fim do arquivo
	{
		//inserção no final
		tipo_no *ptr_novo;
		ptr_novo = (tipo_no*)malloc(sizeof(tipo_no));//aloca memoria para o novo elemento
		
		fscanf(arquivo, "%s", ptr_novo->string);//lê o palavra por palavra do texto no arquivo e armazena no campo de string 
		
		ptr_novo->proximo = NULL;//ponteiro próximo do novo elemento recebe nulo, uma vez que está sempre na ultima posição
	
		if(lista->inicio == NULL)//caso a lista esteja vazia(primeiro elemento a ser inserido)
		{
			lista->inicio = ptr_novo;//o inicio da lista aponta para o primeiro elemento inserido		
		}
		else//caso a lista ja tenha elementos
		{
			lista->fim->proximo = ptr_novo;//o campo proximo do ultimo elemento da lista aponta para o novo elemento
		}
		lista->fim = ptr_novo;//atualiza o fim da lista para apontar para o novo elemento inserido
	}
}

int calcular_tamanho_lista(tipo_lista *lista)
{
	int tamanho=0;
	tipo_no *ptr_atual;
	ptr_atual = lista->inicio;
	
	while(ptr_atual != NULL)
	{
		tamanho++;
		ptr_atual=ptr_atual->proximo;
	}
	return tamanho;
}

void verificar_ocorrencia(tipo_lista *lista)
{
	int i, j, ocorrencia=1, tam;
	
	tipo_no *ptr_atual, *ptr_aux, *ptr_apagar, *ptr_anterior = NULL;
	ptr_atual = lista->inicio;
	//-----------------------------------------------------------Dicionario de variáveis----------------------------------------------------------------------
	//ptr atual prende o for de fora
	//ptr auxiliar percorre o for de dentro
	//ptr apagar é uma auxiliar para dar free na segunda ou mais ocorrencia da palavra
	//ptr anterior marca o elemento anterior a ptr auxiliar
	
	for(ptr_atual = lista->inicio; ptr_atual != NULL; ptr_atual=ptr_atual->proximo)//for para percorrer a lista prendendo as posições
	{
		ptr_anterior = ptr_atual;//inicia o ponteiro anterior sempre na posição do atual, pois o auxiliar estará uma "casa" a frente
		for(ptr_aux = ptr_atual->proximo; ptr_aux != NULL; ptr_aux=ptr_aux->proximo)//for para varrar o resto da lista
		{
			if(strcmp(ptr_atual->string,ptr_aux->string)==0)//compara de a string do elemento preso é igual ao do restante da lista
			{
				ocorrencia++;//incrementa a ocorrencia
				
				if(ptr_aux->proximo == NULL)//caso o auxiliar(elemetno da ocorrencia) seja o ultimo elemento(ultimo elemento da lista)
				{
					//exclui elemento
					lista->fim = ptr_anterior;
					ptr_anterior->proximo=NULL;
					free(ptr_aux);
				}
				else//caso o elemento repetido esteja no meio da lista
				{
					ptr_apagar = ptr_aux;
					ptr_anterior->proximo = ptr_aux->proximo;
					free(ptr_apagar);
				}
			}
			ptr_anterior = ptr_aux;//incrementa o ponteiro anterior
		}
		if(ocorrencia == 0)
		{
			printf("Palavra: %s - Ocorrencia: 1 \n", ptr_atual->string);
		}
		else
		{
			printf("Palavra: %s - Ocorrencia: %d \n", ptr_atual->string, ocorrencia);
			ocorrencia = 1;
		}
	}
}

void imprimir_lista(tipo_lista *lista)
{
	tipo_no *ptr_atual;
	ptr_atual = lista->inicio;
	
	while(ptr_atual != NULL)
	{
		printf("Palavra: %s \n", ptr_atual->string);
		printf("Proximo: %p\n", ptr_atual->proximo);
		ptr_atual = ptr_atual->proximo;
	}
}

int main()
{
	FILE *arquivo;
	arquivo = fopen("texto.txt", "r");
	
	if(arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo");
		return 1;
	}
	
	tipo_lista lista;
	int opcao, tam;
	lista.inicio = NULL;
	lista.fim=NULL;
	
	do
	{
		printf("1-Preencher a lista. \n");
		printf("2- Imprimir lista de palavras. \n");
		printf("3- Verificar ocorrencia de palavras. \n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				ler_arquivo(&lista,arquivo);
			break;
			case 2:
				imprimir_lista(&lista);
			break;
			case 3:
				verificar_ocorrencia(&lista);
			break;
		}
		
	}while(opcao!=0);
	
	return 0;
}
