#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int iseven(char num[],int len)//12
{
	if ((num[len-1]-'0')%2==0)
	return 1;
	else
	return 0;
}
int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)
	{
		char num[100][65]={0};//最多100个数字，60位 
//		int count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",&num[i]);
			int len=strlen(num[i]);
			if (iseven(num[i],len)==1)
			{
				printf("even\n");
			}
			else
			printf("odd\n");
		}
		
	}
}
