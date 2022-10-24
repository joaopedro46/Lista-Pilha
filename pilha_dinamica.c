#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node {
    int data;
    struct node *next;
};
struct node* top = NULL;

void push(int x) {
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    cur -> data = x;
    cur ->next = top;
    top = cur;
    printf("%d enfileirado.\n", cur -> data);
    printf("Aperte ENTER para continuar...");
    getchar();
    getchar();
}

void pop() {
    if(top == NULL)
    {
        printf("A pilha está vazia.\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }
    struct node *cur = top;
    printf("%d desempilhado.\n", cur -> data);
    top = top -> next;
    free(cur);
    printf("Aperte ENTER para continuar...");
    getchar();
    getchar();
}

void print() {
    if(top == NULL)
    {
        printf("A pilha está vazia.\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }
    struct node *cur = top;
    while(cur != NULL)
    {
        printf("%d\t",cur -> data);
        cur = cur -> next;
    }
    printf("\nAperte ENTER para continuar...");
    getchar();
    getchar();
}
int main(){
    setlocale(LC_ALL, "");
    int op = -1, x;
    while(op != 0){
        system("clear || cls");
        printf("1. Empilhar\n2. Desempilhar\n3. Exibir valores\n0. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);
        switch(op) {
            case 0: break;
            
            case 1: printf("Digite o valor: ");
                scanf("%d",&x);
                push(x);
                break;

            case 2: pop();
                break;
            
            case 3: print();
                break;

            default: printf("Opção inválida.\n");
                break;
        }
    }
    return 0;
}
