#include <stdio.h>
int main()
{
	freopen("data.txt","r",stdin);
	int num=0;
	int array[10005]={0};
	int i=0;//����i������Ԫ�� 
	char ch;
		while(scanf("%d%c",&array[i],&ch)==2)//�������ڣ���ʹ������һ�У���Ҳ���ܱ�֤�������������ԣ�һ��ֻ�ܶ�ȡһ�� 
		{
			if (ch=='\n'||ch=='\r')
			{
				printf("\n");
				continue;
			}
			num=array[i];
			if (i>0)//��һ�������Ƚ� 
			{
				int j=i;
				for(j=i;j>0;j--)
				{
			
					if (num>array[j-1])//������ڣ���ǰ�ƣ�С�Ĳ��ֺ��ƣ� 
					{
						array[j]=array[j-1];
						array[j-1]=num;
					}
					else//���ֱ��С��ֱ�Ӻ�Ӽ���
						break;
				}
			 } 
			i++;//����һ����i=1������1000�� i=1000 
		}		 
		printf("%d",array[0]);
		int h=1;
		for(h=1;h<i;h++)
		{
			printf(" %d",array[h]);
		}
		printf("\n");			
	return 0;
 } 
 
 
 
