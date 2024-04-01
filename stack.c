#include <stdio.h>
#include <stdlib.h>

#include "tutorials.h"

#ifdef STACK

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef struct stack {
    int length;
    node_t *head;
} stack_t;

void push(stack_t *stack, int value);

int pop(stack_t *stack);

int peek(const stack_t *stack);

stack_t *createStack();

node_t *createNode();

int main() {
    stack_t *stack = createStack();

    if (stack) {
        push(stack, 69);
        printf("[Peek - Push]: %d\n", peek(stack));

        push(stack, 420);
        printf("[Peek - Push]: %d\n", peek(stack));

        printf("[Pop]: %d\n", pop(stack));
        printf("[Peek]: %d\n", peek(stack));

        printf("[Pop]: %d\n", pop(stack));
        printf("[Peek]: %d\n", peek(stack));
    }

    free(stack);
    stack = NULL;

    return 0;
}

void push(stack_t *stack, int value) {
    node_t *node = createNode();

    if (node) {
        node->value = value;

        if (!stack->head) {
            stack->head = node;
        } else {
            node->next = stack->head;
            stack->head = node;
        }

        stack->length++;
    }
}

int pop(stack_t *stack) {
    if (!stack->head) {
        printf("Stack is empty\n");

        return -1;
    }

    node_t *tempNode = stack->head;
    int retVal = tempNode->value;
    stack->head = stack->head->next;

    stack->length--;

    free(tempNode);
    tempNode = NULL;

    return retVal;
}

int peek(const stack_t *stack) {
    if (!stack->head) {
        printf("Stack is empty\n");

        return -1;
    }

    return stack->head->value;
}

node_t *createNode() {
    node_t *node = NULL;
    node = malloc(sizeof(node_t));

    if (node) {
        node->next = NULL;
        node->value = -1;

        return node;
    }

    return NULL;
}

stack_t *createStack() {
    stack_t *stack = malloc(sizeof(stack_t));

    if (stack) {
        stack->head = NULL;
        stack->length = 0;

        return stack;
    }

    free(stack);
    stack = NULL;

    return NULL;
}

#endif
