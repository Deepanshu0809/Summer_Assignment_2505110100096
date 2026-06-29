#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contacts[MAX_CONTACTS];
int totalContacts = 0;

void addContact();
void viewContacts();
void searchContact();

int main() {
    int choice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

void addContact() {
    if (totalContacts >= MAX_CONTACTS) {
        printf("Error: Contact list is full!\n");
        return;
    }

    struct Contact newContact;

    printf("\nEnter Name: ");
    scanf(" %[^\n]", newContact.name);

    printf("Enter Phone Number: ");
    scanf(" %[^\n]", newContact.phone);

    printf("Enter Email Address: ");
    scanf(" %[^\n]", newContact.email);

    contacts[totalContacts] = newContact;
    totalContacts++;

    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (totalContacts == 0) {
        printf("\nNo contacts found. Your list is empty!\n");
        return;
    }

    printf("\n--- All Contacts ---\n");
    for (int i = 0; i < totalContacts; i++) {
        printf("%d. Name: %s | Phone: %s | Email: %s\n", 
               i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void searchContact() {
    if (totalContacts == 0) {
        printf("\nNo contacts available to search.\n");
        return;
    }

    char searchName[50];
    int found = 0;

    printf("\nEnter the name to search: ");
    scanf(" %[^\n]", searchName);

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < totalContacts; i++) {
    
        if (strstr(contacts[i].name, searchName) != NULL) {
            printf("Name: %s | Phone: %s | Email: %s\n", 
                   contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found matching '%s'.\n", searchName);
    }
}
