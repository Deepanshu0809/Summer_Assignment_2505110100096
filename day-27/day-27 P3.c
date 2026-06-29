#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50

struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float allowance;
    float deduction;
    float net_salary;
};

void addEmployee(struct Employee emp[], int *count);
void displayEmployees(struct Employee emp[], int count);
void calculateSalary(struct Employee emp[], int count);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;

    while (1) {
      
        printf("\n=================================");
        printf("\n     SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Records");
        printf("\n2. Display All Employee Slips");
        printf("\n3. Calculate & Update Salary Components");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &employee_count);
                break;
            case 2:
                displayEmployees(employees, employee_count);
                break;
            case 3:
                calculateSalary(employees, employee_count);
                break;
            case 4:
                printf("\nExiting system. Thank you!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}


void addEmployee(struct Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nSystem database is full!\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp[*count].id);

    getchar(); 
    printf("Enter Employee Name: ");
    fgets(emp[*count].name, sizeof(emp[*count].name), stdin);
    emp[*count].name[strcspn(emp[*count].name, "\n")] = 0; 

    printf("Enter Basic Salary: ");
    scanf("%f", &emp[*count].basic_salary);

    emp[*count].allowance = 0;
    emp[*count].deduction = 0;
    emp[*count].net_salary = emp[*count].basic_salary;

    (*count)++;
    printf("\nEmployee added successfully!\n");
}

void calculateSalary(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records found to calculate!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
    
        emp[i].allowance = emp[i].basic_salary * 0.20;
        emp[i].deduction = emp[i].basic_salary * 0.10;
        emp[i].net_salary = emp[i].basic_salary + emp[i].allowance - emp[i].deduction;
    }
    printf("\nSalaries calculated and updated for all employees!\n");
}

void displayEmployees(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records to display!\n");
        return;
    }

    printf("\n%-5s %-20s %-12s %-10s %-10s %-12s", "ID", "Name", "Basic", "Allow.", "Deduct.", "Net Salary");
    printf("\n------------------------------------------------------------------------");
    for (int i = 0; i < count; i++) {
        printf("\n%-5d %-20s %-12.2f %-10.2f %-10.2f %-12.2f", 
               emp[i].id, emp[i].name, emp[i].basic_salary, 
               emp[i].allowance, emp[i].deduction, emp[i].net_salary);
    }
    printf("\n------------------------------------------------------------------------\n");
}
