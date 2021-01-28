#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int inzi[100]={0};
int q=0;
int prime(int n)
{
	if (n==1||n==2)
	return 1;
	else
	{
		for(int i=2;i<n;i++)
		{
			if (n%i==0)
			{
				return 0;//不是素数 
			}
		}
		return 1;//循环结束没有找到，就是素数 
	}
}
void disp(int num)
{
	if (prime(num)==1)
	{
		inzi[q++]=num;
		return;
	}
	
	int num1=num/2;//9
	for(int i=num1;i>1;i--)//从一半开始找合数 
	{
		if (num%i==0)//找到了最大合数 
		{
			inzi[q++]=num/i;//2 num=6  2
			num=i;
			disp(num);  
			break; 
		}
	}
}
int main()
{
	int num=0;
	while(scanf("%d",&num)==1)
	{
		if (prime(num)==1)
		{
			printf("%d\n",num);
			continue;
		}//12=2*2*3  disp(12)=6*2  num1=6 num2=2 disp(num1)
		disp(num);
		for(int i=0;i<q;i++)
		{
			if (i==0)
			printf("%d",inzi[i]);
			else
			{
				printf(" %d",inzi[i]);
			}
		}
		printf("\n");
		
		memset(inzi,0,q);
		q=0;
	 } 
	return 0;
 } 
 
 
 
