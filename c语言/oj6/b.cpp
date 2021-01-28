#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	//freopen("data.txt","r",stdin);
	char ch;
	char string[2005];
	int stringlen=0;
	char target[15]={0};
	int targetlen=0;
	int flag=0;
	while((ch=getchar())!=EOF)
	{
		if (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
			string[stringlen++]=ch; 
		if (ch=='#')
		{
			flag=1;
			continue;	
		}
		if (flag==1)
		{
			if (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
			{
				target[targetlen]=ch;
				targetlen++;
			}
		}
	}
	int len=0,times=0;
	char *p1=string;
	char *p2=target;
	
	
	while(*p1)
	{
		if (*p1==*p2)
		{
			len++;
			for(int i=1;i<targetlen;i++)
			{
				if (*(p1+i)==*(p2+i))
				{
					len++;
				}
				else
				break;
			}
			if (len==targetlen)
			{
				times++;
				len=0;
				p1=p1+targetlen-1;
			}
			else
			{
				p1=p1+1;
				len=0;
			}
		}
		p1++;
	}
	printf("%d time(s)",times-1);
	
	return 0;
}

