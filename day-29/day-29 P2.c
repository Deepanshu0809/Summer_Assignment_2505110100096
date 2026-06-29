#include <stdio.h>
#include <stdlib.h>

int arr[100];
int size = 0;

void create() {
    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void display() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert() {
    if (size >= 100) {
        printf("Array is full\n");
        return;
    }
    int pos, val;
    printf("Enter position (0 to %d): ", size);
    scanf("%d", &pos);
    if (pos < 0 || pos > size) {
        printf("Invalid position\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size++;
    printf("Element inserted\n");
}

void delete() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    int pos;
    printf("Enter position to delete (0 to %d): ", size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
