#include <stdio.h>
#include <ctype.h>
typedef struct {
    char questionText[150];
    char options[4][50];
    char correctOption; 
} QuizQuestion;

int main() {
    QuizQuestion quiz[3] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Python", "B. C Language", "C. Java", "D. C++"},
            'B'
        },
        {
            "What is the only even prime number?",
            {"A. 2", "B. 4", "C. 6", "D. 8"},
            'A'
        },
        {
            "Which planet is known as the Red Planet?",
            {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"},
            'B'
        }
    };

    int totalQuestions = 3;
    int score = 0;
    char userGuess;

    printf("=========================================\n");
    printf("        WELCOME TO THE QUIZ GAME!        \n");
    printf("=========================================\n\n");

    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].questionText);
        
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        printf("Enter your answer (A, B, C, or D): ");
        scanf(" %c", &userGuess); 
        
        userGuess = toupper(userGuess);

        if (userGuess == quiz[i].correctOption) {
            printf("✅ Correct!\n\n");
            score++;
        } else {
            printf("❌ Wrong! The correct answer was %c.\n\n", quiz[i].correctOption);
        }
    }

    printf("=========================================\n");
    printf("               QUIZ OVER!                \n");
    printf("=========================================\n");
    printf("Your Final Score: %d out of %d\n", score, totalQuestions);
    
    float percentage = ((float)score / totalQuestions) * 100;
    printf("Percentage: %.2f%%\n", percentage);
    printf("=========================================\n");

    return 0;
}
