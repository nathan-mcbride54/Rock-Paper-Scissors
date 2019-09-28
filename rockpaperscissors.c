#include <stdio.h>
#include <stdlib.h>

char GetUserInput()
{
  char input;
  printf("\nEnter your Guess -> ");
  scanf("%c", &input);
  // Input checking?
  return input;
}

char GetComputerChoice()
{
  char computer_choice;
  int r = rand() % 3;
  switch(r)
  {
    case 0 : computer_choice = 'P'; break;
    case 1 : computer_choice = 'R'; break;
    case 2 : computer_choice = 'S'; break;
  }
  return computer_choice;
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
    }
    break;

    case 'P' : switch(computer_choice)
    {
      case 'R' : return 1; break;
      case 'P' : return 0; break;
      case 'S' : return -1; break;
    }
    break;

    case 'S' : switch(computer_choice)
    {
      case 'R' : return -1; break;
      case 'P' : return 1; break;
      case 'S' : return 0; break;
    }
    break;
  }
}

void main()
{
  char user_choice;
  while(user_choice != 'Q')
  {
    printf("Enter R for Rock, P for Paper, S for Scissors, Q for Quit\n");

    user_choice = GetUserInput();
    printf("\nyour choice: ", &user_choice);
\
    char computer_choice = GetComputerChoice();
    printf("\ncomputer choice: ", &computer_choice);

    int winner = FindWinner(user_choice, computer_choice);

    switch(winner)
    {
      case -1 : printf("\nThe Computer wins!"); break;
      case 0 : printf("\nMatch tied!"); break;
      case 1 : printf("\nYou win!"); break;
    }
  }
}
