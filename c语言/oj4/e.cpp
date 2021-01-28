#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getindex(int a[],int len,int target);
int main()
{
	//freopen("data.txt","r",stdin);
	int n,b;
	while(scanf("%d %d",&n,&b)==2)
	{
		int a[100000]={-1};
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}//ÊäÈëÐòÁÐ 
		
		int count=0;
		int bindex=getindex(a,n,b);
		int offset=0;
		while(bindex+offset<n&&bindex-offset>=0)
		{
			count++;
			offset++;
		}
		printf("%d\n",count);
	}
	return 0;
}
int getindex(int a[],int len,int target)
{
	for(int i=0;i<len;i++)
	{
		if (a[i]==target)
		{
			return i;
		}
	 } 
	
 } 
