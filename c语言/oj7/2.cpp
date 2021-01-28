#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double cal(int n,double x)
{
	if (n==0)
	return 1.00;
	else if (n==1)
	return x;
	else if (n>1)
	{
		double mu=(2*n-1)*x*cal(n-1,x)-(n-1)*cal(n-2,x);
		return mu/n;
	}
}
int main()
{
//	freopen("data.txt","r",stdin);
	int n=0;
	double x=0;
	while(scanf("%d %lf",&n,&x)==2)
	{
		printf("%.2lf\n",cal(n,x));
	 } 
	return 0;
 } 
 
 
