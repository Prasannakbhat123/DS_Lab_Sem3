#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;    // Array to store heap elements
    int size;    // Current number of elements
    int capacity;// Maximum number of elements
} MinHeap;

// Function prototypes
MinHeap* createHeap(int capacity);
void insert(MinHeap* heap, int value);
int deleteMin(MinHeap* heap);
void heapify(MinHeap* heap, int index);
void printHeap(MinHeap* heap);
void freeHeap(MinHeap* heap);

int main() {
    int capacity = 10; // Initial capacity of the heap
    MinHeap* heap = createHeap(capacity);

    int choice, value;

    while (1) {
        printf("\nPriority Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete Minimum\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(heap, value);
                printf("Inserted %d into the priority queue\n", value);
                break;

            case 2:
                if (heap->size == 0) {
                    printf("Priority queue is empty.\n");
                } else {
                    value = deleteMin(heap);
                    printf("Deleted minimum value %d from the priority queue\n", value);
                }
                break;

            case 3:
                printHeap(heap);
                break;

            case 4:
                printf("Exiting...\n");
                freeHeap(heap);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Create a new min-heap
MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Insert a value into the heap
void insert(MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        // Resize the array if needed
        heap->capacity *= 2;
        heap->arr = (int*)realloc(heap->arr, heap->capacity * sizeof(int));
    }
    heap->arr[heap->size] = value;
    int index = heap->size;
    heap->size++;

    // Fix the heap property
    while (index != 0 && heap->arr[index] < heap->arr[(index - 1) / 2]) {
        // Swap with parent
        int parentIndex = (index - 1) / 2;
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[parentIndex];
        heap->arr[parentIndex] = temp;

        // Move up the index
        index = parentIndex;
    }
}

// Delete and return the minimum value from the heap
int deleteMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty.\n");
        return -1; // Indicate error
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // Store the minimum value and remove it
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Fix the heap property
    heapify(heap, 0);

    return root;
}

// Maintain the heap property starting from index
void heapify(MinHeap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        // Swap and continue heapifying
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        heapify(heap, smallest);
    }
}

// Print the current state of the heap
void printHeap(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Priority queue is empty.\n");
        return;
    }
    printf("Priority queue elements:\n");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Free the memory allocated for the heap
void freeHeap(MinHeap* heap) {
    free(heap->arr);
    free(heap);
}
