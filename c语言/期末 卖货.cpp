#include <stdio.h>
#include <string.h>
typedef struct{
	double price;
	double amount;
}Por;
int main()
{
	double M;
	int n;
//	freopen("data.txt","r",stdin);
	
	while(scanf("%lf %d",&M,&n)==2) 
	{
		Por list[100]={0,0};
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&list[i].price,&list[i].amount);
		}
		
		for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
		{
			if (list[i].price>list[i+1].price)
			{
				Por temp=list[i];
				list[i]=list[i+1];
				list[i+1]=temp;
			}
		}
		
		double sum=0;
		double cost=0;
		int i=0;
		while(1)
		{
			if (i==n||list[i].price*list[i].amount+cost>M)
			{
				break;
			}
			else
			{
				cost+=list[i].price*list[i].amount;
			}
			sum+=list[i].amount;
			i++;
		}//list[i]没买完 
		if (i==n)
		{
			continue;
		}
		
		double remain=M-cost;
		double amounts=0;
		for(amounts=0;amounts<list[i].amount;amounts++)
		{
			if (amounts*list[i].price>remain) break;
		}
		//找到范围,确定到小数点后两位 
		double  deep=amounts-1;
		double top=amounts;
		for(;deep<=top;deep+=0.01)
		{
			if (deep*list[i].price>remain) break;
		}
		deep-=0.01;
		sum+=deep;
		printf("%.2lf\n",sum);
	
		
	}
	return 0;
}
