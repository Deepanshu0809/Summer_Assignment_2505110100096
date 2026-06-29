#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} BankAccount;

BankAccount bank[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();

int main() {
    int choice;

    do {
        printf("\n=== BANK ACCOUNT MANAGEMENT SYSTEM ===\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("\nThank you for banking with us!\n");
                break;
            default:
                printf("\nInvalid selection. Please choose options 1 through 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nSystem error: Maximum account limits reached.\n");
        return;
    }

    printf("\nEnter a unique Account Number: ");
    scanf("%d", &bank[totalAccounts].accountNumber);
    
    getchar(); 
    printf("Enter Account Holder Name: ");
    fgets(bank[totalAccounts].name, sizeof(bank[totalAccounts].name), stdin);
    bank[totalAccounts].name[strcspn(bank[totalAccounts].name, "\n")] = '\0'; 
    printf("Enter Initial Deposit Amount: ");
    scanf("%lf", &bank[totalAccounts].balance);

    printf("\nSuccess! Account created for %s.\n", bank[totalAccounts].name);
    totalAccounts++;
}

void depositMoney() {
    int accNum, found = 0;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            found = 1;
            printf("Enter Amount to Deposit: ");
            scanf("%lf", &amount);

            if (amount <= 0) {
                printf("Error: Deposit value must be positive.\n");
            } else {
                bank[i].balance += amount;
                printf("Successfully added. Updated Balance: $%.2f\n", bank[i].balance);
            }
            break;
        }
    }
    if (!found) {
        printf("Account number not registered.\n");
    }
}

void withdrawMoney() {
    int accNum, found = 0;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            found = 1;
            printf("Enter Amount to Withdraw: ");
            scanf("%lf", &amount);

            if (amount <= 0) {
                printf("Error: Withdrawal value must be positive.\n");
            } else if (amount > bank[i].balance) {
                printf("Transaction Declined: Insufficient balance. Available: $%.2f\n", bank[i].balance);
            } else {
                bank[i].balance -= amount;
                printf("Successfully debited. Remaining Balance: $%.2f\n", bank[i].balance);
            }
            break;
        }
    }
    if (!found) {
        printf("Account number not registered.\n");
    }
}

void checkBalance() {
    int accNum, found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            found = 1;
            printf("\n--- Account Status ---\n");
            printf("Account Number: %d\n", bank[i].accountNumber);
            printf("Holder Name: %s\n", bank[i].name);
            printf("Current Balance: $%.2f\n", bank[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Account number not registered.\n");
    }
}
