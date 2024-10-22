#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100 // Maximum size of the deque

// Deque structure
typedef struct Deque {
    char arr[MAX_SIZE];
    int front;
    int rear;
} Deque;

// Function prototypes
Deque* createDeque();
void insertRear(Deque* deque, char value);
char deleteFront(Deque* deque);
char deleteRear(Deque* deque);
int isEmpty(Deque* deque);
int isFull(Deque* deque);
void freeDeque(Deque* deque);
int isPalindrome(const char* str);

// Main function
int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

// Create a new deque
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

// Insert an element at the rear of the deque
void insertRear(Deque* deque, char value) {
    if (!isFull(deque)) {
        if (deque->rear == -1) {
            // First element
            deque->front = 0;
            deque->rear = 0;
        } else {
            deque->rear++;
        }
        deque->arr[deque->rear] = value;
    }
}

// Delete and return the front element of the deque
char deleteFront(Deque* deque) {
    if (!isEmpty(deque)) {
        char value = deque->arr[deque->front];
        if (deque->front == deque->rear) {
            // Deque becomes empty
            deque->front = -1;
            deque->rear = -1;
        } else {
            deque->front++;
        }
        return value;
    }
    return '\0'; // Deque is empty
}

// Delete and return the rear element of the deque
char deleteRear(Deque* deque) {
    if (!isEmpty(deque)) {
        char value = deque->arr[deque->rear];
        if (deque->front == deque->rear) {
            // Deque becomes empty
            deque->front = -1;
            deque->rear = -1;
        } else {
            deque->rear--;
        }
        return value;
    }
    return '\0'; // Deque is empty
}

// Check if the deque is empty
int isEmpty(Deque* deque) {
    return deque->front == -1;
}

// Check if the deque is full
int isFull(Deque* deque) {
    return deque->rear >= MAX_SIZE - 1;
}

// Check if the input string is a palindrome
int isPalindrome(const char* str) {
    Deque* deque = createDeque();
    
    // Insert characters into the deque
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {  // Consider only alphanumeric characters
            char lowerChar = tolower(str[i]);
            insertRear(deque, lowerChar);
        }
    }

    // Check for palindrome
    while (!isEmpty(deque)) {
        char frontChar = deleteFront(deque);
        char rearChar = deleteRear(deque);

        // Compare characters from both ends
        if (frontChar != rearChar) {
            // If we've deleted from both ends and they're not equal
            if (frontChar == '\0' || rearChar == '\0') {
                continue; // Handle case when deque becomes empty
            }
            freeDeque(deque);
            return 0; // Not a palindrome
        }
    }

    freeDeque(deque);
    return 1; // Is a palindrome
}

// Free the deque memory
void freeDeque(Deque* deque) {
    free(deque);
}
