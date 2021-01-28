#include <stdio.h>
int main()
{
	int grade;
	while(scanf("%d",&grade)!=EOF)
	{
		if (!(grade>=0&&grade<=100))
		{
			printf("Score is error!\n");
			continue;
		}
		switch(grade/10)
		{
			case 10: printf("A\n");break;
			case 9:printf("A\n");break;
			case 8:printf("B\n");break;
			case 7:printf("C\n");break;
			case 6:printf("D\n");break;
			default:printf("E\n");break;
		}
	}
	return 0;
 } 
