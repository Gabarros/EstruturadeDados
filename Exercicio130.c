#include<stdio.h>
#include<stdlib.h>
struct reg_no
{
    int numero;
    struct reg_no *proximo;
};

struct reg_lista
{
    struct reg_no *inicio;
    struct reg_no *fim;
};

typedef struct reg_no tipo_no;
typedef struct reg_lista tipo_lista;

int verifica_ordem(tipo_lista *lista){
	tipo_no *ptr_atual = lista->inicio;
	
	while(ptr_atual != NULL && ptr_atual->proximo != NULL){
		if(ptr_atual->numero > ptr_atual->proximo->numero)
			return 1;
		ptr_atual = ptr_atual->proximo;
	}
	return 0;
}

void incluir_final(int numero, tipo_lista *lista)
{
    tipo_no *ptr_novo;
    ptr_novo = (tipo_no*) malloc(sizeof(tipo_no));
    ptr_novo->numero = numero;
    ptr_novo->proximo = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = ptr_novo;
    }
    else
    {
        lista->fim->proximo = ptr_novo;
    }
    lista->fim = ptr_novo;
}

void imprimir_lista(tipo_lista *lista)
{
    tipo_no *ptr_atual = lista->inicio;
    while (ptr_atual != NULL)
    {
        printf("Numero: %d\n", ptr_atual->numero);
        ptr_atual = ptr_atual->proximo;
    }
    printf("\n");
}

int main(void){
	
	int opc, numero;
    tipo_lista lista;

    lista.inicio = NULL;
    lista.fim = NULL;
    
	for(;;){
		printf("Entre com sua opcao: ");
		scanf(" %d", &opc);
		printf("\n");
		switch(opc){
			case 1: printf("Entre com um numero:");
                    scanf("%d", &numero);
                    incluir_final(numero, &lista);
                    break;
			case 2:
				if(verifica_ordem(&lista)) printf("\nA lista nao esta ordenada!\n");
				else printf("\nA lista esta ordenada!\n");
				break;
		}
		
		imprimir_lista(&lista);
		
		if(opc!=1 && opc!=2) break;
	}
	return 0;
}
