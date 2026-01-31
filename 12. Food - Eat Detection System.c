#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

#define n 20
#define max 100

int snakex[max], snakey[max];
int foodx, foody;
int length = 3, score = 0;

int main()
{
    int i, j;
    char key, dir = 'D';   // default direction

    // Initial snake position
    snakex[0] = 5; snakey[0] = 5;   // head
    snakex[1] = 5; snakey[1] = 4;   // body
    snakex[2] = 5; snakey[2] = 3;   // tail

    // Food logic
    srand(time(0));
    foodx = rand() % (n - 2) + 1;
    foody = rand() % (n - 2) + 1;

    while (1)
    {
        system("cls");

        // BORDER
        for (i = 0; i < n; i++) printf("_");
        printf("\n");

        for (i = 0; i < n - 2; i++)
        {
            printf("|");
            for (j = 0; j < n - 2; j++) printf(" ");
            printf("|\n");
        }

        for (i = 0; i < n; i++) printf("_");
        printf("\n");

        // INPUT
        if (_kbhit())
        {
            key = _getch();

            if ((key == 'w' || key == 'W') && dir != 'S') dir = 'W';
            if ((key == 's' || key == 'S') && dir != 'W') dir = 'S';
            if ((key == 'a' || key == 'A') && dir != 'D') dir = 'A';
            if ((key == 'd' || key == 'D') && dir != 'A') dir = 'D';
        }

        // SHIFT BODY
        for (i = length - 1; i > 0; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];
        }

        // MOVE HEAD
        if (dir == 'W') snakey[0]--;
        if (dir == 'S') snakey[0]++;
        if (dir == 'A') snakex[0]--;
        if (dir == 'D') snakex[0]++;

        // WALL HIT
        if (snakex[0] <= 0 || snakex[0] >= n - 1 ||
            snakey[0] <= 0 || snakey[0] >= n - 1)
        {
            printf("\nGAME OVER! YOU HIT THE WALL\n");
            break;
        }

        // FOOD EAT
        if (snakex[0] == foodx && snakey[0] == foody)
        {
            length++;
            score++;

            // new tail stays at last position
            snakex[length - 1] = snakex[length - 2];
            snakey[length - 1] = snakey[length - 2];

            foodx = rand() % (n - 2) + 1;
            foody = rand() % (n - 2) + 1;
        }

        // OUTPUT (PROJECT 11 STYLE)
        printf("\nSnake length : %d", length);
        printf("\nScore        : %d",score);

        printf("Head : (%d , %d)\n", snakex[0], snakey[0]);

        for (i = 1; i < length - 1; i++)
        {
            printf("Body %d : (%d , %d)\n", i, snakex[i], snakey[i]);
        }

        printf("Tail : (%d , %d)\n", snakex[length - 1], snakey[length - 1]);

        Sleep(200);
    }

    return 0;
}