#include <stdio.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main()
{
    int score = 0;
    char player1, player2;

    while (scanf("%c %c\n", &player1, &player2) != EOF)
    {
        player1 -= 'A' - 1;
        player2 -= 'X' - 1;

        // 1 - rock
        // 2 - paper
        // 3 - scissors

        // draw
        if (player1 == player2) score += 3;

        if (player1 == ROCK && player2 == PAPER) score += 6;
        if (player1 == PAPER && player2 == SCISSORS) score += 6;
        if (player1 == SCISSORS && player2 == ROCK) score += 6;

        score += player2;
    }

    printf("%d\n", score);
}