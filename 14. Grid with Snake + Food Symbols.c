#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define n 20
#define max 100

int snakex[max], snakey[max];
int foodx , foody;
int x = 0, y = 0;
int length = 3, score = 0;
int main ()
{
    int i, j;
    char key, dir = 'D';

    // Initial snake
    snakex[0] = 5; snakey[0] = 5; // Head
    snakex[1] = 5; snakey[1] = 4; // Body
    snakex[2] = 5; snakey[2] = 3; // Tail

    srand(time(0));
    foodx = rand() % (n - 2) + 1;
    foody = rand() % (n - 2) + 1;

    while(1)
    {
        system("cls");
        for (y = 0; y < n; y++)
        {
            for (x = 0; x < n; x++)
            {
                int printed = 0;
                // WALL
                if (y == 0 || y == n-1 || x == 0 || x == n-1)
                {
                    printf("#");
                    continue;
                }
                // HEAD
                if (x == snakex[0] && y == snakey[0])
                {
                    printf("@");
                    printed = 1;
                }
                else
                {
                    // BODY + TAIL (loop!)
                    for (i = 1; i < length; i++)
                    {
                        if (x == snakex[i] && y == snakey[i])
                        {
                            printf("O");
                            printed = 1;
                            break;
                        }
                	}
                    // FOOD
                    if (!printed && x == foodx && y == foody)
                    {
                        printf("*");
                        printed = 1;
                    }
                    // EMPTY
                    if (!printed)
                        printf(" ");
                }
            }
            printf("\n");
        }

        if(_kbhit())
        {
            key = _getch();

            if((key == 'W'||key == 'w') && dir != 'S') dir = 'W';
            if((key == 'S'||key == 's') && dir != 'W') dir = 'S';
            if((key == 'A'||key == 'a') && dir != 'D') dir = 'A';
            if((key == 'D'||key == 'd') && dir != 'A') dir = 'D';
        }

        // change the position
        for(i = length - 1; i > 0; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];
        }

        // Move Head
        if(dir == 'W') snakey[0]--;
        if(dir == 'S') snakey[0]++;
        if(dir == 'A') snakex[0]--;
        if(dir == 'D') snakex[0]++;

        //If hit the wall
        if(snakex[0] <= 0 || snakex[0] >= n-1 ||
           snakey[0] <= 0 || snakey[0] >= n-1)
        {
            printf("\nGAME OVER! YOU HIT THE WALL\n");
            break;
        }

        //Food eat 
        if(snakex[0] == foodx && snakey[0] == foody)
        {
            score++;
            length++;

            // Add new tail
            snakex[length - 1] = snakex[length - 2];
            snakey[length - 1] = snakey[length - 2];

            foodx = rand() % (n - 2) + 1;
            foody = rand() % (n - 2) + 1;
        }

        printf("SCORE : %d  LENGTH : %d\n", score, length);
        Sleep(200);
    }
}