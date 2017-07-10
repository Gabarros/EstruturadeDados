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

tipo_lista* intersecta(tipo_lista *lista1, tipo_lista *lista2){

    tipo_lista *lista3 = (tipo_lista *)malloc(sizeof(tipo_lista));//aloca memoria para a terceira lista

    lista3->inicio = NULL;//inicializa o inicio da lista como null
    lista3->fim = NULL;//inicializa o final da lista como null. (Usa setinha pois a vari�vel � um ponteiro)

    tipo_no *ptr_atual1 = lista1->inicio, *ptr_atual2 = lista2->inicio, *ptr_atual3 = lista3->inicio, *ptr_novo = NULL;//cria vari�veis para percorrer as listas e inicializa-as
    int cont = 0;


    while (ptr_atual1 != NULL){//percorrer a lista1 ate o final(prende os elementos da primeira lista)
        while(ptr_atual2 != NULL){//percorrer a lista 2 at� o final(percorre os elementos da segunda para comparar)
            if(ptr_atual1->numero == ptr_atual2->numero){//caso o elemento da listaa 1 seja igual ao da lista 2
                    if(lista3->inicio == NULL){//verifica se � o primeiro elemento a ser inserido na lista 3
                        ptr_novo = (tipo_no*)malloc(sizeof(tipo_no));//aloca memoria para inserir o elemento
                        ptr_novo->numero = ptr_atual1->numero;//faz o campo de n�mero receber o elemento da lista 1
                        ptr_novo->proximo = NULL;//campo proximo do novo elemento aponta para NULL, j� que n�o tem mais nenhum elemento
                        lista3->inicio = ptr_novo;//atualiza o inicio da lista para o novo elemento
                        lista3->fim = ptr_novo;//atualiza o final da lista para o novo elemento
                    }
                    else{//caso a lista 3 j� tenha elementos inseridos
                        while(ptr_atual3 != NULL){//percorre a terceira lista at� o final
                            if(ptr_atual2->numero == ptr_atual3->numero){//conta a quantidade de elementos iguais
                                cont++;
                            }
                            if(ptr_atual3->proximo == NULL) break;//faz parar quando o proximo elemento do do atual for nulo
                            ptr_atual3 = ptr_atual3->proximo;//incrementa o ponteiro para percorrer a lista
                        }
                        if(cont == 0){
                            ptr_novo = (tipo_no*)malloc(sizeof(tipo_no));
                            ptr_novo->numero = ptr_atual1->numero;
                            ptr_novo->proximo = NULL;
                            ptr_atual3->proximo = ptr_novo;
                            lista3->fim = ptr_novo;
                        }
                        cont = 0;
                    }
            }
            ptr_atual3 = lista3->inicio;//posiciona o ponteiro no inicio da lista 3
            ptr_atual2 = ptr_atual2->proximo;//incrementa o ponteiro da lista 2
        }
        ptr_atual2 = lista2->inicio;//volta o ponteiro atual da lista 2 para o inicio da lista, a fim de retormar o loop
        ptr_atual1 = ptr_atual1->proximo;
    }
    return lista3; 
}

int main(void){

	int opc1, opc2, numero;
    tipo_lista lista1, lista2, *lista3;

    lista1.inicio = NULL;
    lista1.fim = NULL;

    lista2.inicio = NULL;
    lista2.fim = NULL;

	for(;;){
		printf("Entre com sua opcao:\n1 - preenche listas\n2 - intersecta listas\n");
		scanf(" %d", &opc1);
		printf("\n");

		if(opc1!=1 && opc1!=2) break;

		switch(opc1){
			case 1:
			    printf("1 - lista 1\n2 - lista 2\n");
                scanf(" %d", &opc2);
			    switch(opc2){
			        case 1:
                        printf("Entre com um numero: ");
                        scanf("%d", &numero);
                        incluir_final(numero, &lista1);
                        break;
                    case 2:
                        printf("Entre com um numero: ");
                        scanf("%d", &numero);
                        incluir_final(numero, &lista2);
                        break;
			    }
			    break;
			case 2:
                lista3 = intersecta(&lista1, &lista2);
                printf("\n\nLista 3\n");
                imprimir_lista(lista3);
				break;
		}

        printf("\n\nLista 1\n");
		imprimir_lista(&lista1);

        printf("\n\nLista 2\n");
        imprimir_lista(&lista2);

	}
	return 0;
}
