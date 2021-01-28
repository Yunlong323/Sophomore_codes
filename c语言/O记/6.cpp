#include <stdio.h>
int main()
{
	int x;
	//987
	int result;
	while(scanf("%d",&x)!=EOF)
	{
		int sw[3]={0};
		int i=0;
		while(x&&i<3)
		{
			sw[i++]=x%10;//6 1 0
			x/=10;
		}
		if (sw[2]==0&&sw[1]==0)
		printf("%d\n",sw[0]);
		else if(sw[2]==0&&sw[1]!=0)
		printf("%d\n",sw[1]+sw[0]*10);
		else
		{
			result=sw[2]+sw[1]*10+sw[0]*100;
		printf("%d\n",result);
		}
	}
	return 0;
}
