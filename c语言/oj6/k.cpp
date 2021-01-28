#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	freopen("data.txt","r",stdin);
	int remain=0,mom=0,re=0;
	int i=1;
	for(i=1;i<=12;i++)
	{
		scanf("%d",&re);
		remain=300+remain-re;
		if (remain<0)
		{
			printf("-%d\n",i);
			break;
		}
		if (remain>=100)
		{
			mom+=(remain/100)*100;
			remain=remain-(remain/100)*100;
		}
	}
	if (i==13)
	printf("%.0f\n",mom*1.2);
	return 0;
 } 
