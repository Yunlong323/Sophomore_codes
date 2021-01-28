#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct string{
	char na[505];
	int len;
}string; 
int main()
{
	int n=0;
	freopen("data.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		getchar();
		string name[500]={{0},0};
		for(int i=0;i<n;i++)
		{
			gets(name[i].na);
			name[i].len=strlen(name[i].na);
		}
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n-1-i;j++)//先排字母序，然后冒泡拍数量 大的在后，逆序输出 
		{
			if (strcmp(name[j].na,name[j+1].na)>0)
			{
				string temp=name[j];
				name[j]=name[j+1];
				name[j+1]=temp;
			}
		}
		
		for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++) 
		{
			if (name[j].len>name[j+1].len)
			{
				string temp=name[j];
				name[j]=name[j+1];
				name[j+1]=temp;
			}
		}
		
		for(int i=n-1;i>=0;i--)//短的在前，长的在后 
		{
			puts(name[i].na);
		}
		
	}
	return 0;
}
