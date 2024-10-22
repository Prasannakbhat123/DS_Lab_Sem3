#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a singly circular linked list
typedef struct Node {
    int coeff;         // Coefficient of the term
    int power;        // Power of the term
    struct Node* next; // Pointer to the next node
} Node;

// Define a circular linked list with a header node
typedef struct {
    Node* header; // Header node
} CLList; // Shortened name for Circular Linked List

// Function to create a new node
Node* newNode(int coeff, int power) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->coeff = coeff;
    node->power = power;
    node->next = NULL;
    return node;
}

// Function to initialize the circular linked list with a header node
CLList* initList() {
    CLList* list = (CLList*)malloc(sizeof(CLList));
    list->header = newNode(0, 0); // Create header node
    list->header->next = list->header; // Point header to itself
    return list;
}

// Function to insert a term into the polynomial
void insTerm(CLList* list, int coeff, int power) {
    if (coeff == 0) return; // Skip zero coefficients

    Node* node = newNode(coeff, power);
    Node* curr = list->header;

    // Traverse to find the appropriate position
    while (curr->next != list->header && curr->next->power > power) {
        curr = curr->next;
    }

    // If the term with the same power exists, combine coefficients
    if (curr->next != list->header && curr->next->power == power) {
        curr->next->coeff += coeff;
        // If the coefficient becomes zero, remove the term
        if (curr->next->coeff == 0) {
            Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
    } else {
        node->next = curr->next;
        curr->next = node;
    }
}

// Function to display the polynomial
void showPoly(CLList* list) {
    Node* curr = list->header->next;
    if (curr == list->header) {
        printf("0\n"); // Empty polynomial
        return;
    }

    while (curr != list->header) {
        printf("%dx^%d ", curr->coeff, curr->power);
        curr = curr->next;
    }
    printf("\n");
}

// Function to subtract two polynomials
CLList* subPoly(CLList* poly1, CLList* poly2) {
    CLList* result = initList();
    Node *p1 = poly1->header->next, *p2 = poly2->header->next;

    // Traverse through both polynomials
    while (p1 != poly1->header || p2 != poly2->header) {
        if (p1 != poly1->header && (p2 == poly2->header || p1->power > p2->power)) {
            // Insert term from poly1
            insTerm(result, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p2 != poly2->header && (p1 == poly1->header || p1->power < p2->power)) {
            // Insert negated term from poly2
            insTerm(result, -p2->coeff, p2->power);
            p2 = p2->next;
        } else { // Powers are equal
            int coeff = p1->coeff - p2->coeff; // Subtract coefficients
            if (coeff != 0) {
                insTerm(result, coeff, p1->power); // Insert resulting term
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return result;
}

// Function to multiply two polynomials
CLList* mulPoly(CLList* poly1, CLList* poly2) {
    CLList* result = initList();
    Node* p1 = poly1->header->next;

    while (p1 != poly1->header) {
        Node* p2 = poly2->header->next;
        while (p2 != poly2->header) {
            insTerm(result, p1->coeff * p2->coeff, p1->power + p2->power);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return result;
}

// Function to free the circular linked list
void freeList(CLList* list) {
    Node* curr = list->header->next;
    Node* temp;
    while (curr != list->header) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(list->header);
    free(list);
}

// Function to input a polynomial from the user
void inputPoly(CLList* list) {
    int coeff, power;
    printf("Enter terms (coeff power), -1 -1 to end:\n");
    while (1) {
        scanf("%d %d", &coeff, &power);
        if (coeff == -1 && power == -1) break;
        insTerm(list, coeff, power);
    }
}

// Main function to execute the program
int main() {
    CLList *poly1 = initList(), *poly2 = initList(), *result;
    int choice;

    printf("Polynomial 1:\n");
    inputPoly(poly1);
    printf("Polynomial 2:\n");
    inputPoly(poly2);

    do {
        printf("\n1. Subtract\n2. Multiply\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                result = subPoly(poly1, poly2);
                printf("Result of Subtraction: ");
                showPoly(result);
                freeList(result);
                break;
            case 2:
                result = mulPoly(poly1, poly2);
                printf("Result of Multiplication: ");
                showPoly(result);
                freeList(result);
                break;
            case 3:
                printf("Polynomial 1: ");
                showPoly(poly1);
                printf("Polynomial 2: ");
                showPoly(poly2);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    freeList(poly1);
    freeList(poly2);
    return 0;
}
