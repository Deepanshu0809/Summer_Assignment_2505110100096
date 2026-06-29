#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char position[50];
    float salary;
};

int main() {
    struct Employee emp[100];
    int count = 0;
    int choice;
    int searchId;
    int found;

    while (1) {
        printf("\n--- Employee Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                if (count >= 100) {
                    printf("System full!\n");
                    break;
                }
                printf("Enter ID: ");
                scanf("%d", &emp[count].id);
                getchar();
                printf("Enter Name: ");
                fgets(emp[count].name, 50, stdin);
                emp[count].name[strcspn(emp[count].name, "\n")] = 0;
                printf("Enter Position: ");
                fgets(emp[count].position, 50, stdin);
                emp[count].position[strcspn(emp[count].position, "\n")] = 0;
                printf("Enter Salary: ");
                scanf("%f", &emp[count].salary);
                count++;
                printf("Employee added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No employee records found.\n");
                    break;
                }
                printf("\n%-5s %-20s %-20s %-10s\n", "ID", "Name", "Position", "Salary");
                for (int i = 0; i < count; i++) {
                    printf("%-5d %-20s %-20s %-10.2f\n", emp[i].id, emp[i].name, emp[i].position, emp[i].salary);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("No employee records found.\n");
                    break;
                }
                printf("Enter ID to search: ");
                scanf("%d", &searchId);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (emp[i].id == searchId) {
                        printf("\nID: %d\nName: %s\nPosition: %s\nSalary: %.2f\n", emp[i].id, emp[i].name, emp[i].position, emp[i].salary);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Employee with ID %d not found.\n", searchId);
                }
                break;

            case 4:
                if (count == 0) {
                    printf("No employee records found.\n");
                    break;
                }
                printf("Enter ID to delete: ");
                scanf("%d", &searchId);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (emp[i].id == searchId) {
                        for (int j = i; j < count - 1; j++) {
                            emp[j] = emp[j + 1];
                        }
                        count--;
                        found = 1;
                        printf("Employee record deleted successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Employee with ID %d not found.\n", searchId);
                }
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
