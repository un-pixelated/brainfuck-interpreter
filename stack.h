#ifndef STACK_H
#define STACK_H

#include "constants.h"

struct Stack {
        int data[STACK_SIZE];
        int top;
};

typedef struct Stack Stack;

Stack *init_stack(void) {
        Stack *stack = (Stack *) malloc(sizeof(Stack));
        stack->top = -1;
        return stack;
}

int stack_empty(Stack *stack) {
        if (stack->top == -1) return 1;
        return 0;
}

int stack_full(Stack *stack) {
        if (stack->top == STACK_SIZE - 1) return 1;
        return 0;
}

#endif