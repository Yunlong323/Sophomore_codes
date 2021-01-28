#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	long long n=1;
	int times,k;
	while(scanf("%d %d",&times,&k)==2)
	{
		for(int i=2;i<=times;i++)
			n=n*i;
		char number[100]={0};
		int sw=0;
		long long num=n;
		while(num)
		{
			num/=10;
			sw++; 
		}

		num=n;
		for(int i=sw-1;i>=0;i--)
		{
			number[i]=num%10+'0';
			num/=10;
			printf("%c",number[i]);
		}
		printf("\n");
		char *p=&number[sw-1];
		while(*p=='0')
		{
			p--;
			sw--;
		}//结束时，去除了所有0
		if (sw>k)
		{
			for(int i=sw-k;i<=sw-1;i++)
			{
				printf("%c",number[i]);
			}
			printf("\n");	
		}
		else
		{
			for(int i=0;i<=sw-1;i++)
			{
				printf("%c",number[i]);
			}
			printf("\n");
		}
		
	}
	return 0;
 } 
