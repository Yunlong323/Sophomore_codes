#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Fib(int num)
{
	if (num==0)
	return 0;
	else if (num==1||num==2)
	return 1;
	else
	{
		int result1=1;
		int result2=1;//1 1 2 3 5 8
		int result;
		if (num>10000000) num/=1000;
		else if (num>1000000) num/=100;
		else if (num>100000) num/=10; 
		//if (num>100000) num/=10;
		for(int i=1;i<num-1;i++)
		{
			result=result1+result2;
			result1=result2;
			result2=result;
			
			if (result1>10000||result2>10000)
			{
				result1%=10000;
				result2%=10000;
			}
		}
		 
		return result%10000;
	}
}
int main()
{
//	freopen("data.txt","r",stdin);
	int num=0;
	while(1)
	{
		scanf("%d",&num);
		if (num==-1)
		break;
		
		printf("%d\n",Fib(num)); 
	}
	
	return 0;
} 
