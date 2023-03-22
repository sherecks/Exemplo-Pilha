#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 //tamanho máximo da pilha

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// função que inicializa a pilha
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// função que verifica se a pilha está vazia
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// função que verifica se a pilha está cheia
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// função que adiciona um item ao topo da pilha
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Erro: a pilha está cheia\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// função que remove o item do topo da pilha
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Item removido: %d\n", pop(&stack));
    printf("Item removido: %d\n", pop(&stack));
    printf("Item removido: %d\n", pop(&stack));

    return 0;
}
