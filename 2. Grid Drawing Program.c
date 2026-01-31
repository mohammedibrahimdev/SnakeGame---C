#include<stdio.h>
int main ()
{
	int i,j,width , height;
	printf("Enter width :\n");   //take the input as width.
	scanf("%d", &width );
	
	printf("Enter height:\n");   //take the input as height.
	scanf("%d", &height );
	
	
	for(i =1;i<=height;++i)		//for height that as you give input.
	{								//print the (.) as you give width and height.
		
		for(j =1;j<=width;++j)  //for width ......
		{
			printf(".");
			
		}
		printf("\n");
		
	}
}