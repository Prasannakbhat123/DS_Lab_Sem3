#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the Node structure
typedef struct Node {
    int digit;                  // Store a single digit (0-9)
    struct Node* prev;         // Pointer to the previous node
    struct Node* next;         // Pointer to the next node
} Node;

// Definition of the Circular Doubly Linked List structure with a header node
typedef struct {
    Node* header;              // Pointer to the header node
} cdll;  // Changed the name to cdll

// Function to create a new node
Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the cdll
cdll* initializeList() {
    cdll* list = (cdll*)malloc(sizeof(cdll));
    list->header = createNode(-1);  // Create a header node with dummy value
    list->header->next = list->header; // Point to itself (circular)
    list->header->prev = list->header; // Point to itself (circular)
    return list;
}

// Function to insert a digit at the end of the list
void insertDigit(cdll* list, int digit) {
    Node* newNode = createNode(digit);
    Node* last = list->header->prev; // The last node before the header

    newNode->next = list->header;   // New node points to header
    newNode->prev = last;            // New node points to last node

    last->next = newNode;            // Last node's next points to new node
    list->header->prev = newNode;    // Header's prev points to new node
}

// Function to insert a digit at the front of the list (for result)
void insertDigitAtFront(cdll* list, int digit) {
    Node* newNode = createNode(digit);
    Node* first = list->header->next; // First node (after header)

    newNode->next = first;             // New node points to first
    newNode->prev = list->header;      // New node points to header

    first->prev = newNode;             // First node's previous points to new node
    list->header->next = newNode;      // Header's next points to new node
}

// Function to display the number represented by the list
void displayList(cdll* list) {
    Node* current = list->header->next; // Skip header
    if (current == list->header) {
        printf("List is empty.\n");
        return;
    }

    printf("Number: ");
    do {
        printf("%d", current->digit);
        current = current->next;
    } while (current != list->header);
    printf("\n");
}

// Function to add two cdlls
cdll* addNumbers(cdll* num1, cdll* num2) {
    cdll* result = initializeList();
    Node* p1 = num1->header->prev;  // Start from the last node of num1
    Node* p2 = num2->header->prev;  // Start from the last node of num2
    int carry = 0;

    // Loop until both lists are processed and there is no carry
    while (p1 != num1->header || p2 != num2->header || carry) {
        int sum = carry; // Start with the carry
        if (p1 != num1->header) {
            sum += p1->digit; // Add digit from num1
            p1 = p1->prev;    // Move to the previous node
        }
        if (p2 != num2->header) {
            sum += p2->digit; // Add digit from num2
            p2 = p2->prev;    // Move to the previous node
        }
        carry = sum / 10;     // Calculate carry
        insertDigitAtFront(result, sum % 10); // Insert the last digit of sum at the front
    }

    return result;
}

// Function to get user input and insert digits into the list
void inputNumber(cdll* list) {
    char input[100]; // Assuming maximum number length is 99 digits
    printf("Enter a long positive integer: ");
    scanf("%s", input); // Read input as a string

    // Insert each character as a digit into the circular doubly linked list
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            insertDigit(list, input[i] - '0'); // Convert char to int
        } else {
            printf("Invalid input. Please enter digits only.\n");
            exit(1); // Exit if the input is invalid
        }
    }
}

// Function to free the allocated memory for the cdll
void freeList(cdll* list) {
    Node* current = list->header->next;
    Node* nextNode;

    while (current != list->header) {
        nextNode = current->next; // Save next node
        free(current);            // Free current node
        current = nextNode;       // Move to next node
    }
    free(list->header);           // Free header node
    free(list);                   // Free the list structure
}

int main() {
    cdll* num1 = initializeList();
    cdll* num2 = initializeList();

    // Get user input for the two numbers
    inputNumber(num1);
    inputNumber(num2);

    // Display the two numbers
    displayList(num1);
    displayList(num2);

    // Add the two numbers
    cdll* result = addNumbers(num1, num2);

    // Display the result
    displayList(result);

    // Free allocated memory
    freeList(num1);
    freeList(num2);
    freeList(result);

    return 0;
}
