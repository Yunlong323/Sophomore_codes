#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int count=0;
		int mod=0;
		count=n/21;
		mod=n%21;
		if (mod<2)
		{
			printf("%d\n",count*6);
		}
		else if (mod>=2&&mod<4)
		{
			printf("%d\n",count*6+1);
		}
		else if (mod>=4&&mod<5)
		{
			printf("%d\n",count*6+2);
		}
		else if (mod>=5&&mod<6)
		{
			printf("%d\n",count*6+3);
		}
		else if (mod>=6&&mod<10)
		{
			printf("%d\n",count*6+4);
		}
		else if (mod>=10&&mod<15)
		{
			printf("%d\n",count*6+5);
		}
		else if (mod>=15&&mod<21)
		{
			printf("%d\n",count*6+6);
		}
	}
	return 0;
 } 
