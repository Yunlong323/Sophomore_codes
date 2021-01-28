#include<stdio.h>
#include<math.h>
int main()
{
	int n=10000000001;
	int bool1;
	printf("%f %d",sqrt(n),(int)sqrt(n));
	if (sqrt(n)==(int)sqrt(n))//双精度的数字可以和整数直接比大小 
	{
		printf("是完全平方数\n");
	}
	else
	{
		printf("no\n");
	}
}
