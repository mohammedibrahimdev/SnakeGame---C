#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
int x = 1,y = 1;
int foodx = 0 , foody = 0;
int main ()
{
	int n =  20, i,j,p = 0,s = 0;
	while(1)
	{ 
		system("cls");
		for(i = 0;i<n;++i)
		printf("_");
		printf("\n");
		
		for(i = 0;i< n - 2;++i)
		{
			for(j = 1;j<= 1;++j)
			printf("|");
			for(j = 0;j<n - 2;++j)
			printf(" ");
			for(j = 1;j<= 1;++j)
			printf("|");
			
			printf("\n");
		}
		for(i = 0;i<n;++i)
		printf("_");
		
		char key;
		static char dir = 'R';   // current direction

			if (_kbhit())
			{
			    key = _getch();

    // change direction only if NOT opposite
  					if ((key == 'W' || key == 'w') && dir != 'S') dir = 'W';
 					if ((key == 'S' || key == 's') && dir != 'W') dir = 'S';
    				if ((key == 'A' || key == 'a') && dir != 'D') dir = 'A';
    				if ((key == 'D' || key == 'd') && dir != 'A') dir = 'D';
			}

				// move based on direction
				{
					if (dir == 'W') y++;
					if (dir == 'S') y--;
					if (dir == 'A') x--;
					if (dir == 'D') x++;
					Sleep(20);
				}
		printf("\nthe location of the snake : (%d, %d)\n", x,y);
			if (x <= 0 || x >= n-1 || y <= 0 || y >= n-1)
  			  {
   			     printf("\nGAME over by hit the wall ");
   			     break;
  			  }
		while (p == 0)
		{
			p = 1;
			srand(time(0));
			foodx = rand() % (n - 2) + 1;
			foody = rand() % (n - 2) + 1;
		}
			if(x == foodx && y == foody)
			{
				s ++;
				p = 0;
			}
		    printf("scoure is %d", s);
}
	}