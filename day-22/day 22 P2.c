#include <stdio.h>
#include <ctype.h> 

int main() {
    char sentence[1000];
    int count = 0;
    int in_word = 0; 

    printf("Enter a sentence: ");
    
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {

        if (isspace(sentence[i])) {
            in_word = 0; // We hit a space, so we are no longer inside a word
        } 
        // If it is not a space and we weren't already in a word
        else if (in_word == 0) {
            in_word = 1; // Mark that we have entered a new word
            count++;     // Increment the word counter
        }
    }

    printf("Total number of words: %d\n", count);

    return 0;
}