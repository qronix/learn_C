#include <stdio.h>
#include <malloc.h>

#include "tutorials.h"
#include "linked_lists.h"


#ifdef LINKED_LISTS

void printList(node_t *head) {
    node_t *current = head;

    if (current == NULL) {
        printf("The list is empty\n");
        return;
    }

    while (current != NULL) {
        printf("%d\n", current->value);

        current = current->next;
    }
}

void append(node_t *head, int val) {
    node_t *current = head;

    if (!current) {
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->value = val;
    current->next->next = NULL;
}

void push(node_t **head, int val) {
    if (!*head) {
        return;
    }

    node_t *newHead = NULL;
    newHead = malloc(sizeof(node_t));

    newHead->next = *head;
    newHead->value = val;
    *head = newHead;
}

int pop(node_t **head) {
    if (*head == NULL) {
        return -1;
    }

    int retValue;

    node_t *newNode = NULL;
    newNode = (*head)->next;
    retValue = (*head)->value;

    free(*head);

    *head = newNode;

    return retValue;
}

int removeLast(node_t **head) {
    int retVal;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->next == NULL) {
        retVal = (*head)->value;
        free(*head);
        *head = NULL;

        return retVal;
    }

    while ((*head)->next->next != NULL) {
        *head = (*head)->next;
    }

    retVal = (*head)->next->value;
    free((*head)->next);
    (*head)->next = NULL;

    return retVal;
}

int removeByIndex(node_t **head, int n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return pop(head);
    }

    node_t *current = *head;

    if (!current) {
        return -1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (current->next == NULL) {
            return -1;
        }

        current = current->next;
    }

    if (current->next == NULL) {
        return -1;
    }


    int retVal;
    node_t *tempNode = NULL;
    tempNode = current->next;
    retVal = tempNode->value;
    current->next = tempNode->next;

    free(tempNode);

    return retVal;
}

int removeFirstWithValue(node_t **head, int val) {
    int index = 0;

    node_t *current = *head;

    if (!current) {
        return -1;
    }

    while (current->next != NULL) {
        if (current->value == val) {
            return removeByIndex(head, index);
        }

        current = current->next;

        index++;
    }

    return -1;
}

node_t *createList(int val) {
    node_t *head = NULL;
    head = malloc(sizeof(node_t));

    if (head) {
        head->next = NULL;
        head->value = val;
    }

    return head;
}

int getItemAtIndex(node_t *head, int index) {
    if (!head) {
        return -1;
    }

    if (index < 0) {
        return -1;
    }

    if (index == 0) {
        return head->value;
    }

    node_t *currentNode = head;
    int currentIndex = 0;

    while (currentNode->next != NULL && currentIndex < index) {
        currentNode = currentNode->next;
        ++currentIndex;
    }

    if (!currentNode) {
        return -1;
    }

    return currentNode->value;
}

int indexOf(node_t *head, int val) {
    if (!head) {
        return -1;
    }

    int currentIndex = 0;
    int retVal = -1;
    node_t *currentNode = head;

    while (currentNode->next != NULL) {
        if (currentNode->value == val) {
            retVal = currentIndex;

            break;
        }

        currentNode = currentNode->next;
        ++currentIndex;
    }

    free(currentNode);

    return retVal;
}

#endif
