ok s#include<stdio.h>
#include<windows.h>
#include<conio.h>

int x = 0 , y = 0 ;

int main ()
{
    char key;

    while (1)
    {
        if (_kbhit())
        {
            key = _getch();
            
            if(key == 'w' ||key == 'W') y++;
            if(key == 's' ||key == 'S') y--;
            if(key == 'a' ||key == 'A') x--;
            if(key == 'd' ||key == 'D') x++;
        

            if(key == -32 || key == 224)
            {
                key = _getch(); 

                if(key == 72) y++;
                if(key == 80) y--; 
                if(key == 75) x--; 
                if(key == 77) x++; 
            }
        }

        system("cls");
        printf("The position in coordinate is (%d, %d)", x, y);
    }
}
