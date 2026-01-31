#include<stdio.h>
#include<windows.h>
int main ()
{
	int x =0 , y=0;
	while(1)
	{
		system("cls");		// clear the screen eveytime run.
		
		printf("X = %d", x);  //print x poition.
		
		++x;				//increase x position.
		Sleep(200);			//delay the time to print
		
		
	}
	
}