#include <stdio.h>
#include <string.h>
#include <stdlib.h>//��һ�⻹û������������ 
#include <math.h>		
int main()
{
	//freopen("data.txt","r",stdin);
	int num=0;
	int array[10005]={0};
	int i=0;//����i������Ԫ�� 
	while(scanf("%d",&array[i])==1)
	{
		num=array[i];
		if (i>0)//��һ�������Ƚ� 
		for(int j=i;j>0;j--)
		{
		
			if (num>array[j-1])//������ڣ���ǰ�ƣ�С�Ĳ��ֺ��ƣ� 
			{
				array[j]=array[j-1];
				array[j-1]=num;
			}
			else//���ֱ��С��ֱ�Ӻ�Ӽ���
				break;
		}
		i++;//����һ����i=1������1000�� i=1000 
	}
	printf("%d",array[0]);
	for(int h=1;h<i;h++)
	{
		printf(" %d",array[h]);
	}
	printf("\n");

	return 0;
 } 
 
 
 
