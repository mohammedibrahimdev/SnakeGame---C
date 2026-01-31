#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define MAX 100   // max movements stored

int main()
{
    int x = 5, y = 5;          // head position
    int posX[MAX], posY[MAX]; // movement history
    int steps = 0;             // number of moves stored
    char key;

    printf("Movement Replay System (Project 13)\n");
    printf("Use W A S D to move, Q to quit\n");
    Sleep(1500);

    while (1)
    {
        system("cls");

        // Store current position
        posX[steps] = x;
        posY[steps] = y;
        steps++;

        printf("Current Head Position: (%d, %d)\n", x, y);
        printf("Step: %d\n", steps);
        printf("Press Q to stop\n");

        if (_kbhit())
        {
            key = _getch();

            if (key == 'q' || key == 'Q')
                break;

            if (key == 'w' || key == 'W') y--;
            if (key == 's' || key == 'S') y++;
            if (key == 'a' || key == 'A') x--;
            if (key == 'd' || key == 'D') x++;
        }

        Sleep(200);

        if (steps >= MAX)
            break;
    }

    // Replay movements
    system("cls");
    printf("MOVEMENT REPLAY\n\n");

    for (int i = 0; i < steps; i++)
    {
        printf("Step %d : (%d, %d)\n", i + 1, posX[i], posY[i]);
        Sleep(200);
    }

    return 0;
}