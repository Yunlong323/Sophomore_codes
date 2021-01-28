#include <stdio.h>
#include <string.h>
#include <math.h>
double cal(int a,int b,int c,int d,double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}

double find(double m,double n,int a,int b,int c,int d)
{
	double mid=(m+n)*1.0/2;
	double result1=cal(a,b,c,d,m*1.0);
	double result2=cal(a,b,c,d,n*1.0);
	double result3=cal(a,b,c,d,mid);
	if (fabs(result1)<=1e-6)
	return m;
	if (fabs(result2)<=1e-6)
	return n;
	while(cal(a,b,c,d,mid)==0)
	{
		mid=(m+n)*1.0/2;
		result1=cal(a,b,c,d,m*1.0);
		result2=cal(a,b,c,d,n*1.0);
		result3=cal(a,b,c,d,mid);
		if (fabs(result1)<=1e-6)
		return m;
		if (fabs(result2)<=1e-6)
		return n;
		
		if (fabs(result3)<=1e-6)
		return mid;
		if (result1*result3<0)
		n=mid;
		else if (result3*result2<0)
		m=mid;
	}
	return mid;
}
int main()
{
	int a,b,c,d;
	freopen("data2.txt","r",stdin); 
	while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
	{
		int count=0;
		double repeat[3]={0};
		for(float i=-100.5;i<=100.5;i++)
		{
			double result=cal(a,b,c,d,i*1.0)*cal(a,b,c,d,(i+1)*1.0);
			if (result<=0)
			{
				double x=find(i,i+1.0,a,b,c,d);
				printf("%.2lf",x);
				count++;
				if (count==3)
				{
					printf("\n");
					break;
				}
				else
					printf(" ");
			}
		}
	}
	return 0;
}
