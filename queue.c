#include <stdio.h>
#include <stdlib.h>

#include "tutorials.h"

#ifdef QUEUE

typedef struct node {
    int value;
    struct node *next;
} node_t;


typedef struct queue {
    int length;
    node_t *head;
    node_t *tail;
} queue_t;

node_t *createNode();

queue_t *createQueue();

void enqueue(queue_t *queue, int value);

int deque(queue_t *queue);

int peek(const queue_t *queue);


int main() {
    queue_t *queue = createQueue();

    printf("Peek [Empty Queue]: %d\n", peek(queue));

    enqueue(queue, 69);

    printf("Peek [Enqueue 69]: %d\n", peek(queue));

    enqueue(queue, 420);

    printf("Peek [Enqueue 420]: %d\n", peek(queue));

    enqueue(queue, 17);

    printf("Peek [Enqueue 17]: %d\n", peek(queue));

    printf("[Dequeue]: %d\n", deque(queue));

    printf("[Peek]: %d\n", peek(queue));

    printf("[Dequeue]: %d\n", deque(queue));

    printf("[Peek]: %d\n", peek(queue));

    printf("[Dequeue]: %d\n", deque(queue));

    printf("[Peek]: %d\n", peek(queue));

    free(queue);
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

queue_t *createQueue() {
    queue_t *queue = NULL;
    queue = malloc(sizeof(queue_t));

    if (queue) {

        queue->head = queue->tail = NULL;
        queue->length = 0;

        return queue;
    }

    free(queue);

    return NULL;
}

void enqueue(queue_t *queue, int value) {
    // Add item to end of queue
    node_t *node = createNode();

    if (node) {
        node->value = value;

        if (!queue->tail) {
            queue->head = queue->tail = node;

            return;
        }

        queue->tail->next = node;
        queue->tail = node;
    }
}

int deque(queue_t *queue) {
    // Get first node value
    // Update queue head to first -> next
    // decrement queue length
    // set previous first node to null
    // free previous first node
    // return value

    if (!queue->head) {
        printf("Queue is empty!\n");
        return -1;
    }

    int retVal = queue->head->value;

    node_t *temp = queue->head;
    queue->head = NULL;
    free(queue->head);
    queue->head = temp->next;
    queue->length--;

    return retVal;
}

int peek(const queue_t *queue) {
    if (!queue->head) {
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->head->value;
}

#endif
