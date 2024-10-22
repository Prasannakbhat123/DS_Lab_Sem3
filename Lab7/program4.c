#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define a maximum size for the stacks

typedef struct {
    int top;
    int data[MAX];
} Stack;

typedef struct {
    Stack stack1;
    Stack stack2;
} Queue;

// Function prototypes
void initStack(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);

int main() {
    Queue q;
    initStack(&q.stack1);
    initStack(&q.stack2);
    
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                printf("Enqueued %d\n", value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) { // Check if dequeue was successful
                    printf("Dequeued %d\n", value);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Error value
    }
    return stack->data[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Error value
    }
    return stack->data[stack->top];
}

void enqueue(Queue* q, int value) {
    push(&q->stack1, value);
}

int dequeue(Queue* q) {
    if (isEmpty(&q->stack2)) {
        // Transfer elements from stack1 to stack2
        while (!isEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    
    // If stack2 is still empty, queue is empty
    if (isEmpty(&q->stack2)) {
        printf("Queue is empty\n");
        return -1; // Error value
    }
    
    return pop(&q->stack2);
}
