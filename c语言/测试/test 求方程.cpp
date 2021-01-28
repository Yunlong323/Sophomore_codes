#include <stdio.h>
#include <string.h>
double cal(int a,int b,int c,int d,double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
double find(int m,int n,int a,int b,int c,int d)
{
	int mid=(m+n)*1.0/2;
	while(cal(a,b,c,d,mid)-0.001<1e-6)
	{
		mid=(m+n)*1.0/2;
		double result1=cal(a,b,c,d,m*1.0);
		double result2=cal(a,b,c,d,n*1.0);
		double result3=cal(a,b,c,d,mid);
		if (result1==0)
		return m*1.0;
		if (result2==0)
		return n*1.0;
		if (result3-0.001<1e-6)
		return mid;
		if (result1*result3<0)
		n=mid;
		else if (result3*result2)
		m=mid;
	}
	return mid;
}
int main()
{
	int a,b,c,d;
	a=b=c=1;
	d=0;
	//printf("cal(-1)*cal(-2)=%d\n",cal(a,b,c,d,-1.0)*cal(a,b,c,d,-2.0)) ;
	for(int i=-2;i<2;i++)
	{
		double x=find(i,i+1,a,b,c,d);
		printf("½âÎª£º%f\n",x);
	 } 
	
	return 0;
}
