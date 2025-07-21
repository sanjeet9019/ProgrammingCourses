/***********************************************
* Name        : C Programmer (sanjeet8.23@gmail.com)
* Description : Queue in C (Array-based)
* Date        : 12th July 2025
***********************************************/

#include <stdio.h>
#include "queue.h"

#define SIZE 100
int queue[SIZE];
int front = -1, rear = -1;

// Enqueue: Insert an element at the rear of the queue
void enqueue(int value) {
    printf("Enqueue Operation: Trying to insert %d\n", value);

    if (rear >= SIZE - 1) {
        printf("Queue is full. Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
            printf("Queue was empty. Initializing front to 0\n");
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d at rear position %d\n", value, rear);
    }
}

// Dequeue: Remove and return the element from the front of the queue
int dequeue() {
    printf("Dequeue Operation: Trying to remove element from front\n");

    if (front == -1 || front > rear) {
        printf("Queue is empty. Nothing to dequeue\n");
        return -1;
    } else {
        int value = queue[front];
        printf("Removed %d from front position %d\n", value, front);
        front++;
        if (front > rear) {
            // Reset queue when empty
            front = rear = -1;
            printf("Queue is now empty after dequeue. Resetting front and rear\n");
        }
        return value;
    }
}

// Peek: View the front element without removing it
void peekQueue() {
    printf("Peek Operation: Checking front element\n");

    if (front == -1 || front > rear)
        printf("Queue is empty. No front element\n");
    else
        printf("Front element is %d at position %d\n", queue[front], front);
}

// Display: Show all elements from front to rear
void displayQueue() {
    printf("Display Operation: Showing current queue state\n");

    if (front == -1 || front > rear)
        printf("Queue is empty. Nothing to display\n");
    else {
        printf("Queue elements from front to rear:\n");
        for (int i = front; i <= rear; i++)
            printf("  queue[%d] = %d\n", i, queue[i]);
    }
}

// Demo: Run a complete example sequence of queue operations
void runQueueDemo() {
    printf("\n=== Queue Demo Begins ===\n");

    printf("\n[1] Enqueue 10, 20, 30\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("\n[2] Peek at front element\n");
    peekQueue();

    printf("\n[3] Display current queue contents\n");
    displayQueue();

    printf("\n[4] Dequeue one element\n");
    dequeue();

    printf("\n[5] Peek after dequeue\n");
    peekQueue();

    printf("\n[6] Display queue again\n");
    displayQueue();

    printf("\n[7] Enqueue 40\n");
    enqueue(40);

    printf("\n[8] Final queue contents\n");
    displayQueue();

    printf("\n=== Queue Demo Ends ===\n");
}