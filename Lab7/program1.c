#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Define the maximum number of elements in the queue
#define STR_LEN 100  // Define the maximum length of each string

// Define a structure for the circular queue
typedef struct {
    char data[MAX][STR_LEN];  // Array to hold strings
    int front;  // Index of the front element
    int rear;   // Index of the rear element
    int size;   // Current size of the queue
} CircularQueue;

// Function prototypes
void initializeQueue(CircularQueue *cq);
int isFull(CircularQueue *cq);
int isEmpty(CircularQueue *cq);
void insertcq(CircularQueue *cq, const char *str);
void deletecq(CircularQueue *cq);
void displaycq(CircularQueue *cq);

int main() {
    CircularQueue cq;
    initializeQueue(&cq);

    insertcq(&cq, "Hello");
    insertcq(&cq, "World");
    insertcq(&cq, "Circular");
    insertcq(&cq, "Queue");
    
    displaycq(&cq);
    
    deletecq(&cq);
    displaycq(&cq);

    return 0;
}

// Initialize the circular queue
void initializeQueue(CircularQueue *cq) {
    cq->front = 0;
    cq->rear = -1;
    cq->size = 0;
}

// Check if the circular queue is full
int isFull(CircularQueue *cq) {
    return cq->size == MAX;
}

// Check if the circular queue is empty
int isEmpty(CircularQueue *cq) {
    return cq->size == 0;
}

// Insert a string into the circular queue
void insertcq(CircularQueue *cq, const char *str) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    cq->rear = (cq->rear + 1) % MAX;
    strncpy(cq->data[cq->rear], str, STR_LEN - 1);
    cq->data[cq->rear][STR_LEN - 1] = '\0';  // Ensure null termination
    cq->size++;
}

// Delete a string from the circular queue
void deletecq(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    printf("Deleted: %s\n", cq->data[cq->front]);
    cq->front = (cq->front + 1) % MAX;
    cq->size--;
}

// Display the circular queue
void displaycq(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents:\n");
    for (int i = 0; i < cq->size; i++) {
        int index = (cq->front + i) % MAX;
        printf("%s\n", cq->data[index]);
    }
}
