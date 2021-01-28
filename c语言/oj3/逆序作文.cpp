#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse(char c[]);//每行最后的乱码需要修改即可 
int ends(char c[]);//每行最后的乱码需要修改即可 
int main()//每行最后的乱码需要修改即可 
{
	freopen("逆序.txt","r",stdin);//每行最后的乱码需要修改即可 
	char s[200]={0}; 
	while(gets(s)!=NULL)//这题刁钻在 每个单词都是逆序，所以你每次读入一行，需要对读入这行继续分割，各自逆序 
	{
		if (ends(s)==1)
			continue;//是#下一行
		//world！ hello 
		char *p=s;//p=!dlrow olleh\n
		while(*p!='\n')
		{
			//p跨过空格 
			int flag=0;
			char string[100]={0};
			for(int i=0;*p!=' '&&*p!='\n';i++)
			{
				string[i]=*p; 
				p++;
				if (*p==' ')
				flag++;
			}
			//此时p指向空格 
			reverse(string);
			if (flag)//*p=' '结束的循环 
			printf("%s ",string);
			else//*p=='\n'时结束的循环 
			printf("%s",string);
			if (*p=='\n')
			break;
			else
			p++; 
		 } 
		printf("\n"); //本行逆序完成 
		memset(s,0,200);
	}
	return 0;
}
int ends(char c[])
{
	char *p=c;
	while(*p)
	{
		if (*p=='#')
		return 1;
		p++;
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

