#include <conio.h>
#include <windows.h>
#include <stdio.h>

int x = 1, y = 1;

int main()
{
    char key;
    int n = 30, i, j;

    while (1)
    {
        system("cls");

        // Draw top wall
        for (i = 0; i < n; i++)
            printf("_");
        printf("\n");

        // Draw side walls
        for (i = 0; i < n - 2; i++)
        {
            printf("|");
            for (j = 0; j < n - 2; j++)
                printf(" ");
            printf("|\n");
        }

        // Draw bottom wall
        for (i = 0; i < n; i++)
            printf("_");

        // Input
        if (_kbhit())
        {
            key = _getch();

            if (key == 'w' || key == 'W') y--;
            if (key == 's' || key == 'S') y++;
            if (key == 'a' || key == 'A') x--;
            if (key == 'd' || key == 'D') x++;
        }

        printf("\nSnake head position: (%d, %d)", x, y);

        // ? ALL wall collision check
        if (x == 0 || x == n - 1 || y == 0 || y == n - 1)
        {
            printf("\nGAME OVER - Hit the wall!");
            break;
        }

        Sleep(100);
    }

    return 0;
}
