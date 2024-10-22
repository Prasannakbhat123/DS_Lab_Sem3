#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Definition of the DLL structure
typedef struct {
    Node* head;
    Node* tail;
} DLL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the DLL
DLL* initializeList() {
    DLL* list = (DLL*)malloc(sizeof(DLL));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to insert a node at the head
void insertAtHead(DLL* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) { // If list is empty
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Function to insert a node at the tail
void insertAtTail(DLL* list, int data) {
    Node* newNode = createNode(data);
    if (list->tail == NULL) { // If list is empty
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to delete a node from the head
void deleteFromHead(DLL* list) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete from head.\n");
        return;
    }
    Node* temp = list->head;
    if (list->head == list->tail) { // Only one node
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the tail
void deleteFromTail(DLL* list) {
    if (list->tail == NULL) {
        printf("List is empty, cannot delete from tail.\n");
        return;
    }
    Node* temp = list->tail;
    if (list->head == list->tail) { // Only one node
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(temp);
}

// Function to display the list
void displayList(DLL* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = list->head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <=> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Menu-driven interface
int main() {
    DLL* list = initializeList();
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Delete from Head\n");
        printf("4. Delete from Tail\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at head: ");
                scanf("%d", &data);
                insertAtHead(list, data);
                break;
            case 2:
                printf("Enter data to insert at tail: ");
                scanf("%d", &data);
                insertAtTail(list, data);
                break;
            case 3:
                deleteFromHead(list);
                break;
            case 4:
                deleteFromTail(list);
                break;
            case 5:
                displayList(list);
                break;
            case 6:
                printf("Exiting...\n");
                free(list);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
