#include <stdio.h>
#include <stdlib.h>

char GetUserInput() {
    printf("Enter your Guess -> ");
    char input = 'R';
    // Input checking?

    return input;
}

char GetComputerChoice() {
    int i = rand() % 3;
    char computer_choice;
    // Case statement to convert to char from int
    return computer_choice;
}

int FindWinner(char user_choice, char computer_choice) {
    // Case statement
    return 1;
}

void main() {
    char user_choice = GetUserInput();
    while(user_choice =! 'Q') {
        printf("Enter R for Rock, P for Paper, S for Scissors, Q for Quit");

        user_choice = GetUserInput();
        printf(user_choice);
        char computer_choice = GetComputerChoice();
        int winner = FindWinner(user_choice, computer_choice);

        // Case statement for results
    }
}
