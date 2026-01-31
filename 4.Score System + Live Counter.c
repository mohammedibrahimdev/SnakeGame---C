 #include<stdio.h>
#include<windows.h>
int main ()
{
	int score = 0;
	while(1)       //infinite loop because 1 is always true.
	{
		
		printf("THE CERRENT SCORE : %d", score);     //pirnt the cerrent score.
		++score;									// increase
		Sleep(2000);									// wait 200 ms
		system ("cls");								// clear the screen 
	}
}
