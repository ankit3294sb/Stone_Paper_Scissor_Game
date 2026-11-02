#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showChoice(int choice)
{
    switch (choice)
    {
        case 1:
            printf("Stone");
            break;
        case 2:
            printf("Paper");
            break;
        case 3:
            printf("Scissors");
            break;
    }
}

void showHandSign(int choice)
{
    switch (choice)
    {
        case 1: 
            printf("    _______\n");
            printf("---'   ____)\n");
            printf("      (_____)\n");
            printf("      (_____)\n");
            printf("      (____)\n");
            printf("---.__(___)\n");
            break;

        case 2:  
            printf("    _______\n");
            printf("---'   ____)____\n");
            printf("          ______)\n");
            printf("          _______)\n");
            printf("         _______)\n");
            printf("---.__________)\n");
            break;

        case 3:  
            printf("    _______\n");
            printf("---'   ____)____\n");
            printf("          ______)\n");
            printf("       __________)\n");
            printf("      (____)\n");
            printf("---.__(___)\n");
            break;
    }
}


int findWinner(int human, int computer)
{
    if (human == computer)
        return 0;

    if ((human == 1 && computer == 3) ||
        (human == 2 && computer == 1) ||
        (human == 3 && computer == 2))
        return 1;

    return 2;
}

int main()
{
    char humanName[30];                 
    char computerName[30] = "Jarvis";  
    int round, humanChoice, computerChoice, result;
    int humanScore = 0, computerScore = 0;

    srand(time(0));   

    printf("=====================================\n");
    printf("    STONE  PAPER  SCISSORS GAME\n");
    printf("=====================================\n");

   
    printf("Enter your name : ");
    scanf("%s", humanName);

    printf("\nPlayer 1 : %s\n", humanName);
    printf("Player 2  : %s\n", computerName);
    printf("\nThe game has 5 rounds.\n");
    printf("1 = Stone, 2 = Paper, 3 = Scissors\n");

    for (round = 1; round <= 5; round++)
    {
        printf("\n--- Round %d ---\n", round);

        do
        {
            printf("%s, enter your choice (1/2/3): ", humanName);
            scanf("%d", &humanChoice);

            if (humanChoice < 1 || humanChoice > 3)
                printf("Wrong choice! Please enter 1, 2 or 3.\n");

        } while (humanChoice < 1 || humanChoice > 3);

       
        computerChoice = rand() % 3 + 1;

        printf("\n%s chose: ", humanName);
        showChoice(humanChoice);
        printf("\n");
        showHandSign(humanChoice);

        printf("\n%s chose: ", computerName);
        showChoice(computerChoice);
        printf("\n");
        showHandSign(computerChoice);

        result = findWinner(humanChoice, computerChoice);

        if (result == 0)
        {
            printf("\nResult: It is a draw!\n");
        }
        else if (result == 1)
        {
            printf("\nResult: %s wins this round!\n", humanName);
            humanScore++;
        }
        else
        {
            printf("\nResult: %s wins this round!\n", computerName);
            computerScore++;
        }

        printf("Score -> %s: %d | %s: %d\n", humanName, humanScore, computerName, computerScore);
    }

    printf("\n=====================================\n");
    printf("            FINAL RESULT\n");
    printf("=====================================\n");
    printf("%s: %d\n%s: %d\n", humanName, humanScore, computerName, computerScore);

    if (humanScore > computerScore)
        printf("Congratulations %s, you won the game!\n", humanName);
    else if (computerScore > humanScore)
        printf("%s (computer) won the game. Better luck next time, %s!\n", computerName, humanName);
    else
        printf("The game is a draw!\n");

    return 0;
}