 #include<stdio.h>
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
            
        }
        
        system("cls");
        printf("The position in coordinate is (%d, %d)\n", x, y);
        
        if(x==20||y==20||x==-20||y==-20)
        {
        	printf("collision\n");
        	break;
	}
    
    }
}