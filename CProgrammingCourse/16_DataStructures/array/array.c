/***********************************************
* Name        : C Programmer (sanjeet8.23@gmail.com)
* Description : Array-based Data Structure in C
* Date        : 12th July 2025
***********************************************/

#include <stdio.h>
#include "array.h"

// Inserts a value at the end of the array if space is available
void insert(int arr[], int *size, int value) {
    printf("Insert Operation: Trying to insert %d\n", value);
    if (*size < MAX_SIZE) {
        arr[*size] = value;
        printf("  Inserted at index %d\n", *size);
        (*size)++;
    } else {
        printf("  Array is full. Cannot insert.\n");
    }
}

// Performs logical deletion by marking the specified index with -1
void logicalDelete(int arr[], int index) {
    printf("Logical Delete: Marking index %d (value %d) as deleted\n", index, arr[index]);
    arr[index] = -1;
}

// Searches for a value and returns its index if found, otherwise -1
int search(int arr[], int size, int key) {
    printf("Search Operation: Looking for %d\n", key);
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("  Found %d at index %d\n", key, i);
            return i;
        }
    }
    printf("  %d not found in array\n", key);
    return -1;
}

// Displays all elements in the array with their indices
void traverse(const int arr[], int size) {
    printf("Traversal Operation: Array contents\n");
    for (int i = 0; i < size; i++) {
        printf("  arr[%d] = %d\n", i, arr[i]);
    }
}

// Returns the value present at a specified index
int access(const int arr[], int index) {
    printf("Access Operation: arr[%d] = %d\n", index, arr[index]);
    return arr[index];
}

// Sorts the array using Bubble Sort (ascending order)
void sort(int arr[], int size) {
    printf("Sort Operation: Bubble Sort in ascending order\n");
    int temp;
    for (int i = 0; i < size - 1; i++) {       
        for (int j = 0; j < size - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {             
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("  Swapped arr[%d] and arr[%d]\n", j, j + 1);
            }
        }
    }
}

// Updates an existing element at a given index with a new value
void update(int arr[], int index, int value) {
    printf("Update Operation: Changing arr[%d] from %d to %d\n", index, arr[index], value);
    arr[index] = value;
}

// Demo: Run a sequence of array operations
void runArrayDemo() {
    int arr[MAX_SIZE] = {40, 10, 30, 20, 50}; 
    int size = 5;

    printf("\n=== Array Demo Begins ===\n");

    printf("\n[1] Insertion\n");
    traverse(arr, size);
    insert(arr, &size, 60);
    traverse(arr, size);

    printf("\n[2] Logical Deletion\n");
    logicalDelete(arr, 2);
    traverse(arr, size);

    printf("\n[3] Search for 40\n");
    search(arr, size, 40);

    printf("\n[4] Traversal\n");
    traverse(arr, size);

    printf("\n[5] Access arr[3]\n");
    access(arr, 3);

    printf("\n[6] Sorting\n");
    sort(arr, size);
    traverse(arr, size);

    printf("\n[7] Update arr[4] to 99\n");
    update(arr, 4, 99);
    traverse(arr, size);

    printf("\n=== Array Demo Ends ===\n");
}