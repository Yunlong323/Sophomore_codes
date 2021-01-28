//从（1,1）到（n,m)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cal(int m,int n);
int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)==2) 
	{
		printf("%d\n",cal(m,n));	
	}
	return 0;
}
int cal(int m,int n)
{
	if (m==1||n==1)
	{
		return 1;
	}
	else
	{
		return  cal(n-1,m)+cal(n,m-1);//必经（n-1,m） (n,m-1)
	}
 } 
 
