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
			if (a[i]==0&&exp!=0)//�ǳ�����ϵ��Ϊ0 ������  
			{
				continue;
			}
			if (exp>1&&a[i]!=0)//ָ������1��ͨ�� 
			{
				if (a[i]==1)//ϵ��Ϊ1������ʾ1 
				printf("+x^%d",exp);
				else if (a[i]==-1)//ϵ��Ϊ-1������ʾ-1 
				printf("-x^%d",exp);
				else if (a[i]>0&&i==0)//��һ�����֣���Ϊ����������ʾ 
				printf("%dx^%d",a[i],exp);
				else if (a[i]>0&&i!=0)//���ǵ�һ�����֣���Ϊ���������мӺ� 
				printf("+%dx^%d",a[i],exp);
				else//�����Ǹ�����������ʾ���ź����� 
				printf("%dx^%d",a[i],exp);
			}
			if (exp==1&&n>1)//ָ��Ϊ1��ͨ��  
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
			else if (exp==1&&n==1)//n==1��ֻ��һ����ͳ����� ����ζ�����ģ���һ�����ܴ�+�� 
			{
				printf("%dx",a[i]);		//2x+1
			}
			else if (exp==0&&n>0)//ʣ�³���������ʽ�Ӳ���ֻ�г����� ����ζ�����Ļ���Ҫ+�� 
			{
				if (a[i]>0)
				printf("+%d",a[i]);//2x+3
				else if (a[i]==0)
				continue;
				else
				printf("%d",a[i]);
			}
			else if (exp==0&&n==0)//ֻ�г������ʽ�� ������Ҫ���ǼӺ� 
			{
				printf("%d",a[i]);
			}
		} 
		printf("\n"); 
	}
	return 0;
}
