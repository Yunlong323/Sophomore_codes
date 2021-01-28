#include <stdio.h>
int strlen(char s1[]);
void memset(char s1[],char c,int size)
{
	for(int i=0;i<size;i++)
	{
		s1[i]=c;
	}
}
int main()
{
	char s[2][4]={'a','b','c','d','e','f','g','h'};
	memset(s[0],'0',4*sizeof(s));
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
{
		printf("%c",s[i][j]);
}
}



int strlen(char s1[])
{
	int length=0;
	while(*(s1+length)!='\0')
	{
		length++;
	}
	return length;
}
