#include <stdio.h>
#include <string.h>
int sta(int num[],int n)
{
	int even=0;

	for(int i=0;i<n;i++)
	{
		if (num[i]%2==0)
			even++;
	}
	if (even%2==0)
		return 0;
	else 
		return 1;
}
int main()
{
	int T;
//	freopen("data.txt","r",stdin);
	while(scanf("%d",&T)!=EOF) 
	{
		for(int m=0;m<T;m++)
		{
			int n=0,num[10001]={0};
			scanf("%d",&n);
			for(int i=0;i<n;i++)
			{
				scanf("%d",&num[i]);
			}
			if (sta(num,n)==1)
				printf("Win\n");
			else
				printf("Lose\n");
		}	
	}
 } 
