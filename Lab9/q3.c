#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the singly linked list
typedef struct Node {
    int height;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int height) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->height = height;
    newNode->next = NULL;
    return newNode;
}
// Function to append a node to the end of the linked list
void appendNode(Node** head, int height) {
    Node* newNode = createNode(height);
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
// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->height);
        current = current->next;
    }
    printf("\n");
}
// Function to merge two sorted linked lists
Node* mergeLists(Node* listA, Node* listB) {
    Node* mergedList = NULL;
    Node** tail = &mergedList;

    while (listA != NULL && listB != NULL) {
        if (listA->height <= listB->height) {
            *tail = listA;
            listA = listA->next;
        } else {
            *tail = listB;
            listB = listB->next;
        }
        tail = &((*tail)->next);
    }

    // If one of the lists is not exhausted, append it to the merged list
    if (listA != NULL) {
        *tail = listA;
    } else if (listB != NULL) {
        *tail = listB;
    }

    return mergedList;
}

int main() {
    int N1, N2;

    // Input the number of students in class A and class B
    printf("Enter number of students in class A: ");
    scanf("%d", &N1);
    printf("Enter number of students in class B: ");
    scanf("%d", &N2);

    Node* listA = NULL; // Initialize the head of list A
    Node* listB = NULL; // Initialize the head of list B

    // Input heights for class A
    printf("Enter heights for class A (in ascending order):\n");
    for (int i = 0; i < N1; i++) {
        int height;
        scanf("%d", &height);
        appendNode(&listA, height);
    }

    // Input heights for class B
    printf("Enter heights for class B (in ascending order):\n");
    for (int i = 0; i < N2; i++) {
        int height;
        scanf("%d", &height);
        appendNode(&listB, height);
    }

    // Display class A and class B
    printf("Class A heights: ");
    displayList(listA);
    printf("Class B heights: ");
    displayList(listB);

    // Merge the two lists
    Node* mergedList = mergeLists(listA, listB);
    printf("Merged class heights: ");
    displayList(mergedList);

    return 0;
}

