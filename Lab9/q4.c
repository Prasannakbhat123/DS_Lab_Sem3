#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the singly linked list
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int val);
void appendNode(Node** head, int val);
void display(Node* head);
void input(Node** head, int n);
void deleteDuplicates(Node* head);

int main() {
    int n;
    Node* list = NULL; // Initialize the head of the linked list
    printf("Enter length of list: ");
    scanf("%d", &n);
    printf("Enter input for list (in ascending order):\n");
    input(&list, n); // Populate the list with user input
    printf("Original List: ");
    display(list); // Display original list
    deleteDuplicates(list); // Remove duplicates
    printf("After removing duplicates: ");
    display(list); // Display modified list
    return 0;
}

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the linked list
void appendNode(Node** head, int val) {
    Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to take input for the linked list
void input(Node** head, int n) {
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        appendNode(head, val);
    }
}

// Function to display the linked list
void display(Node* head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Function to delete duplicates from a sorted linked list
void deleteDuplicates(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            // Duplicate found, skip the next node
            Node* temp = current->next; // Temporary node to hold the duplicate
            current->next = current->next->next; // Bypass the duplicate
            free(temp); // Free the memory of the duplicate node
        } else {
            current = current->next; // Move to the next node
        }
    }
}
