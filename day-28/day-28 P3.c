#include <stdio.h>
#include <stdlib.h>

#define TOTAL_SEATS 10

int seats[TOTAL_SEATS] = {0}; 

void displaySeats();
void bookTicket();
void cancelTicket();

int main() {
    int choice;

    while (1) {
        printf("\n=============================\n");
        printf("    TICKET BOOKING SYSTEM    \n");
        printf("=============================\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                printf("\nThank you for using the Ticket Booking System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose a number between 1 and 4.\n");
        }
    }
    return 0;
}

void displaySeats() {
    printf("\n----- SEATING CHART -----\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %d: ", i + 1);
        if (seats[i] == 0) {
            printf("[ Available ]\n");
        } else {
            printf("[   BOOKED  ]\n");
        }
    }
    printf("-------------------------\n");
}

void bookTicket() {
    int seatNumber;
    printf("\nEnter the seat number you want to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid seat number! Please select between 1 and %d.\n", TOTAL_SEATS);
        return;
    }

    if (seats[seatNumber - 1] == 0) {
        seats[seatNumber - 1] = 1; 
        printf("Success! Seat %d has been booked for you.\n", seatNumber);
    } else {
        printf("Sorry, Seat %d is already taken!\n", seatNumber);
    }
}

void cancelTicket() {
    int seatNumber;
    printf("\nEnter the seat number you want to cancel (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid seat number! Please select between 1 and %d.\n", TOTAL_SEATS);
        return;
    }

    if (seats[seatNumber - 1] == 1) {
        seats[seatNumber - 1] = 0; 
        printf("Success! Your booking for Seat %d has been canceled.\n", seatNumber);
    } else {
        printf("Cancellation failed! Seat %d is not currently booked.\n", seatNumber);
    }
}
