#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define n 20
#define max 100
int foodx, foody;
int x = 0, y = 0;
int length = 3;
int score = 3;
int main ()
{
	int j,i;
	int snakeX[max], snakeY[max];
	char key, dir;
	
	// position of the heard, Body,tail
	snakeX[0] = 5; snakeY[0] = 5; //Heard
	snakeX[1] = 5; snakeY[1] = 4; //Body
	snakeX[2] = 5; snakeY[2] = 3; //Tail
	
	srand(time(0));
	foodx = rand() % (n - 2) + 1;
	foody = rand() % (n - 2) + 1;
	
	while(1)
	{
		system("cls");
		for(i = 0;i<n;++i) printf("_");
		printf("\n");
		for(i = 0;i<n - 2;++i)
		{
			for(j = 1;j<=1;++j) printf("|");
			for(j = 0;j<n - 2;++j) printf(" ");
			for(j = 1;j<=1;++j) printf("|");
			printf("\n");
		}
		for(i = 0;i<n;++i) printf("_");
		printf("\n");
		
		if(_kbhit())
		{
			key = _getch();
			{
				if ((key == 'W'|| key == 'w') && dir!='S') dir = 'W';
				if ((key == 'S'|| key == 's') && dir!='W') dir = 'S';
				if ((key == 'A'|| key == 'a') && dir!='D') dir = 'A';
				if ((key == 'D'|| key == 'd') && dir!='A') dir = 'D';
			}
		}
		// change the positions
		for(i = length - 1;i>0;--i)
		{
			snakeX[i] = snakeX[i - 1];
			snakeY[i] = snakeY[i - 1];
		}
		 
		 // Move the Heard
		 if(dir == 'W') snakeY[0]--;
		 if(dir == 'S') snakeY[0]++;
		 if(dir == 'A') snakeX[0]--;
		 if(dir == 'D') snakeX[0]++;
		 printf("The location of  Heard : (%d, %d)\n", snakeX[0], snakeY[0]);
		 
		 //if hit the wall
		 	if(snakeX[0] <= -19 || snakeX[0] >= n - 1 || snakeY[0] <= -19 || snakeY[0] >= n - 1)
			{
				printf("\n GAME OVER! \nYOU  HIT THE WALL \n ");
				break;
			}
		 
		 // eat the food
		 if(snakeX[0] == foodx && snakeY[0] == foody)
		{
		 	length++;
		 	score++;
		 	
		 	//new tail
		 	snakeX[length - 1] = snakeX[length - 2];
		 	snakeY[length - 1] = snakeY[length - 2];
		 	
		 	//new food
		 	foodx = rand() % (n - 2) + 1;
		 	foody = rand() % (n - 2) + 1;
		}
		printf("scoure : %d\nsnake length : %d", score, length);
		Sleep(200);	
	}
}
