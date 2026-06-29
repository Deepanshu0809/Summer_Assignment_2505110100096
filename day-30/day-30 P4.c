#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

char names[MAX_STUDENTS][NAME_LENGTH];
int rollNumbers[MAX_STUDENTS];
float marks[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nDatabase full!\n");
        return;
    }
    printf("\nEnter Name: ");
    scanf(" %[^\n]s", names[studentCount]);
    printf("Enter Roll Number: ");
    scanf("%d", &rollNumbers[studentCount]);
    printf("Enter Marks: ");
    scanf("%f", &marks[studentCount]);
    studentCount++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", rollNumbers[i], names[i], marks[i]);
    }
}

void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo data to search.\n");
        return;
    }
    char searchName[NAME_LENGTH];
    int found = 0;
    printf("\nEnter student name to search: ");
    scanf(" %[^\n]s", searchName);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("\nRecord Found:\nRoll: %d | Name: %s | Marks: %.2f\n", rollNumbers[i], names[i], marks[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n*** Mini Student Management System ***\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Name\n");
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
                return 0;
            default:
                printf("\nInvalid selection. Try again.\n");
        }
    }
    return 0;
}
