#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n1. Add Student\n2. Display All\n3. Search by Roll\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count < 100) {
                printf("Enter Roll Number: ");
                scanf("%d", &s[count].roll);
                printf("Enter Name: ");
                scanf("%s", s[count].name);
                printf("Enter Marks: ");
                scanf("%f", &s[count].marks);
                count++;
            } else {
                printf("Database full!\n");
            }
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("No records found.\n");
            } else {
                printf("\n--- Student Records ---\n");
                for (int i = 0; i < count; i++) {
                    printf("Roll: %d | Name: %s | Marks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
                }
            }
        } 
        else if (choice == 3) {
            int searchRoll, found = 0;
            printf("Enter Roll Number to search: ");
            scanf("%d", &searchRoll);
            for (int i = 0; i < count; i++) {
                if (s[i].roll == searchRoll) {
                    printf("Found! Name: %s, Marks: %.2f\n", s[i].name, s[i].marks);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Record not found.\n");
            }
        } 
        else if (choice == 4) {
            break;
        } 
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
