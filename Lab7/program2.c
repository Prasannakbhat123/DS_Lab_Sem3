#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int array[MAX_SIZE];
    int front1, rear1;
    int front2, rear2;
    int size;
} TwoCircularQueues;

void initialize(TwoCircularQueues *queues, int size) {
    queues->size = size;
    queues->front1 = 0;
    queues->rear1 = -1;
    queues->front2 = size / 2;
    queues->rear2 = size / 2 - 1;
}

bool isFull1(TwoCircularQueues *queues) {
    return (queues->rear1 + 1) % (queues->size / 2) == queues->front1;
}

bool isFull2(TwoCircularQueues *queues) {
    return ((queues->rear2 + 1) % (queues->size / 2)) + queues->size / 2 == queues->front2;
}

bool isEmpty1(TwoCircularQueues *queues) {
    return queues->front1 == (queues->rear1 + 1) % (queues->size / 2);
}

bool isEmpty2(TwoCircularQueues *queues) {
    return queues->front2 == (queues->rear2 + 1) % (queues->size / 2);
}

void enqueue1(TwoCircularQueues *queues, int item) {
    if (isFull1(queues)) {
        printf("Queue 1 is full\n");
        return;
    }
    queues->array[queues->rear1 + 1] = item;
    queues->rear1 = (queues->rear1 + 1) % (queues->size / 2);
    printf("Enqueued %d to Queue 1\n", item);
}

void enqueue2(TwoCircularQueues *queues, int item) {
    if (isFull2(queues)) {
        printf("Queue 2 is full\n");
        return;
    }
    queues->array[(queues->rear2 + 1) % (queues->size / 2) + queues->size / 2] = item;
    queues->rear2 = (queues->rear2 + 1) % (queues->size / 2);
    printf("Enqueued %d to Queue 2\n", item);
}

int dequeue1(TwoCircularQueues *queues) {
    if (isEmpty1(queues)) {
        printf("Queue 1 is empty\n");
        return -1;
    }
    int item = queues->array[queues->front1];
    queues->front1 = (queues->front1 + 1) % (queues->size / 2);
    return item;
}

int dequeue2(TwoCircularQueues *queues) {
    if (isEmpty2(queues)) {
        printf("Queue 2 is empty\n");
        return -1;
    }
    int item = queues->array[queues->front2];
    queues->front2 = (queues->front2 + 1) % (queues->size / 2) + queues->size / 2;
    return item;
}

void display(TwoCircularQueues *queues) {
    printf("Queue 1: ");
    int i = queues->front1;
    int count = 0;
    while (count < (queues->size / 2)) {
        printf("%d ", queues->array[i]);
        i = (i + 1) % (queues->size / 2);
        count++;
    }
    printf("\n");

    printf("Queue 2: ");
    i = queues->front2;
    count = 0;
    while (count < (queues->size / 2)) {
        printf("%d ", queues->array[i]);
        i = (i + 1) % (queues->size / 2) + queues->size / 2;
        count++;
    }
    printf("\n");
}

int main() {
    TwoCircularQueues queues;
    int size;

    printf("Enter the size of the array (must be even): ");
    scanf("%d", &size);

    if (size % 2 != 0) {
        printf("Size must be even\n");
        return 1;
    }

    initialize(&queues, size);

    while (1) {
        int choice, item;

        printf("\nMenu:\n");
        printf("1. Enqueue to Queue 1\n");
        printf("2. Enqueue to Queue 2\n");
        printf("3. Dequeue from Queue 1\n");
        printf("4. Dequeue from Queue 2\n");
        printf("5. Display Queues\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue to Queue 1: ");
                scanf("%d", &item);
                enqueue1(&queues, item);
                break;
            case 2:
                printf("Enter the item to enqueue to Queue 2: ");
                scanf("%d", &item);
                enqueue2(&queues, item);
                break;
            case 3:
                item = dequeue1(&queues);
                if (item != -1) {
                    printf("Dequeued %d from Queue 1\n", item);
                }
                break;
            case 4:
                item = dequeue2(&queues);
                if (item != -1) {
                    printf("Dequeued %d from Queue 2\n", item);
                }
                break;
            case 5:
                display(&queues);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}