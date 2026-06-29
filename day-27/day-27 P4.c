#include <stdio.h>

int main() {
    char name[50];
    int roll_no;
    float math, science, english, history, computer;
    float total, percentage;
    char grade;

    printf("=== Marksheet Generation System ===\n");
    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin); 
    printf("Enter Roll Number: ");
    scanf("%d", &roll_no);
   
    printf("\nEnter marks for 5 subjects (out of 100):\n");
    printf("Mathematics: ");
    scanf("%f", &math);
    printf("Science: ");
    scanf("%f", &science);
    printf("English: ");
    scanf("%f", &english);
    printf("History: ");
    scanf("%f", &history);
    printf("Computer Science: ");
    scanf("%f", &computer);


    total = math + science + english + history + computer;
    percentage = (total / 500.0) * 100;

    if (percentage >= 90) {
        grade = 'A';
    } else if (percentage >= 75) {
        grade = 'B';
    } else if (percentage >= 50) {
        grade = 'C';
    } else if (percentage >= 35) {
        grade = 'D';
    } else {
        grade = 'F'; 
    }

    printf("\n========================================\n");
    printf("               MARKSHEET                \n");
    printf("========================================\n");
    printf("Student Name : %s", name);
    printf("Roll Number  : %d\n", roll_no);
    printf("----------------------------------------\n");
    printf("Subject           |  Marks Obtained\n");
    printf("----------------------------------------\n");
    printf("Mathematics       |  %.2f\n", math);
    printf("Science           |  %.2f\n", science);
    printf("English           |  %.2f\n", english);
    printf("History           |  %.2f\n", history);
    printf("Computer Science  |  %.2f\n", computer);
    printf("----------------------------------------\n");
    printf("Total Marks       |  %.2f / 500.00\n", total);
    printf("Percentage        |  %.2f%%\n", percentage);
    printf("Final Grade       |  %c\n", grade);
    printf("========================================\n");

    return 0;
}
