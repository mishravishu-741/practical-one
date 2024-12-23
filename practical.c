#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the array

void insert(int arr[], int *n, int pos, int value) {
    if (*n >= MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }
    
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }
    
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Current size of the array

    int choice, pos, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert (0-based index): ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &n, pos, value);
                break;

            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;

            case 3:
                printf("Array elements: ");
                display(arr, n);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
