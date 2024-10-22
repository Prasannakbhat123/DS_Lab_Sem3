#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Function prototypes
void insertNode(Node** head, int val);
void display(Node* list);
void input(Node** head, int n);
int search(Node* list, int x);
void getUnion(Node* list1, Node* list2, Node** un);
void intersection(Node* list1, Node* list2, Node** inter);

// Function to insert a node at the end of the list
void insertNode(Node** head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(Node* list) {
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

// Function to input elements into the list
void input(Node** head, int n) {
    for (int i = 0; i < n; i++) {
        int val;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insertNode(head, val);
    }
}

// Function to search for a value in the list
int search(Node* list, int x) {
    while (list != NULL) {
        if (list->val == x) {
            return 1;
        }
        list = list->next;
    }
    return 0;
}

// Function to get the union of two lists
void getUnion(Node* list1, Node* list2, Node** un) {
    Node* temp = list1;
    while (temp != NULL) {
        if (search(*un, temp->val) == 0) { // Check if already in union list
            insertNode(un, temp->val);
        }
        temp = temp->next;
    }

    temp = list2;
    while (temp != NULL) {
        if (search(*un, temp->val) == 0) { // Check if already in union list
            insertNode(un, temp->val);
        }
        temp = temp->next;
    }
}

// Function to get the intersection of two lists
void intersection(Node* list1, Node* list2, Node** inter) {
    Node* temp = list1;
    while (temp != NULL) {
        if (search(list2, temp->val)) {
            insertNode(inter, temp->val);
        }
        temp = temp->next;
    }
}

int main() {
    int choice;
    Node* list1 = NULL; // Initialize List 1
    Node* list2 = NULL; // Initialize List 2
    Node* unionList = NULL; // Initialize Union List
    Node* intersectionList = NULL; // Initialize Intersection List

    do {
        printf("\nMenu:\n");
        printf("1. Input elements for List 1\n");
        printf("2. Input elements for List 2\n");
        printf("3. Get Union of List 1 and List 2\n");
        printf("4. Get Intersection of List 1 and List 2\n");
        printf("5. Display List 1\n");
        printf("6. Display List 2\n");
        printf("7. Display Union List\n");
        printf("8. Display Intersection List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements for List 1: ");
                int n1;
                scanf("%d", &n1);
                input(&list1, n1);
                break;
            case 2:
                printf("Enter number of elements for List 2: ");
                int n2;
                scanf("%d", &n2);
                input(&list2, n2);
                break;
            case 3:
                getUnion(list1, list2, &unionList);
                printf("Union of List 1 and List 2 is: ");
                display(unionList);
                break;
            case 4:
                intersection(list1, list2, &intersectionList);
                printf("Intersection of List 1 and List 2 is: ");
                display(intersectionList);
                break;
            case 5:
                printf("List 1: ");
                display(list1);
                break;
            case 6:
                printf("List 2: ");
                display(list2);
                break;
            case 7:
                printf("Union List: ");
                display(unionList);
                break;
            case 8:
                printf("Intersection List: ");
                display(intersectionList);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    // Free allocated memory
    Node* temp;
    while (list1 != NULL) {
        temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        temp = list2;
        list2 = list2->next;
        free(temp);
    }
    while (unionList != NULL) {
        temp = unionList;
        unionList = unionList->next;
        free(temp);
    }
    while (intersectionList != NULL) {
        temp = intersectionList;
        intersectionList = intersectionList->next;
        free(temp);
    }

    return 0;
}
