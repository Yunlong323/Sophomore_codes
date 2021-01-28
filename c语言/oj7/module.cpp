#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void print_answer(char qp[][13],int n)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (qp[i][j]=='1'&&flag==0)
			{
				printf("%c",j);
				flag=1;
			}
			else if (qp[i][j]=='1'&&flag==1)
			{
				printf(" %c",j);
			}
		}
	}
	printf("\n");
} 
void column_zero(char qp[][13],int i,int j,int n)//第i行全0 
{
	for(int m=0;m<n;m++)
	{
		if (m!=j)
		{
			qp[i][m]='0';
		}
	} 
}
void row_zero(char qp[][13],int i,int j,int n)
{
	for(int m=0;m<n;m++)//第j列全0 
	{
		if (m!=i)
		{
			qp[m][j]='0';
		}
	} 
}
void axis_zero(char qp[][13],int i,int j,int n)//对角线置0 
{
	int add=i+j;
	if (i>=j)
	{
		int sub=i-j;
		for(int m=0;m<n;m++)
		for(int l=0;l<n;l++)
		{
			if (m+n==add)
			{
				qp[m][n]='0';
			}
			if (m-n==sub||n-m==sub)
			qp[m][n]='0';
		}
	}
	else
	{
		int sub=j-i;
		for(int m=0;m<n;m++)
		for(int l=0;l<n;l++)
		{
			if (m+n==add&&m!=i&&n!=j)
			{
				qp[m][n]='0';
			}
			if ((m-n==sub||n-m==sub)&&m!=i&&n!=j)
			qp[m][n]='0';
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);//n皇后
	int flag=0;
	char qp[13][13]={'1'};
	int results=0;
//找解 
		int i=0;
		int j=0;
		int all=0;
		int count=0;
		for(all=0;all<n;all++) //all=1,就是i=2的解 
		{
				for(i=all;i<n;i++)//i=1的解  之后找i=2，3，./....n的解 
				{
					for(int j=0;j<n;j++)
					{
						if (qp[i][j]=='0')//如果已经是0，就跳到下一行，让j后移，直到有非0的，开始置1 
						continue;
						column_zero(qp,i,j,n);
						row_zero(qp,i,j,n);
						axis_zero(qp,i,j,n);
						printf("这次测试的成功点为：(%d,%d)\n",i,j); 
						count++;//如果数够了n个就是有解 
						break;//这一行已经结束所以跳到下一行 
					} 	
				}
				if (count==n)//说明求出了解
				{
					if (results<=3)//输出前三个解 
					print_answer(qp,n);
					results++;
					count=0;
				} 
				for(int c=0;c<n;c++)
				memset(qp[c],'1',n);
		} //找解完毕 
	printf("%d\n",results); //%d皇后问题的总解数为：%d种
	return 0;
 } 
