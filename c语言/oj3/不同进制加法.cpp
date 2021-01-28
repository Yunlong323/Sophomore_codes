#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void reverse(char c[]);
int main()
{
	long long da=0,db=0,result=0;
	char a[10]={0},b[10]={0},c[10]={0};
	int d1,d2,d3,num;
	while(scanf("%d",&num)!=EOF)
	{
		for(int o=0;o<num;o++)
		{
			scanf("%s%d%s%d%d",a,&d1,b,&d2,&d3);
			{
				int lena=strlen(a);
				int lenb=strlen(b);
				for(int i=0;i<lena;i++)
				{
					da+=(a[i]-'0')*(int)pow(d1,lena-i-1);
				}
				for(int i=0;i<lenb;i++)
				{
					db+=(b[i]-'0')*(int)pow(d2,lenb-i-1);
				}
				result=da+db;//max 10λ
				for(int i=0;i<10;i++)
				{
					c[i]=result%d3+'0';
					result/=d3;
					if (result==0)
					break;
				}
				reverse(c);
				printf("%s\n",c);
			}
			memset(a,0,10);
			memset(b,0,10);
			memset(c,0,10);
			result=0;
			da=0;
			db=0;
		}
	}
	
	
	return 0;
 } 
 void reverse(char c[])
 {
 	int len=strlen(c);
 	for(int i=0;i<len/2;i++)
 	{
 		char temp=c[i];
 		c[i]=c[len-i-1];
 		c[len-i-1]=temp;
	 }
 }
