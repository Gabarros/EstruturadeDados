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

    tipo_lista *lista3 = (tipo_lista *)malloc(sizeof(tipo_lista));

    lista3->inicio = NULL;
    lista3->fim = NULL;

    tipo_no *ptr_atual1 = lista1->inicio, *ptr_atual2 = lista2->inicio, *ptr_atual3 = lista3->inicio, *ptr_novo = NULL;
    int cont = 0;


    while (ptr_atual1 != NULL){
        while(ptr_atual2 != NULL){
            if(ptr_atual1->numero == ptr_atual2->numero){
                    if(lista3->inicio == NULL){
                        ptr_novo = (tipo_no*)malloc(sizeof(tipo_no));
                        ptr_novo->numero = ptr_atual1->numero;
                        ptr_novo->proximo = NULL;
                        lista3->inicio = ptr_novo;
                        lista3->fim = ptr_novo;
                    }
                    else{
                        while(ptr_atual3 != NULL){
                            if(ptr_atual2->numero == ptr_atual3->numero){
                                cont++;
                            }
                            if(ptr_atual3->proximo == NULL) break;
                            ptr_atual3 = ptr_atual3->proximo;
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
            ptr_atual3 = lista3->inicio;
            ptr_atual2 = ptr_atual2->proximo;
        }
        ptr_atual2 = lista2->inicio;
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
		printf("Entre com sua opcao:\n1 - Preencher listas \n2 - Intersectar listas\n");
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
