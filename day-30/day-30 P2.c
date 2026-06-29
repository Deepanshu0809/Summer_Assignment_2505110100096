#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

int main() {
    struct Book library[100];
    int count = 0;
    int choice;
    int searchId;
    int found;

    while (1) {
        printf("\n--- MINI LIBRARY SYSTEM ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < 100) {
                    printf("Enter Book ID: ");
                    scanf("%d", &library[count].id);
                    getchar();
                    printf("Enter Book Title: ");
                    fgets(library[count].title, sizeof(library[count].title), stdin);
                    library[count].title[strcspn(library[count].title, "\n")] = 0;
                    printf("Enter Book Author: ");
                    fgets(library[count].author, sizeof(library[count].author), stdin);
                    library[count].author[strcspn(library[count].author, "\n")] = 0;
                    count++;
                    printf("Book added successfully!\n");
                } else {
                    printf("Library is full!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No books available in the library.\n");
                } else {
                    printf("\n--- Library Books ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("ID: %d | Title: %s | Author: %s\n", library[i].id, library[i].title, library[i].author);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("Library is empty.\n");
                } else {
                    printf("Enter Book ID to search: ");
                    scanf("%d", &searchId);
                    found = 0;
                    for (int i = 0; i < count; i++) {
                        if (library[i].id == searchId) {
                            printf("Book Found: ID: %d | Title: %s | Author: %s\n", library[i].id, library[i].title, library[i].author);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Book with ID %d not found.\n", searchId);
                    }
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
