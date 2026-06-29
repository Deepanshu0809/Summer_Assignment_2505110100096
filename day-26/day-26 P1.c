#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, attempts = 0;

    srand(time(NULL));

    secret_number = (rand() % 100) + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100. Try to guess it!\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > secret_number) {
            printf("Too high! Try again.\n\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != secret_number);

    return 0;
}
