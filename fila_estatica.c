#include <stdio.h>
#include <stdlib.h>
#define TAM 10 //define o tamanho da fila

typedef struct {
	int primeiro;
	int ultimo;
	int itens[TAM];
}Fila;

void iniciar(Fila *fila){

	fila->primeiro = -1;
	fila->ultimo = -1;

}

void enfileirar(Fila *fila, int valor){
 
    if((fila->ultimo + 1)%TAM == fila->primeiro)
    {
        printf("Não é possível enfileirar, a fila está cheia.");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }
    else if(fila->ultimo == -1 && fila->primeiro == -1)
    {
        fila->ultimo = 0;
        fila->primeiro = 0;
    }
    else
    {
        fila->ultimo = (fila->ultimo + 1) % TAM;
    }
    fila->itens[fila->ultimo] = valor;    

}

void desenfileirar(Fila *fila){
    
    if((fila->ultimo == -1 && fila->primeiro == -1))
    {
        printf("Não foi possível desenfileirar, a fila está vazia.");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }
    else if (fila->ultimo == fila->primeiro)
    {
        fila->primeiro = -1;
        fila->ultimo = -1;
    }
    else
    {
        int auxiliar=0;
        auxiliar = fila->itens[fila->primeiro];
        fila->primeiro = (fila->primeiro + 1) % TAM;
    }   
}


void tamanho(Fila *fila){

    if(fila->ultimo == -1 && fila->primeiro == -1)
    {
        printf("A fila está vazia.\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }
    printf("O tamanho da fila eh: %d\n",(fila->ultimo - fila->primeiro) + 1);
    
}

void exibir_elementos(Fila *fila)
{
    system("clear || cls");
    if(fila->ultimo == -1 && fila->primeiro == -1)
    {
        printf("A fila está vazia.\n");
    }
    else
    {
        printf("A fila possui %d elementos:\n",(fila->ultimo - fila->primeiro) + 1);
        int i;
        for(i = fila->primeiro; i != (fila->ultimo + 1) % TAM; i = (i + 1) % TAM)
        {
            printf("%d\t",fila->itens[i]);
        }
        //printf("%d\t",fila->itens[fila->ultimo]);
    }
    printf("\nAperte ENTER para continuar...");
    getchar();
    getchar();
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
            printf("4: Exibir elementos\n");
       
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
            
            case 4:
                exibir_elementos(&fila);
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