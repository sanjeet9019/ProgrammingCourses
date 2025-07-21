############################################################
# Project      : Modular Data Structures in C              #
# Author       : C Programmer (sanjeet8.23@gmail.com)      #
# Description  : Builds array, linked list, stack, queue,  #
#                and tree modules from separate folders.   #
#                Produces a single unified executable.     #
# Usage        : make           → Build the binary         #
#                make clean     → Remove object files      #
# Date         : 12th July 2025                            #
############################################################

CC = gcc
CFLAGS = -Wall -g

OBJS = main.o \
       array/array.o \
       linklist/linklist.o \
       stack/stack.o \
       queue/queue.o \
       tree/tree.o

TARGET = datastructures

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c array/array.h linklist/linklist.h stack/stack.h queue/queue.h tree/tree.h
	$(CC) $(CFLAGS) -c main.c

array/array.o: array/array.c array/array.h
	$(CC) $(CFLAGS) -c array/array.c -o array/array.o

linklist/linklist.o: linklist/linklist.c linklist/linklist.h
	$(CC) $(CFLAGS) -c linklist/linklist.c -o linklist/linklist.o

stack/stack.o: stack/stack.c stack/stack.h
	$(CC) $(CFLAGS) -c stack/stack.c -o stack/stack.o

queue/queue.o: queue/queue.c queue/queue.h
	$(CC) $(CFLAGS) -c queue/queue.c -o queue/queue.o

tree/tree.o: tree/tree.c tree/tree.h
	$(CC) $(CFLAGS) -c tree/tree.c -o tree/tree.o

clean:
	rm -f *.o */*.o $(TARGET)