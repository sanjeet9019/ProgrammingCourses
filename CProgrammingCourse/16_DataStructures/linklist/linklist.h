#ifndef LINKLIST_H
#define LINKLIST_H

// ---------------- Structure Definition ----------------
typedef struct Node {
    int rollNo;
    char name[50];
    float marks;
    struct Node* next;
} Node;

// ---------------- Function Declarations ----------------
Node* ll_insert(Node* head, int rollNo, const char* name, float marks);
void ll_traverse(Node* head);
Node* ll_search(Node* head, int rollNo);
void ll_logicalDelete(Node* head, int rollNo);
void ll_update(Node* head, int rollNo, const char* newName, float newMarks);
void ll_sortByMarks(Node* head);
Node* ll_deleteNode(Node* head, int rollNo);       // ⬅ New: Physical delete by roll number
void ll_cleanup(Node** headRef);                   // ⬅ New: Free all nodes and nullify head
void runLinkedListDemo();

#endif // LINKLIST_H