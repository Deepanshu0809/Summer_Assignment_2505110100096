#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nError: Maximum student limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[studentCount].rollNo);
    
    getchar(); 

    printf("Enter Name: ");
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);

    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &students[studentCount].marks);

    studentCount++;
    printf("Student record added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    printf("%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-30s %-10.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int roll;
    int found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            printf("\nRecord Found!\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name:        %s\n", students[i].name);
            printf("Marks:       %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}

int main() {
    int choice;

    do {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
