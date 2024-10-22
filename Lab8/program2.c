#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define STRING_SIZE 50

typedef struct {
    char deque[MAX][STRING_SIZE];
    int front, rear;
} Output;

void initDeque(Output *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Output *dq) {
    return (dq->front == -1);
}

int isFull(Output *dq) {
    return ((dq->rear + 1) % MAX == dq->front);
}

void insertRear(Output *dq, char *str) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    strcpy(dq->deque[dq->rear], str);
}

void insertFront(Output *dq, char *str) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    strcpy(dq->deque[dq->front], str);
}

void deleteFront(Output *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted: %s\n", dq->deque[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
}

void displayQueue(Output *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Queue: ");
    int i = dq->front;
    while (1) {
        printf("%s\t", dq->deque[i]);
        if (i == dq->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Output dq;
    initDeque(&dq);
    int choice;
    char str[STRING_SIZE];
    while (1) {
        printf("\nOperations:\n");
        printf("1. Insert at rear\n");
        printf("2. Insert at front\n");
        printf("3. Delete from front\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter string to insert at rear: \n");
                scanf("%s", str);
                insertRear(&dq, str);
                break;
            case 2:
                printf("Enter string to insert at front: \n");
                scanf("%s", str);
                insertFront(&dq, str);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                displayQueue(&dq);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}