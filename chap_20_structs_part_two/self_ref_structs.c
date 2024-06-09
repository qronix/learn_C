#include <stdio.h>
#include <stdlib.h>

#include "../tutorials.h"

#ifdef SELF_REFERENTIAL_STRUCTS
// Self-referential structs are a common pattern as seen in graph like data structures
// where it's useful to be able to have pointers to the connected nodes/vertices
struct node {
    int data;
    struct node *next;
};

// This is the exact pattern we used when working with linked lists

int main(void){
    struct node *head;

// Hackishly set up a linked list (11)->(22)->(33)
    head = malloc(sizeof(struct node));
    head->data = 11;
    head->next = malloc(sizeof(struct node));
    head->next->data = 22;
    head->next->next = malloc(sizeof(struct node));
    head->next->next->data = 33;
    head->next->next->next = NULL;
// Traverse it
    for (struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d\n", cur->data);
    }

    free(head);

    return 0;
}
#endif
