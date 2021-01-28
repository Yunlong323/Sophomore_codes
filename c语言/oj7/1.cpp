#include <stdio.h>
#include <string.h>
#include <stdlib.h>//第一题还没有做多行输入 
#include <math.h>		
int main()
{
	//freopen("data.txt","r",stdin);
	int num=0;
	int array[10005]={0};
	int i=0;//共有i个输入元素 
	while(scanf("%d",&array[i])==1)
	{
		num=array[i];
		if (i>0)//第一个，不比较 
		for(int j=i;j>0;j--)
		{
		
			if (num>array[j-1])//如果大于，就前移，小的部分后移； 
			{
				array[j]=array[j-1];
				array[j-1]=num;
			}
			else//如果直接小，直接后接即可
				break;
		}
		i++;//输入一个，i=1；输入1000个 i=1000 
	}
	printf("%d",array[0]);
	for(int h=1;h<i;h++)
	{
		printf(" %d",array[h]);
	}
	printf("\n");

	return 0;
 } 
 
 
 
