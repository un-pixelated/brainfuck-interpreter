#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

struct Stack {
        int array[STACK_SIZE];
        int top;
};

typedef struct Stack Stack;

Stack *stack_init(void) {
        Stack *stack = (Stack *) malloc(sizeof(Stack));

        if (stack == NULL) {
                fprintf(stderr, "couldn't initialize stack\n");
                return NULL;
        }

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

void stack_push(Stack *stack, int data) {
        if (stack_full(stack) == 1) {
                fprintf(stderr, "stack overflow\n");
                return;
        }

        stack->top++;
        stack->array[stack->top] = data;
}

int stack_pop(Stack *stack) {
        if (stack_empty(stack) == 1) {
                fprintf(stderr, "stack underflow\n");
                return -1;
        }

        stack->top--;
        return stack->array[stack->top + 1];
}

#endif