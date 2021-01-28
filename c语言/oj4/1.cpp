#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	//freopen("data.txt","r",stdin); 
	char string[105];
	char Name[50]={0};
	char TEL[50]={0};
	char Title[50]={0};
	while(gets(string))//Title:ABCD
	{
		int len=strlen(string); 
		if (len==0)
		break;
		if (string[0]=='N'&&string[1]=='a'&&string[2]=='m'&&string[3]=='e'&&string[4]==':'&&string[5]==' ')
		{
			char *p=string+6;//第一个字符 
			int count=0;
			while(*p)
			{
				Name[count]=*p;
				p++;
				count++;
			 } 
		}
		else if (string[0]=='T'&&string[1]=='i'&&string[2]=='t'&&string[3]=='l'&&string[4]=='e'&&string[5]==':'&&string[6]==' ')
		{
			char *p=string+7;//第一个字符 
			int count=0;
			while(*p)
			{
				Title[count]=*p;
				p++;
				count++;
			 } 
		}
		else if (string[0]=='T'&&string[1]=='E'&&string[2]=='L'&&string[3]==':'&&string[4]==' ')
		{
			char *p=string+5;//第一个字符 
			int count=0;
			while(*p)
			{
				TEL[count]=*p;
				p++;
				count++;
			 } 
		}
		else
		continue;
	}
	printf("%s %s's telephone number is %s.\n",Title,Name,TEL);
	return 0;
 } 
