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
void column_zero(char qp[][13],int i,int j,int n)//��i��ȫ0 
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
	for(int m=0;m<n;m++)//��j��ȫ0 
	{
		if (m!=i)
		{
			qp[m][j]='0';
		}
	} 
}
void axis_zero(char qp[][13],int i,int j,int n)//�Խ�����0 
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
	scanf("%d",&n);//n�ʺ�
	int flag=0;
	char qp[13][13]={'1'};
	int results=0;
//�ҽ� 
		int i=0;
		int j=0;
		int all=0;
		int count=0;
		for(all=0;all<n;all++) //all=1,����i=2�Ľ� 
		{
				for(i=all;i<n;i++)//i=1�Ľ�  ֮����i=2��3��./....n�Ľ� 
				{
					for(int j=0;j<n;j++)
					{
						if (qp[i][j]=='0')//����Ѿ���0����������һ�У���j���ƣ�ֱ���з�0�ģ���ʼ��1 
						continue;
						column_zero(qp,i,j,n);
						row_zero(qp,i,j,n);
						axis_zero(qp,i,j,n);
						printf("��β��Եĳɹ���Ϊ��(%d,%d)\n",i,j); 
						count++;//���������n�������н� 
						break;//��һ���Ѿ���������������һ�� 
					} 	
				}
				if (count==n)//˵������˽�
				{
					if (results<=3)//���ǰ������ 
					print_answer(qp,n);
					results++;
					count=0;
				} 
				for(int c=0;c<n;c++)
				memset(qp[c],'1',n);
		} //�ҽ���� 
	printf("%d\n",results); //%d�ʺ�������ܽ���Ϊ��%d��
	return 0;
 } 
