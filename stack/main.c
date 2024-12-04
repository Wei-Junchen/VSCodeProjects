#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node
{
    int data;
    struct Node* prev;
};

typedef struct stack
{
    struct Node* top;
    size_t size;
}Stack;

void push(Stack* stack,int data)
{
    ++stack->size;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->prev = stack->top;
    stack->top = node;
}

void pop(Stack* stack)
{
    if(stack->size>0)
    {
        --stack->size;
        struct Node* tmp = stack->top->prev;
        free(stack->top);
        stack->top = tmp;
    }
}

int top(Stack* stack)
{
    if(stack->size>0)
        return stack->top->data;
    else 
        return -1;
}

size_t size(Stack* stack)
{
    return stack->size;
}   

Stack* init()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

int main()
{
    Stack* stack = init();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    pop(stack);
    printf("%d %d",top(stack),size(stack));
    return 0;
}