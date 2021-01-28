#include <stdio.h> 
#include <string.h>
int main()
{
	char string[300];
//	freopen("data.txt","r",stdin);
	int times=0;
	int length=0;
	while(gets(string)!=NULL)
	{	
		char *p=string;
		int count=0;
		while(*p)
		{
			if (*p!=32&&*p!=9)
				count++;
			p++;
		}
		if (count!=0) length++;
		if (strcmp(string,"#")==0)
		{
			times++;
			if (times%2==0)
			{
				printf("%d\n",length-2);
				length=0; 
				continue;
			}
			else
			continue;
		}
	}
	return 0;
}
