#include <malloc.h>
#include <stdio.h>

#include "../tutorials.h"
#include "../linked_lists.h"

#ifdef LINKED_LIST_TEST

void logResult(int result, int expected, char *testName) {
    if (result == expected) {
        printf("Test: %s. PASS\n", testName);
    } else {
        printf("Test: %s. FAIL. Expected: %d, Got: %d\n", testName, expected, result);
    }
}

void appendToListTest() {
    node_t *list = createList(69);

    append(list, 420);

    int result = getItemAtIndex(list, 1);
    const int expected = 420;

    logResult(result, expected, "Append to list");

    free(list);
}

void appendTwoItemsToListTest() {
    node_t *list = createList(0);

    append(list, 69);
    append(list, 420);

    int result = getItemAtIndex(list, 1);
    int expected = 69;
    char* testName = "Append two items to list";

    logResult(result, expected, testName);

    result = getItemAtIndex(list, 2);
    expected = 420;

    logResult(result, expected, testName);

    free(list);
}

void pushItemToListTest(){
    node_t* list = createList(0);

    push(&list, 69);

    int result = getItemAtIndex(list, 0);
    int expected = 69;
    char* testName = "Push item to list";

    logResult(result, expected, testName);

    free(list);
}

void removeLastItemFromListTest(){
    node_t* list = createList(0);

    append(list, 69);
    append(list, 420);

    int result = removeLast(&list);
    int expected = 420;

    char* testName = "Remove last item from list";

    logResult(result, expected, testName);

    free(list);
}

void removeLastItemFromListWithOneValueTest(){
    node_t* list = createList(69);

    int result = removeLast(&list);
    int expected = 69;

    char* testName = "Remove last item from list with one value";

    logResult(result, expected, testName);

    free(list);
}

void popItemFromListWithOneItemTest(){
    node_t* list = createList(69);

    int result = pop(&list);
    int expected = 69;
    char* testName = "Pop item from list with one item";

    logResult(result, expected, testName);

    free(list);
}

void removeFirstItemWithValueTest(){
    node_t* list = createList(69);

    push(&list, 420);
    push(&list, 333);
    push(&list, 101);

    int result = removeFirstWithValue(&list, 333);
    int expected = 333;

    char* testName = "Remove first item with value";

    logResult(result, expected, testName);

    free(list);
}

void removeFirstItemWithValueWhichDoesNotExistTest(){
    node_t* list = createList(69);

    push(&list, 420);
    push(&list, 333);
    push(&list, 101);

    int result = removeFirstWithValue(&list, 777);
    int expected = -1;

    char* testName = "Remove first item with value which does not exist";

    logResult(result, expected, testName);

    free(list);
}

void removeItemWithGivenIndexTest(){
    node_t* list = createList(69);

    push(&list, 420);
    push(&list, 22);
    push(&list, 18);
    push(&list, 333);

    int result = removeByIndex(&list, 3);
    int expected = 420;

    char* testName = "Remove item at given index";

    logResult(result, expected, testName);

    free(list);
}

void removeItemWithOutOfBoundsIndexTest(){
    node_t* list = createList(69);

    push(&list, 420);
    push(&list, 22);
    push(&list, 18);
    push(&list, 333);

    int result = removeByIndex(&list, 99);
    int expected = -1;

    char* testName = "Remove item at out of bounds index";

    logResult(result, expected, testName);

    free(list);
}

void removeItemWithNegativeIndexTest(){
    node_t* list = createList(69);

    push(&list, 420);
    push(&list, 22);
    push(&list, 18);
    push(&list, 333);

    int result = removeByIndex(&list, -69);
    int expected = -1;

    char* testName = "Remove item at negative index";

    logResult(result, expected, testName);

    free(list);
}

void getIndexOfItemTest(){
    node_t* list = createList(69);

    push(&list, 420);
    push(&list, 22);
    push(&list, 18);
    push(&list, 333);

    int result = indexOf(list, 420);
    int expected = 3;

    char* testName = "Remove item at index";

    logResult(result, expected, testName);

    free(list);
}

void getIndexOfItemWhichDoesNotExistTest(){
    node_t* list = createList(69);

    push(&list, 420);
    push(&list, 22);
    push(&list, 18);
    push(&list, 333);

    int result = indexOf(list, -22);
    int expected = -1;

    char* testName = "Remove item at index which does not exit";

    logResult(result, expected, testName);

    free(list);
}

int main() {
    appendToListTest();
    appendTwoItemsToListTest();
    pushItemToListTest();
    removeLastItemFromListTest();
    removeLastItemFromListWithOneValueTest();
    popItemFromListWithOneItemTest();
    removeFirstItemWithValueTest();
    removeFirstItemWithValueWhichDoesNotExistTest();
    removeItemWithGivenIndexTest();
    removeItemWithOutOfBoundsIndexTest();
    removeItemWithNegativeIndexTest();
    getIndexOfItemTest();
    getIndexOfItemWhichDoesNotExistTest();

    return 0;
}

#endif
