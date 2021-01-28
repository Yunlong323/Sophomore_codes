#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if (n==0||n==1||n==2)
			printf("%d\n",n==0?0:1);
		else
		{
			int a=1,b=1,result;
 			for(int i=2;i<n;i++)//ÇóF£¨n£© 
		 	{
		 		result=a+b;
		 		if (result>10000)
		 		{
		 			result%=10000;
		 			a%=10000;
		 			b%=10000;
				}
				a=b;
				b=result;
			 }
			printf("%lld\n",result%10000);
		}
	}
	return 0;
}

