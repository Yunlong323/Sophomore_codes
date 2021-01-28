#include <stdio.h>
#include <string.h>
int main()
{
	int x,y;
	while(scanf("%d %d",&x,&y)==2)
	{
		int backx=x%100;
		int backy=y%100; 
		x=x/100;
		y=y/100;
		if (backy<backx)
		{
			printf("The train journey time is %d hours %d minutes.\n",y-1-x,backy+60-backx);
		 } 
		 else
		 {
		 		printf("The train journey time is %d hours %d minutes.\n",y-x,backy-backx);
		 }       
	}
	return 0;
 } 
