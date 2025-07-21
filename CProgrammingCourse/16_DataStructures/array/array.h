#ifndef ARRAY_H
#define ARRAY_H

#define MAX_SIZE 10

void insert(int arr[], int *size, int value);
void logicalDelete(int arr[], int index);
int search(int arr[], int size, int key);
void traverse(const int arr[], int size);
int access(const int arr[], int index);
void sort(int arr[], int size);
void update(int arr[], int index, int value);
void runArrayDemo();

#endif