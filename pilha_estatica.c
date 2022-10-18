#include <stdio.h>
#include <stdlib.h>

// PILHA ESTATICA - VETORES

#define MAX 5

typedef struct{
	int elementos[MAX]; // PILHA ESTATICA
	int topo;
} TPilha;

// CRIAR PILHA
TPilha * criar_pilha(){
	TPilha *ppilha;

	ppilha = calloc(1, sizeof(TPilha)); //ALOCACAO DA MEMORIA
	if(ppilha == NULL)
		exit(1);

	ppilha->topo = 0;

	return ppilha;
}

// EMPILHAR ELEMENTO
void empilhar(TPilha *ppilha, int valor){
	int i = ppilha->topo;
    if(i == 5)
    {
        printf("A pilha está cheia, não é possível empilhar.\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
    }
    else
    {
        ppilha->elementos[i] = valor;
	    ppilha->topo = ppilha->topo + 1;
    }
}

// DESEMPILHAR ELEMENTO
int desempilhar(TPilha *ppilha){
	if(ppilha->topo==0)
    {
        printf("Não é possível desempilhar pois a pilha está vazia.\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return -1;
    }
    int i;

	ppilha->topo = ppilha->topo - 1;

	i = ppilha->topo;

	return ppilha->elementos[i];
}

// MENSURAR TAMANHO DA PILHA
int tamanho(TPilha *ppilha){
	return ppilha->topo;
}

//DESTRUIR PILHA
void destruir_pilha(TPilha *ppilha) {
	free(ppilha);
}

void exibir_elementos(TPilha *ppilha)
{
    system("clear || cls");
    int i=0;
    printf("A pilha possui %d elementos:\n\n",ppilha->topo);
    for(i=0;i<ppilha->topo;i++)
    {
        printf("%d\t",ppilha->elementos[i]);
    }
    printf("\n\nAperte ENTER para continuar...");
    getchar();
    getchar();
}
int main(void) {
  int op;
  int valor;
  
  TPilha *ppilha;

  ppilha = criar_pilha();

  printf("\n------ PILHA ESTATICA -------");

  do{
      printf("\n 1 - Empilhar");
      printf("\n 2 - Desempilhar");
      printf("\n 3 - Tamanho da pilha");
      printf("\n 4 - Exibir elementos da pilha");
      printf("\n 5 - Sair");
      printf("\n Digite a opcao: ");
      scanf("%d", &op);

      switch(op){
            case 1:
                printf("\n Digite o valor: ");
                scanf("%d", &valor);
                empilhar(ppilha, valor);
                break;
            case 2:
                valor = desempilhar(ppilha);
                printf("\n Valor: %d \n", valor);
                break;
            case 3:
                valor = tamanho(ppilha);
                printf("\n Tamanho: %d\n", valor);
                break;
            case 4:
                exibir_elementos(ppilha);
                break;
      }

  } while(op != 5);

  destruir_pilha(ppilha);

  return 0;
}
