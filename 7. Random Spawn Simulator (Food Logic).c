#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
int x = 1,y = 1;
int foodx = 0 , foody = 0;
int main ()
{
	int n =  10, i,j,p = 0,s = 0;
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
		
		char key ;
		if(_kbhit())
		{
			key = _getch();
			{
				if(key == 'W' || key == 'w') y++;
				if(key == 'S' || key == 's') y--;
				if(key == 'A' || key == 'a') x--;
				if(key == 'D' || key == 'd') x++;
			}
		}
		printf("\nthe location of the snake : (%d, %d)\n", x,y);
		if(x == 10 || y == 10)
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