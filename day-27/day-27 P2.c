#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee();
void displayAllEmployees();
void searchEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nDatabase full! Cannot add more employees.\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == emp.id) {
            printf("\nError: Employee ID %d already exists!\n", emp.id);
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);

    printf("Enter Designation: ");
    scanf(" %[^\n]s", emp.designation);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    employees[employeeCount] = emp;
    employeeCount++;

    printf("\nEmployee added successfully!\n");
}

void displayAllEmployees() {
    if (employeeCount == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-25s %-20s $%-9.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
}

void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == searchId) {
            printf("\n--- Employee Found ---\n");
            printf("ID:          %d\n", employees[i].id);
            printf("Name:        %s\n", employees[i].name);
            printf("Designation: %s\n", employees[i].designation);
            printf("Salary:      $%.2f\n", employees[i].salary);
            return;
        }
    }

    printf("\nEmployee with ID %d not found.\n", searchId);
}
