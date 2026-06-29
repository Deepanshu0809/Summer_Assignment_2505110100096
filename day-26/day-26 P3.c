#include <stdio.h>

int main() {
    
    int pin = 1234;
    int entered_pin;
    int attempts = 0;
    int choice;
    float balance = 1000.00; 
    float amount;

    printf("=== WELCOME TO THE ATM SIMULATION ===\n");

    while (attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == pin) {
            printf("Access Granted!\n");
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Remaining attempts: %d\n\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("Too many incorrect attempts. Your card is blocked.\n");
        return 0;
    }

    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                printf("\nYour current balance is: $%.2f\n", balance);
                break;

            case 2:
               
                printf("\nEnter amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, balance);
                } else {
                    printf("Invalid amount entered.\n");
                }
                break;

            case 3:
               
                printf("\nEnter amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Insufficient balance! Operation failed.\n");
                } else if (amount <= 0) {
                    printf("Invalid amount entered.\n");
                } else {
                    balance -= amount;
                    printf("Please collect your cash.\n");
                    printf("Successfully withdrew $%.2f. New balance: $%.2f\n", amount, balance);
                }
                break;

            case 4:
                printf("\nThank you for using our ATM services. Goodbye!\n");
                break;

            default:
              
                printf("\nInvalid selection. Please choose an option between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
