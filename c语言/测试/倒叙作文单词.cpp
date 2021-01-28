#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse_print(char string[],int n)
{
	for(int i=0;i<n/2;i++)
	{
		char tmep=string[i];
		string[i]=string[n-i-1];
		string[n-1-i]=tmep;
	}
	printf("%s",string);
}
int main()
{
	freopen("data.txt","r",stdin);
	int jing=0;
	char string[1000];
	while(scanf("%s",string)!=EOF)
	{
		if (strcmp(string,"#")==0)
		{
			continue;
		}
		char ch;
		ch=getchar(); 
		if (ch=='\n') 
		{
			printf("\n");
			continue;//ÏÂÒ»ÐÐ
		}
		reverse_print(string,strlen(string));
				
	}
	return 0;
}
