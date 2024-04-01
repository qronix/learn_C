
#ifndef LEARN_C_LINKED_LISTS_H
#define LEARN_C_LINKED_LISTS_H
typedef struct node {
    int value;
    struct node* next;
} node_t;

// Print all items in the list
void printList(node_t* head);

// Add an item to the end of the list
void append(node_t* head, int val);

// Add an item to the beginning of the list
void push(node_t** head, int val);

// Remove the first item in the list and return its value
int pop(node_t** head);

// Remove the last item from the list and return its value
int removeLast(node_t** head);

// Remove an item from the list with the given index and return its value
int removeByIndex(node_t** head, int index);

// Remove the first item from the list with the given value and return its value
int removeFirstWithValue(node_t** head, int val);

// Get the value of the list item at the given index
int getItemAtIndex(node_t* head, int index);

// Get the index of the first item with the given value
int indexOf(node_t* head, int val);

// Create an empty list and the head pointer
node_t* createList(int val);

#endif //LEARN_C_LINKED_LISTS_H
