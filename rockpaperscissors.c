// ======================
// Nathan Mcbride 0615415
// COIS-3320 Lab 1
// ======================
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

// This function is used to prompt the user for an input and ensure the input is valid.
char GetUserInput()
{
  // This method was created independent from error checking to improve modularity.
  char Prompt()
  {
    char input[100];
    printf("Enter your Guess -> ");
    scanf("%s", &input);
    return toupper(input[0]);
  }

  // Input errors are caught by matching to only the specific characters that are valid in this program.
  while(1)
  {
    char input = Prompt();
    if(input == 'R' || input == 'P' || input == 'S' || input == 'Q') { return input; }
    else { printf("Invalid Input\n"); }
  }
}

// This function generates a random number between 0-2 and returns a char representing the random choice.
char GetComputerChoice()
{
  switch((rand() % 3))
  {
    case 0 : return 'P'; break;
    case 1 : return 'R'; break;
    case 2 : return 'S'; break;
  }
}

// This function uses nested switch statements to define the logic of who wins the game.
int FindWinner(char user_choice, char computer_choice)
{
  switch(user_choice)
  {
    case 'R' : switch(computer_choice)
    {
      case 'R' : return 0; break;
      case 'P' : return -1; break;
      case 'S' : return 1; break;
    } break;

    case 'P' : switch(computer_choice)
    {
      case 'R' : return 1; break;
      case 'P' : return 0; break;
      case 'S' : return -1; break;
    } break;

    case 'S' : switch(computer_choice)
    {
      case 'R' : return -1; break;
      case 'P' : return 1; break;
      case 'S' : return 0; break;
    } break;
  }
}

void main()
{
  // Included to seed random number generation with time at NULL for rand() at runtime.
  srand((time(NULL)));

  int user_score = 0;
  int computer_score = 0;
  int round = 0;

  // Loop until user exits the program.
  while(1)
  {
    // Display the user interface of the game in the terminal.
    system("clear");
    printf("╦═╗┌─┐┌─┐┬┌─  ╔═╗┌─┐┌─┐┌─┐┬─┐  ╔═╗┌─┐┬┌─┐┌─┐┌─┐┬─┐┌─┐\n");
    printf("╠╦╝│ ││  ├┴┐  ╠═╝├─┤├─┘├┤ ├┬┘  ╚═╗│  │└─┐└─┐│ │├┬┘└─┐\n");
    printf("╩╚═└─┘└─┘┴ ┴  ╩  ┴ ┴┴  └─┘┴└─  ╚═╝└─┘┴└─┘└─┘└─┘┴└─└─┘\n");
    printf("=====================================================\n");
    printf("Enter R for Rock, P for Paper, S for Scissors, Q to Quit\n\n");
    printf("=======================================\n");
    printf("| ROUND: %i | USER: %i | COMPUTER: %i |\n", round, user_score, computer_score);
    printf("=======================================\n\n");

    // Call prompt to get user input for program, quit program if requested.
    char user_choice = GetUserInput();
    if(user_choice == 'Q') { return; }
    printf("your choice: %c \n", user_choice);

    // Generate random choice from computer.
    char computer_choice = GetComputerChoice();
    printf("computer choice: %c \n", computer_choice);

    // Call function to compare choices, then determine winner.
    switch(FindWinner(user_choice, computer_choice))
    {
      case -1 :
      printf("The Computer wins!\n\n");
      computer_score += 1;
      break;

      case 0 :
      printf("Match tied!\n\n");
      break;

      case 1 :
      printf("You win!\n\n");
      user_score += 1;
      break;
    }
    
    round += 1;

    // Pause program before ending loop and clearing screen.
    sleep(2);
  }
}
