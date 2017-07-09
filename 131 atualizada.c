#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

struct reg_lista
{
    Lista *inicio;
    Lista *fim;
};

typedef struct reg_lista tipo_lista;

void imprimir_lista(tipo_lista *lista)
{
    Lista *ptr_atual = lista->inicio;
    while (ptr_atual != NULL)
    {
        printf("Numero: %d\n", ptr_atual->info);
        ptr_atual = ptr_atual->prox;
    }
    printf("\n");
}

void incluir_final(int numero, tipo_lista *lista){
    Lista *ptr_novo;
    ptr_novo = (Lista*) malloc(sizeof(Lista));
    ptr_novo->info = numero;
    ptr_novo->prox = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = ptr_novo;
    }
    else
    {
        lista->fim->prox = ptr_novo;
    }
    lista->fim = ptr_novo;
}

int* Copia_Lista(tipo_lista *lista, int *num){
    int *vetor, cont = 0;
    Lista *ptr_atual = lista->inicio;
    while(ptr_atual != NULL){
        cont++;
        ptr_atual = ptr_atual->prox;
    }
    *num = cont;
    if(*num == 0)
        return NULL;
    vetor = (int *)malloc((*num)*sizeof(int));
    for(cont = 0, ptr_atual = lista->inicio; cont<(*num); cont++, ptr_atual = ptr_atual->prox){
        vetor[cont] = ptr_atual->info;
    }
    return vetor;
}

void imprime_vetor(int *vetor, int num){
    int cont;
    if(vetor == NULL){
        printf("\nVetor vazio!\n");
    }
    for(cont = 0; cont < num; cont++){
        printf("%d ", vetor[cont]);
    }
    printf("\n");
}

int main(void){

	int opc = 0, num = 0, *vetor = NULL, numero;
    tipo_lista lista;

    lista.inicio = NULL;
    lista.fim = NULL;

	for(;;){
		printf("Entre com sua opcao:\n1 - Preencher lista\n2 - Gerar vetor\n");
		scanf(" %d", &opc);
		printf("\n");

		if(opc!=1 && opc!=2) break;

		switch(opc){
			case 1:
                    printf("Entre com um numero: ");
                    scanf("%d", &numero);
                    incluir_final(numero, &lista);
                    break;
			case 2:
			    vetor = Copia_Lista(&lista, &num);
			    imprime_vetor(vetor, num);
				break;
		}

        printf("\n\nLista\n");
		imprimir_lista(&lista);

	}
	return 0;
}
