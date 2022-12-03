#include <stdio.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

#define LOSE 1
#define DRAW 2
#define WIN 3

int main()
{
    int score = 0;
    char player1, verdict;

    while (scanf("%c %c\n", &player1, &verdict) != EOF)
    {
        char player2;
        player1 -= 'A' - 1;
        verdict -= 'X' - 1;

        if (verdict == LOSE)
        {
            if (player1 == ROCK) player2 = SCISSORS;
            if (player1 == PAPER) player2 = ROCK;
            if (player1 == SCISSORS) player2 = PAPER;
        }
        else if (verdict == DRAW)
        {
            score += 3;
            player2 = player1;
        }
        else if (verdict == WIN)
        {
            if (player1 == ROCK) player2 = PAPER;
            if (player1 == PAPER) player2 = SCISSORS;
            if (player1 == SCISSORS) player2 = ROCK;
            score += 6;
        }

        score += player2;
    }

    printf("%d\n", score);
}