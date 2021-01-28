#include <stdio.h>
int main()//82% 
{
	int exp;
	while(scanf("%d",&exp)==1)//2x+0    
	{
		int n=exp;
		int a[100];
		for(int i=0;i<n+1;i++)
		{
			scanf("%d",&a[i]); 
		}
		for(int i=0;exp>=0;i++,exp--)
		{
			if (a[i]==0&&exp!=0)//非常数项系数为0 ，跳过  
			{
				continue;
			}
			if (exp>1&&a[i]!=0)//指数大于1的通项 
			{
				if (a[i]==1)//系数为1，不显示1 
				printf("+x^%d",exp);
				else if (a[i]==-1)//系数为-1，不显示-1 
				printf("-x^%d",exp);
				else if (a[i]>0&&i==0)//第一个数字，且为正，正常显示 
				printf("%dx^%d",a[i],exp);
				else if (a[i]>0&&i!=0)//不是第一个数字，且为正，正数有加号 
				printf("+%dx^%d",a[i],exp);
				else//否则，是负数，正常显示符号和数字 
				printf("%dx^%d",a[i],exp);
			}
			if (exp==1&&n>1)//指数为1的通项  
			{					
				if (a[i]==1)
				printf("+x");
				else if (a[i]==-1)
				printf("-x");
				else if (a[i]>0)
				printf("+%dx",a[i]);
				else
				printf("%dx",a[i]);
			}
			else if (exp==1&&n==1)//n==1就只有一次项和常数项 ，意味着正的，第一个不能带+号 
			{
				printf("%dx",a[i]);		//2x+1
			}
			else if (exp==0&&n>0)//剩下常数项，但这个式子不是只有常数项 ，意味着正的还需要+号 
			{
				if (a[i]>0)
				printf("+%d",a[i]);//2x+3
				else if (a[i]==0)
				continue;
				else
				printf("%d",a[i]);
			}
			else if (exp==0&&n==0)//只有常数项的式子 ，不需要考虑加号 
			{
				printf("%d",a[i]);
			}
		} 
		printf("\n"); 
	}
	return 0;
}
