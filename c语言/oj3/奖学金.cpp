#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sumarray(int sum[],int len);
int max(int max[],int len);
int cal(int qimo,int pingyi,int ganbu,int xibu,int lunwen);
int main()
{
	//freopen("info.txt","r",stdin); 
	int num=0;
	scanf("%d",&num);
		int sum[100]={0};
		int maxl=0;
		char name[100][100]={0};
		for(int l=0;l<num;l++)
		{
			int qimo=0;
			int pingyi=0;
			int ganbu=0;
			int xibu=0;
			int lunwen=0;
			scanf("%s%d%d %c %c %d",name[l],&qimo,&pingyi,&ganbu,&xibu,&lunwen);
			sum[l]=cal(qimo,pingyi,ganbu,xibu,lunwen); 
		}
		maxl=max(sum,100);
		printf("%s\n%d\n%d",name[maxl],sum[maxl],sumarray(sum,100));
	
	return 0;
}
int cal(int qimo,int pingyi,int ganbu,int xibu,int lunwen)
{
	int result=0;
	if (qimo>80&&lunwen>=1)
	result+=8000;
	if (qimo>85&&pingyi>80)
	result+=4000;
	if (qimo>90)
	result+=2000;
	if (qimo>85&&xibu=='Y')
	result+=1000;
	if (qimo>80&&ganbu=='Y')
	result+=850;
	return result;
}
int max(int max[],int len)
{
	int index=0;
	int ma=max[0];
	for(int i=0;i<len;i++)
	{
		if (max[i]>ma)
		{
			index=i;
			ma=max[i];
		}
	}
	return index;
}
int sumarray(int sum[],int len)
{
	int result=0;
	for(int i=0;i<len;i++)
	{
		result+=sum[i];
	}
	return result;
}


