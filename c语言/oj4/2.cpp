#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int isprime(int m);
int main()
{
	int num;
	while(scanf("%d",&num)==1)
	{
		if (isprime(num)==1)
		{
			printf("%d=%d\n",num,num);
			continue;
		}		
		printf("%d=",num);
		int storenum[20]={0};
		int thenum=num;//36 
		int result=1; 
		int div=2;
		int i=0;//记录分解的数字的个数 
		while(result!=thenum)
		{
			if (num%div==0&&i==0)
			{
				printf("%d",div);
				result*=div; 
				i++;
				num/=div;
				div=2;
			} 
			else if (num%div==0&&i>0)
			{
			 	printf("*%d",div);
			 	result*=div;
			 	i++;
			 	num/=div;
			 	div=2;
			}
			else
			{
				div++;
			}
		}
		printf("\n");
	}
	return 0;
}
int isprime(int m)
{
	if (m==1||m==2)
	return 1;
	
	int i=2;
	for(;i<(int)sqrt(m)+1;i++)
	{
		if (m%i==0)
			return 0;
	}
	if (i==(int)sqrt(m)+1)
	return 1;
}
