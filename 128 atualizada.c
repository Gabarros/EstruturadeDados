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
//--------------------------------------------------------------------------------FUNÃ‡OES--------------------------------------------------------------------------------------------------------------------//
void inicializar_lista(tipo_lista *lista)
{
	lista = (tipo_lista*)malloc(sizeof(tipo_lista));
	lista->inicio = NULL;
	lista->fim = NULL;
}

int verificar_lista_vazia(tipo_lista *lista)
{
	tipo_no *ptr_atual;
	ptr_atual = lista->inicio;
	if(ptr_atual == NULL)
	{
		return 0;//lista nula
	}
	return 1;

}

void inserir_valor(int numero, tipo_lista *lista)//insercao escolhida: incluir inicio
{
	tipo_no *ptr_novo;
	ptr_novo = (tipo_no*)malloc(sizeof(tipo_no));//aloca memoria para o ponteiro novo

	ptr_novo->numero = numero;//ponteiro novo recebe o valor que o usuario digitou

	if(lista->inicio == NULL)//verifica se a lista Ã© nula
	{
		ptr_novo->proximo = NULL;//faz o campo proximo do ponteiro novo receber nulo, uma vez que sÃ³ tem ele na lista
		lista->fim = ptr_novo;//faz o fim apontar para o unico elemento da lista
	}
	else//trata o caso de a lista nao estar vazia
	{
		ptr_novo->proximo = lista->inicio;//faz o proximo do ponteiro novo, apontar para onde o inicio da lista aponta
	}
	lista->inicio = ptr_novo;//faz o inicio apontar sempre para o primeiro elemento que estÃ¡ sendo inserido
}

int excluir_elemento_especifico(int numero, tipo_lista *lista)
{
    tipo_no *ptr_atual = NULL, *ptr_anterior = NULL;

    ptr_atual = lista->inicio;

    if (lista->inicio != NULL)
    {
        while((ptr_atual->proximo != NULL) && (ptr_atual->numero != numero))
        {
            ptr_anterior = ptr_atual;
            ptr_atual = ptr_atual->proximo;
        }
        if ((ptr_anterior == NULL) && (ptr_atual->numero == numero))
        {
            lista->inicio = ptr_atual->proximo;
            if (ptr_atual->proximo == NULL)
            {
                lista->fim = NULL;
            }
            free(ptr_atual);
            return 0;
        }
        else
        {
            ptr_anterior->proximo = ptr_atual->proximo;
            if (ptr_atual->proximo == NULL)
            {
                lista->fim = ptr_anterior;
            }
            free(ptr_atual);
            return 0;
        }
        return 2;
    }
    else
    {
        return 1;
    }
}

int tamanho_lista(tipo_lista *lista){
  int tamanho = 0;
  tipo_no *ptr_atual = NULL, *ptr_anterior = NULL;

  ptr_atual = lista->inicio;

  if (lista->inicio != NULL)
  {
      while((ptr_atual->proximo != NULL))
      {
          ptr_anterior = ptr_atual;
          ptr_atual = ptr_atual->proximo;

          tamanho++;
      }
      return tamanho;
    }
      else
      {
          return 0;
          }
  }

  // float media_lista(int tamanho, tipo_lista *lista){
  //   float media = 0;
  //   int *tamanho_total = 0;
  //   tipo_no *ptr_atual = NULL, *ptr_anterior = NULL;
  //
  //   ptr_atual = lista->inicio;
  //
  //   if (lista->inicio != NULL)
  //   {
  //       while((ptr_atual->proximo != NULL))
  //       {
  //           ptr_anterior = ptr_atual;
  //           ptr_atual = ptr_atual->proximo;
  //           tamanho_total += ptr_atual;
  // 
  //
  //       }
  //       media = (&tamanho_total/tamanho);
  //       return media;
  //     }
  //       else
  //       {
  //           return 0;
  //           }
  //   }

void imprimir_lista(tipo_lista *lista)
{
    tipo_no *ptr_atual = lista->inicio;
    while (ptr_atual != NULL)
    {
        printf("Número: %d\n", ptr_atual->numero);
        printf("Próximo: %p\n", ptr_atual->proximo);
        ptr_atual = ptr_atual->proximo;
    }
}


int main()
{
    int opcao, numero, posicao, verifica, media, tamanho;
    tipo_lista lista;
    int erro;

    lista.inicio = NULL;
    lista.fim = NULL;

    do
    {
        printf("1 - Inicializar Lista\n");
        printf("2 - Verificar se a Lista esta Vazia\n");
        printf("3 - Inserir elemento\n");
        printf("4 - Remover Elemento\n");
        printf("5 - Tamanho da Lista\n");
        printf("6 - Media dos valores da lista\n");
        printf("7 - Exluir Lista\n");
        printf("8 - Imprimir Lista \n");
        printf("0 - Sair do programa\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1: inicializar_lista(&lista);
                    break;

            case 2:

            verifica = verificar_lista_vazia(&lista);

            if (verifica == 0) {
              printf("A Lista estï¿½ Vazia! \n");
            }
            else printf("A Lista Contem Elementos! \n" );

            break;

            case 3: printf("Entre com um número:");
                    scanf("%d", &numero);
                  
                   inserir_valor(numero, &lista);
                   break;

            case 4: printf("Entre com o número a ser excluído:");
                    scanf("%d", &numero);
                    erro = excluir_elemento_especifico(numero, &lista);
                    if (erro == 1)
                    {
                        printf("Lista vazia!!\n\n");
                    }
                    else
                    {
                        if (erro == 2)
                        {
                            printf("Numero não encontrado!!\n\n");
                        }
                    }
                    break;

            case 5:
          tamanho = tamanho_lista(&lista);
            if (tamanho = 0) {
              printf("A lista esta vazia! \n");
            }
            else printf("A lista possui %d elementos!\n", tamanho );

			break;
			
            case 6:
            //tamanho = tamanho_lista(&lista);
            //int media = media_lista(tamanho, &lista);

            if (media == 0) {
            printf("A lista esta vazia \n" );
            }
            else printf("A media da Lista é %f \n", media);
			break;

            case 7:
			break;

            case 8: imprimir_lista(&lista);
                    break;
        }
    }
    while (opcao != 0);
    return 0;
}
