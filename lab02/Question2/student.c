// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));

    queue->data = (int*) malloc(sizeof(int) * k);
    queue->capacity = k;
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;

    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size == obj->capacity) {
        return false;
    }

    obj->data[obj->tail] = value;
    obj->size++;

    if(obj->tail == obj->capacity - 1) {
        obj->tail = 0; // wrap
    } else {
        obj->tail++; // don't wrap
    }

    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->size == 0) {
        return false;
    }

    if(obj->head == obj->capacity - 1) {
        obj->head = 0;
    } else {
        obj->head++;
    }

    obj->size--;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->size == 0) {
        return -1;
    }

    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->size == 0) {
        return -1;
    }
    
    if(obj->tail == 0) {
        return obj->data[obj->capacity - 1];
    }

    return obj->data[obj->tail - 1];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->size == 0) {
        return true;
    }

    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->size == obj->capacity) {
        return true;
    }
    return false;
 
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}
