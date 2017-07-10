#include<stdio.h>
#include<stdlib.h>
//estrutura do nó
struct reg_no
{
    int numero;
    struct reg_no *proximo;
};
//ponteiro para o inicio e fim da lista
struct reg_lista
{
    struct reg_no *inicio;
    struct reg_no *fim;
};

typedef struct reg_no tipo_no;
typedef struct reg_lista tipo_lista;

int verifica_ordem(tipo_lista *lista){
	tipo_no *ptr_atual = lista->inicio;//cria um ponteiro atual e ele recebe o inicio da lista
	//o ponteiro atual será usado para percorrer a lista
	while(ptr_atual != NULL && ptr_atual->proximo != NULL){//faz o ponto de parada ser quando ptr atual está no penultimo elemento, para que possa compará-lo com o ultimo
		if(ptr_atual->numero > ptr_atual->proximo->numero)//compara se o elemento atual é maior que o próximo elemento, caso seja, a lista não está ordenada
			return 1;
		ptr_atual = ptr_atual->proximo;//faz o ptr_atual andar para o proximo elemento(incremento)
	}
	return 0;
}

void incluir_final(int numero, tipo_lista *lista)
{
    tipo_no *ptr_novo;//ponteiro que vai receber o elemento a ser inserido
    ptr_novo = (tipo_no*) malloc(sizeof(tipo_no));//aloca espaço na memória para o ponteiro
    ptr_novo->numero = numero;//capo numero recebe o valor digitado pelo usuario
    ptr_novo->proximo = NULL;//o campo proximo recebe null, já que a inserção é no final
    if (lista->inicio == NULL)//se a lista estiver vazia(primeiro elemento a ser inserido)
    {
        lista->inicio = ptr_novo;//faz o inicio apontar para o novo elemento
    }
    else//caso a lista esteja preenchida
    {
        lista->fim->proximo = ptr_novo;//faz o ponteiro do ultimo elemento apontar para o novo
    }
    lista->fim = ptr_novo;//o fim aponta para o novo elemento(está fora do if/else, pois o código é executado em ambos casos
}

void imprimir_lista(tipo_lista *lista)
{
    tipo_no *ptr_atual = lista->inicio;
    while (ptr_atual != NULL)//enquanto o ponteiro nao chegar a null(ou seja, no fim da lista) ele roda
    {
        printf("Numero: %d\n", ptr_atual->numero);//imprime o numero que está na "posição" do ponteiro atual
        ptr_atual = ptr_atual->proximo;//incrementa o atual
    }
    printf("\n");
}

int main(void){
	
	int opc, numero;
    tipo_lista lista;

    lista.inicio = NULL;//inicializa o inicio da lista com NULL
    lista.fim = NULL;//inicializa o final da lista com NULL
    
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
