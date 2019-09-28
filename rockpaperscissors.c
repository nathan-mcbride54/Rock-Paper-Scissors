//
// ======================
// Nathan Mcbride 0615415
// Rock Paper Scissors!
// COIS-3320 Lab 1
// ======================
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>``
#include <ctype.h>
#include <time.h>

#define infinate 1

char GetUserInput()
{
  char Prompt()
  {
    char input;
    printf("Enter your Guess -> ");
    scanf("%c", &input);
    getchar(); // Grab the extra character entered
    return toupper(input);
  }

  while(infinate)
  {
    char input = Prompt();
    if(input == 'R' || input == 'P' || input == 'S' || input == 'Q') { return input; }
    else { printf("Invalid Input\n"); }
  }
}

char GetComputerChoice()
{
  switch((rand() % 3))
  {
    case 0 : return 'P'; break;
    case 1 : return 'R'; break;
    case 2 : return 'S'; break;
  }
}

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
  // Included to seed radom number generation at runtime
  srand((time(NULL)));

  while(infinate)
  {

    system("clear");
    printf("╦═╗┌─┐┌─┐┬┌─  ╔═╗┌─┐┌─┐┌─┐┬─┐  ╔═╗┌─┐┬┌─┐┌─┐┌─┐┬─┐┌─┐\n");
    printf("╠╦╝│ ││  ├┴┐  ╠═╝├─┤├─┘├┤ ├┬┘  ╚═╗│  │└─┐└─┐│ │├┬┘└─┐\n");
    printf("╩╚═└─┘└─┘┴ ┴  ╩  ┴ ┴┴  └─┘┴└─  ╚═╝└─┘┴└─┘└─┘└─┘┴└─└─┘\n");
    printf("=====================================================\n");
    printf("Enter R for Rock, P for Paper, S for Scissors, Q to Quit\n\n");

    char user_choice = GetUserInput();
    if(user_choice == 'Q') { return; }
    printf("your choice: %c \n", user_choice);

    char computer_choice = GetComputerChoice();
    printf("computer choice: %c \n", computer_choice);

    switch(FindWinner(user_choice, computer_choice))
    {
      case -1 :
      printf("The Computer wins!\n\n");
      break;

      case 0 :
      printf("Match tied!\n\n");
      break;

      case 1 :
      printf("You win!\n\n");
      break;
    }

    sleep(2);
  }
}
