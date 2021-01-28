#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void change(char *bi,int n)
{
	int i=0;
	while(n)
	{
		bi[i++]=n%2;
		n/=2;//26 0  1  0  1  1 
	}
}
int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if (n==0)
		break;
		char bi[8]={0};
		char *p=bi;
		int i=0;
		change(bi,n);
		while(*p==0)
		{
			i++;
			p++;
		}
		printf("%d\n",(int)(pow(2,i)));
		//26 11010  ´æ0 1 0 11 
	}
	
	
	return 0;
 } 
