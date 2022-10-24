#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void enqueue(int x){
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    if(!cur) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    cur -> data = x;
    cur ->  next = NULL;
    if(head == NULL && tail == NULL) {
        head = tail = cur;
        printf("%d enfileirado\n",cur -> data);
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }
    tail -> next = cur;
    tail = cur;

    printf("%d enfileirado\n",cur -> data);
    printf("Aperte ENTER para continuar...");
    getchar();
    getchar();
}
void dequeue() {
    struct node *cur = head;
    if(head == NULL)
    {
        printf("A fila está vazia.\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }
    
    if(head == tail){
        head = tail = NULL;
    }
    
    else {
        head = head -> next;
    }
    printf("%d desenfileirado\n",cur -> data);
    free(cur);
    printf("Aperte ENTER para continuar...");
    getchar();
    getchar();
}
void print() {
    if(head == NULL && tail == NULL){
        printf("A lista está vazia.\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    struct node *cur = head;
    printf("Lista: ");
    while(cur != NULL){
        printf("%d\t",cur -> data);
        cur = cur -> next;
    }
    printf("\nAperte ENTER para continuar...");
    getchar();
    getchar();
}
int main() {

    setlocale(LC_ALL,"");
    int op = -1,x;
    while(op != 0)
    {
        system("clear || cls");
        printf("1. Enfileirar\n2. desenfileirar\n3. Exibir valores\n0. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d",&op);
        switch(op) {
            case 0: break;
            
            case 1: printf("Digite o valor: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            
            case 2: dequeue();
                break;
            
            case 3: print();
                break;
                
            default: printf("Opção Inválida.\n");
                printf("Aperte ENTER para continuar...");
                getchar();
                getchar();
                break;
        }
    }
    return 0;
}