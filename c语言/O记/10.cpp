#include <stdio.h>
#include <string.h>
int main()
{
	int lengthF,lengthG;
	long long int F[100]={0},G[100]={0};
	long long int store[201]={0};//100+100
	while(scanf("%d %d",&lengthF,&lengthG)!=EOF)
	{
		for(int i=0;i<lengthF;i++)
			scanf("%lld",F+i);
		for(int i=0;i<lengthG;i++)
			scanf("%lld",G+i);
			
		for(int i=0;i<=lengthF;i++)
			for(int j=0;j<=lengthG;j++)
			{
				store[i+j+2]+=F[i]*G[j];
			}

		for(int i=2;i<=lengthF+lengthG;i++)
		{
			if (i==2&&store[i])
			printf("%lld",store[i]);
			else if(i>2&&store[i])
			printf(" %lld",store[i]);
		}
		printf("\n");
		memset(store,0,sizeof(store));
		memset(G,0,sizeof(F));
		memset(F,0,sizeof(G));

	}
	return 0;
 } 
