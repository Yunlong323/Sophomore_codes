#include <stdio.h>
#include <string.h>
#include <math.h>
double cal(int a,int b,int c,int d,double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
//double find(double m,double n,int a,int b,int c,int d)
//{
//	int mid=(m+n)*1.0/2;
//	double result1=cal(a,b,c,d,m*1.0);
//	printf("result1:%lf\n",result1);
//	double result2=cal(a,b,c,d,n*1.0);
//		printf("result2:%lf\n",result2);
//	double result3=cal(a,b,c,d,mid);
//	if (fabs(result1)-1e-6<=0)
//	{
//			printf("走了result1:%lf\n",result1);
//		return m*1.0;
//	}
//	if (fabs(result2)-1e-6<=0)
//	{
//					printf("走了result2:%lf\n",result2);
//
//			return n*1.0;
//
//	 } 
//	printf("走下面了吗？\n");
//	while(fabs(cal(a,b,c,d,mid)-1e-6)>=0)
//	{
//		mid=(m+n)*1.0/2;
//		result1=cal(a,b,c,d,m*1.0);
//		result2=cal(a,b,c,d,n*1.0);
//		result3=cal(a,b,c,d,mid);
//		
//		if (result1==0)
//		return m*1.0;
//		if (result2==0)
//		return n*1.0;
//		if (result3==0)
//		return mid;
//		
//		if (result1*result3<0)
//		n=mid;
//		else if (result3*result2<0)
//		m=mid;
//	}
//	printf("结果是mid:%f\n",mid);
//	return mid;
//}

int main()
{
	double x=2.0;
	int a,b,c,d;
	freopen("data2.txt","r",stdin);
	scanf("%d %d %d %d",&a,&b,&c,&d);

		printf("%lf\n",cal(a,b,c,d,-2.5));

	return 0;
}
