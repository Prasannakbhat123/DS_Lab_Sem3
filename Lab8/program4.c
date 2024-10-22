#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = 0, rear = 0;

int empty() {
    return front == rear;
}

int dequeue() {
    return queue[front++];
}

void enqueue(int item) {
    queue[rear++] = item;
}

void print_queue() {
    int i;
    for (i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void reverse_queue() {
    int temp[MAX_SIZE];
    int top = 0;
    while (!empty()) {
        temp[top++] = dequeue();
    }
    while (top > 0) {
        enqueue(temp[--top]);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[rear]);
        rear++;
    }
    printf("Original queue: ");
    print_queue();
    reverse_queue();
    printf("Reversed queue: ");
    print_queue();
    return 0;
}