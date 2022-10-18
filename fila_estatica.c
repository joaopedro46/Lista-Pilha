#include <stdio.h>
#include <stdlib.h>
#define TAM 10 //define o tamanho da fila

typedef struct {
	int primeiro;
	int ultimo;
	int itens[TAM];
}Fila;

void iniciar(Fila *fila){

	fila->primeiro = 0;
	fila->ultimo = -1;

}

void enfileirar(Fila *fila, int valor){
    if(fila->itens[TAM-1] )
    {
        printf("A fila está cheia, não é possível enfileirar.\n");
        getchar();
        getchar();
    }
    else
    {
        fila->ultimo++;
        fila->itens[fila->ultimo] = valor;
    }
    
}

void desenfileirar(Fila *fila){
    int auxiliar=0;
    auxiliar = fila->itens[fila->primeiro];
    fila->primeiro++;
    
}


void tamanho(Fila *fila){
    printf("\nO tamanho da fila eh %d\n",(fila->ultimo - fila->primeiro) + 1);
}


int main()
{
    int opcao=-1;
    int valor=0;
    Fila fila;
    int i;
    iniciar(&fila);

        while(opcao!=0)
        {

            valor=0;
            
            printf("\n\nDIGITE 0 PARA SAIR\n");
            printf("Escolha uma opcao\n");
            printf("1: Enfileirar\n");
            printf("2: Desenfileirar\n");
            printf("3: Tamanho\n");
       
            scanf("%d",&opcao);

            switch(opcao)
            {

            case 1:
                printf("Digite um valor para enfileirar\n");
                scanf("%d",&valor);

                enfileirar(&fila, valor);

                break;

            case 2:
                desenfileirar(&fila);
                break;

            case 3:
                tamanho(&fila);
                break;

            case 0:
                printf("Tchau! Ate a proxima\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;

            }


        }

    return 0;
}