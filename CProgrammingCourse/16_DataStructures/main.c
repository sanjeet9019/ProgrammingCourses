/***********************************************
* Name        : C Programmer (sanjeet8.23@gmail.com)
* Description : Data Structure in C (Modular & Menu-Driven)
* Date        : 12th July 2025
***********************************************/

#include <stdio.h>
#include "array/array.h"
#include "linklist/linklist.h"
#include "stack/stack.h"
#include "queue/queue.h"
#include "tree/tree.h"

typedef enum {
    EXIT = 0,
    ARRAY = 1,
    LINKED_LIST = 2,
    STACK = 3,
    QUEUE = 4,
    TREE = 5
}DataStructureOption;

int main() {
    int choice = 0;
    do {
        printf("\n=== Data Structure Demo Hub ===\n");
        printf("%d. Array Operations\n", ARRAY);
        printf("%d. Linked List Operations\n", LINKED_LIST);
        printf("%d. Stack Operations\n", STACK);
        printf("%d. Queue Operations\n", QUEUE);
        printf("%d. Tree Operations\n", TREE);
        printf("%d. Exit\n", EXIT);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
            case ARRAY:
                runArrayDemo();
                break;
            case LINKED_LIST:
                runLinkedListDemo();
                break;
            case STACK:
                runStackDemo();
                break;
            case QUEUE:
                runQueueDemo();
                break;
            case TREE:
                runTreeDemo();
                break;
            case EXIT:
                printf("Exiting... Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
        printf("\n-----------------------------\n");
    } while (choice != EXIT);

    return 0;
}