/***********************************************
* Name        : C Programmer (sanjeet8.23@gmail.com)
* Description : A dynamic student record management system using singly linked lists.
*               It demonstrates core operations—insert, traverse, search, update,
*               logical delete, and sort—applied to academic data represented via
*               user-defined structures. Logical deletion is handled by marking records
*               rather than removing nodes. Sorting is implemented through a data-swapping
*               variant of bubble sort based on student marks.
*               Emphasizes practical use of pointers, structured data, and modular functions,
*               suitable for educational contexts targeting clean coding and debugging practices.
* Date        : 12th July 2025
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

// ---------------- Function Definitions ----------------

Node* ll_insert(Node* head, int rollNo, const char* name, float marks) {
    printf("[Insert] Creating node: RollNo=%d, Name=%s, Marks=%.2f\n", rollNo, name, marks);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("[Insert] Memory allocation failed for new node!\n");
        return head;
    }

    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->next = NULL;

    if (head == NULL) {
        printf("[Insert] List is empty. New node becomes the head.\n");
        return newNode;
    }

    Node* temp = head;
    int position = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        position++;
    }

    temp->next = newNode;
    printf("[Insert] Node inserted at position %d (end of list).\n", position + 1);
    return head;
}

void ll_traverse(Node* headCopy) {
    printf("Traverse() Student Records:\n");
    if (headCopy == NULL) {
        printf("No records found.\n");
        return;
    }
    while (headCopy != NULL) {
        printf("RollNo: %d, Name: %s, Marks: %.2f\n", headCopy->rollNo, headCopy->name, headCopy->marks);
        headCopy = headCopy->next;
    }
}

Node* ll_search(Node* head, int rollNo) {
    Node *temp = head;
    printf("[Search] Looking for RollNo=%d\n", rollNo);
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("[Search] Match found.\n");
            return temp;
        }
        temp = temp->next;
    }
    printf("[Search] No matching record found.\n");
    return NULL;
}

void ll_logicalDelete(Node* head, int rollNo) {
    printf("[Delete] Logical deletion requested for RollNo=%d\n", rollNo);
    Node* target = ll_search(head, rollNo);
    if (target != NULL) {
        strcpy(target->name, "Deleted");
        target->marks = -1.0;
        printf("[Delete] Record marked as deleted.\n");
    } else {
        printf("[Delete] Record not found.\n");
    }
}

void ll_update(Node* head, int rollNo, const char* newName, float newMarks) {
    printf("[Update] Updating RollNo=%d to Name=%s, Marks=%.2f\n", rollNo, newName, newMarks);
    Node* target = ll_search(head, rollNo);
    if (target != NULL) {
        strcpy(target->name, newName);
        target->marks = newMarks;
        printf("[Update] Record updated successfully.\n");
    } else {
        printf("[Update] Record not found.\n");
    }
}

void ll_sortByMarks(Node* head) {
    printf("[Sort] Initiating sort by marks (ascending).\n");
    if (head == NULL) return;
    int swapped;
    Node *ptr, *lptr = NULL;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != lptr) {
            if (ptr->marks > ptr->next->marks) {
                int rTemp = ptr->rollNo;
                char nTemp[50];
                float mTemp = ptr->marks;
                strcpy(nTemp, ptr->name);

                ptr->rollNo = ptr->next->rollNo;
                strcpy(ptr->name, ptr->next->name);
                ptr->marks = ptr->next->marks;

                ptr->next->rollNo = rTemp;
                strcpy(ptr->next->name, nTemp);
                ptr->next->marks = mTemp;

                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
    printf("[Sort] Sorting complete.\n");
}

/**
 * Function    : ll_deleteNode
 * Description : Deletes a node physically (memory deallocation) from the list based on roll number.
 *               Handles edge cases like deleting head node and empty list.
 */
Node* ll_deleteNode(Node* head, int rollNo) {
    printf("[Delete] Physical deletion requested for RollNo=%d\n", rollNo);

    if (head == NULL) {
        printf("[Delete] List is empty. Nothing to delete.\n");
        return NULL;
    }

    Node *temp = head, *prev = NULL;

    // Case: Head node needs to be deleted
    if (temp->rollNo == rollNo) {
        head = head->next;
        if (temp != NULL) {
            free(temp);
            temp = NULL;
        }
        printf("[Delete] Head node deleted successfully.\n");
        return head;
    }

    // Traverse to find node
    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("[Delete] Record not found. No deletion performed.\n");
        return head;
    }

    prev->next = temp->next;
    if (temp != NULL) {
        free(temp);
        temp = NULL;
    }
    printf("[Delete] Node deleted successfully.\n");
    return head;
}

/**
 * Function    : ll_cleanup
 * Description : Frees all dynamically allocated nodes in the list and sets head to NULL.
 *               Prevents memory leaks in long-running or demo programs.
 */
void ll_cleanup(Node** headRef) {
    Node* current = *headRef;
    int freedCount = 0;

    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        if(temp!=NULL)
        {
            free(temp);
            temp = NULL;
        }
        freedCount++;
    }
    *headRef = NULL;
    printf("[Cleanup] %d node(s) freed. Head pointer is now NULL.\n", freedCount);
}

void runLinkedListDemo() {
    printf("## LinkedList Demo ##\n");
    Node* head = NULL;

    // Inserting initial student records
    head = ll_insert(head, 101, "Ravi", 78.5);
    head = ll_insert(head, 102, "Priya", 82.0);
    head = ll_insert(head, 103, "Aman", 65.0);
    head = ll_insert(head, 104, "Neha", 92.5);
    head = ll_insert(head, 105, "Kabir", 58.0);

    // Traverse
    printf("\n*** All Records ***\n");
    ll_traverse(head);

    // Search
    int queryRoll = 103;
    printf("\n*** Search for Roll No %d ***\n", queryRoll);
    Node* result = ll_search(head, queryRoll);
    if (result != NULL)
        printf("Found: RollNo=%d, Name=%s, Marks=%.2f\n", result->rollNo, result->name, result->marks);
    else
        printf("Roll No %d not found\n", queryRoll);

    // Update
    printf("\n*** Update Record for Roll No 102 ***\n");
    ll_update(head, 102, "Priya Sharma", 88.75);
    ll_traverse(head);

    // Sort by Marks
    printf("\n*** Sorting by Marks (Ascending) ***\nBefore:\n");
    ll_traverse(head);
    ll_sortByMarks(head);
    printf("After:\n");
    ll_traverse(head);

    // Physical deletion demo
    printf("\n*** Physical Delete for Roll No 104 ***\n");
    head = ll_deleteNode(head, 104);
    ll_traverse(head);

    // Logical Delete
    printf("\n*** Logical Delete for Roll No 105 ***\n");
    ll_logicalDelete(head, 105);
    ll_traverse(head);

    // Final cleanup
    printf("\n*** Final Cleanup ***\n");
    ll_cleanup(&head);
    ll_traverse(head);

	printf("## LinkedList Ends ##\n");
}