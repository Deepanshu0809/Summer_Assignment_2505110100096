#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100


struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
};

int main() {
    struct Book library[MAX_BOOKS];
    int count = 0;
    int choice, searchId, found;

    while (1) {
      
        printf("\n=== Library Management System ===\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Total Books Count\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                if (count < MAX_BOOKS) {
                    printf("\nEnter Book ID: ");
                    scanf("%d", &library[count].id);
                    
                    printf("Enter Book Title: ");
                
                    scanf(" %[^\n]s", library[count].title); 
                    
                    printf("Enter Author Name: ");
                    scanf(" %[^\n]s", library[count].author);
                    
                    printf("Enter Book Price: ");
                    scanf("%f", &library[count].price);
                    
                    count++;
                    printf("Book added successfully!\n");
                } else {
                    printf("\nLibrary is full! Cannot add more books.\n");
                }
                break;

            case 2:
                
                if (count == 0) {
                    printf("\nNo books available in the library.\n");
                } else {
                    printf("\n%-10s %-30s %-20s %-10s\n", "Book ID", "Title", "Author", "Price");
                    printf("-------------------------------------------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        printf("%-10d %-30s %-20s %-10.2f\n", 
                               library[i].id, library[i].title, library[i].author, library[i].price);
                    }
                }
                break;

            case 3:
             
                if (count == 0) {
                    printf("\nLibrary is empty. Nothing to search.\n");
                } else {
                    printf("\nEnter Book ID to search: ");
                    scanf("%d", &searchId);
                    found = 0;
                    
                    for (int i = 0; i < count; i++) {
                        if (library[i].id == searchId) {
                            printf("\nBook Found!\n");
                            printf("ID: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\n", 
                                   library[i].id, library[i].title, library[i].author, library[i].price);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nBook with ID %d not found.\n", searchId);
                    }
                }
                break;

            case 4:
               
                printf("\nTotal number of books in the library: %d\n", count);
                break;

            case 5:
                
                printf("\nExiting the system. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}
