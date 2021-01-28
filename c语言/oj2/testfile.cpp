#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isprime(int a) { //return 1 素数
	if (a==1)
		return 0;
	else if (a==2)
		return 1;
	int flag=0;
	for(int i=2; i<sqrt(a)+1; i++) {
		if (a%i==0)
		{
			flag=1;
			break;
		}
	}
	if (flag==1)
		return 0;
	else
		return 1;
}
int test(int s,int v,int o);
int main()
{
	freopen("fortest.txt","r+",stdin);
	freopen("resulttest.txt","w",stdout);
	int a,step,c;
	for(a=2;a<9703;a++)
	{
		for(step=2;step<3;step++)
		{
			for(int c=1;c<210;c++)
			{
				fprintf(stdin,"%d %d %d",a,step,c);
			}
		}
	}//生成测试数据 
	
	while(!feof(stdin))
	{
		long long int result;
		scanf("%d %d %d",&a,&step,&c);
		result=test(a,step,c);
		printf("%d\n",result);
	}
	return 0;
}

int test(int s,int v,int o)
{
	long long es[100000];
		int flag=0;
		long long number=0;
		while(flag!=o) {
			for(int i=0; i<100000; i++) {
				es[i]=s+v*i;
				if (isprime(es[i]))
					flag++;
				if (flag==o) {
					number=es[i];
					break;
				}
			}
		}
		return number;
}
