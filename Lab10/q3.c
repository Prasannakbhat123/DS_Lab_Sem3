#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the Node structure
typedef struct Node {
    char* data;               // Store a string (word)
    struct Node* prev;        // Pointer to the previous node
    struct Node* next;        // Pointer to the next node
} Node;

// Function to create a new node
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = strdup(word); // Allocate memory and copy the string
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head, const char* word) {
    Node* newNode = createNode(word);
    if (*head == NULL) {
        *head = newNode; // If list is empty, make new node the head
    } else {
        Node* last = *head;
        while (last->next != NULL) { // Find the last node
            last = last->next;
        }
        last->next = newNode; // Link new node at the end
        newNode->prev = last; // Set the prev pointer
    }
}

// Function to reverse the doubly linked list
void reverseList(Node** head) {
    Node* temp = NULL;
    Node* current = *head;

    // Swap the prev and next pointers for each node
    while (current != NULL) {
        temp = current->prev; // Store previous node
        current->prev = current->next; // Swap
        current->next = temp; // Swap
        current = current->prev; // Move to next node
    }

    // Adjust the head pointer to the new head
    if (temp != NULL) {
        *head = temp->prev; // The new head is the last non-null node
    }
}

// Function to display the list
void displayList(Node* node) {
    while (node != NULL) {
        printf("%s ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to free the list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data); // Free the string
        free(temp);       // Free the node
    }
}

// Function to take input from the user
void inputWords(Node** head) {
    char word[100]; // Buffer to store each word
    printf("Enter words (type 'END' to finish):\n");
    
    while (1) {
        printf("Enter a word: ");
        scanf("%s", word);
        if (strcmp(word, "END") == 0) { // Stop input if user types "END"
            break;
        }
        insertEnd(head, word); // Insert the word into the list
    }
}

int main() {
    Node* head = NULL;

    // Get user input for the words
    inputWords(&head);

    // Display the original list
    printf("\nOriginal list:\n");
    displayList(head);

    // Reverse the doubly linked list
    reverseList(&head);

    // Display the reversed list
    printf("Reversed list:\n");
    displayList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
