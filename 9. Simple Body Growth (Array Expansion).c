#include<stdio.h>
#include<time.h>
#include<windows.h>
#define max 100
#define n 20
int x = 0 , y = 0;
int length = 3;
int foodx , foody;
int main ()
{
	int j,i,scoure = 0;
	int snakex[max],snakey[max];
	char key, dir;
	
	// position of snake heard,body,tail.
	
	snakex[0] =5; snakey[0] = 5; // Heard
	snakex[1] = 5; snakey[1] = 4; // Body
	snakex[2] = 5; snakey[2] = 3; // tail
	
	srand(time(0));
	foodx = rand() % (n -2) + 1;
	foody = rand() % (n - 2) + 1;
	
	while(1)
	{
		system("cls");
		for( i = 0;i<n;++i) printf("_");
		printf("\n");
		for(i = 0;i<n - 2;++i)
		{
			for(j = 1;j<=1;++j) printf("|");
			for(j = 0;j<n - 2;++j) printf(" ");
			for(j = 1;j<=1;++j) printf("|");
			printf("\n");
		}
		for(i = 0;i<n;++i) printf("_");
		
		if(_kbhit())
		{
			key = _getch();
			{
  					if ((key == 'W' || key == 'w') && dir != 'S') dir = 'W';
 					if ((key == 'S' || key == 's') && dir != 'W') dir = 'S';
    				if ((key == 'A' || key == 'a') && dir != 'D') dir = 'A';
    				if ((key == 'D' || key == 'd') && dir != 'A') dir = 'D';
			}
		}
			// changing the positin of Snake Body
			for(i = length-1;i>0;--i)
			{
				snakex[i] = snakex[i-1];
				snakey[i] = snakey[i-1];
			}
			
			// Move heard
			if(dir == 'W')snakey[0]--;
			if(dir == 'S')snakey[0]++;
			if(dir == 'A')snakex[0]--;
			if(dir == 'D')snakex[0]++;
			printf("\nThe location is : (%d, %d)", snakex[0], snakey[0]);
			//if hit the wall 
			if(snakex[0] <= -19 || snakex[0] >= n - 1 || snakey[0] <= -19 || snakey[0] >= n - 1)
			{
				printf("\n GAME OVER! \nYOU  HIT THE WALL \n ");
				break;
			}
			
			// Eat the food
			if(snakex[0] == foodx && snakey[0] == foodx)
			{
				scoure++;
				length++;
				
				//Add new tail 
				snakex[length - 1] = snakex[length - 2];
				snakey[length - 1] = snakey[length - 2]; 
				
				//new food
				foodx = rand() % (n - 2) +1;
				foody = rand() % (n - 2) + 1;
			}
			printf("\nscore is : %d\nsnake length is : %d", scoure,length);
		Sleep(200);
	}
}

