#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse(char c[]);//ÿ������������Ҫ�޸ļ��� 
int ends(char c[]);//ÿ������������Ҫ�޸ļ��� 
int main()//ÿ������������Ҫ�޸ļ��� 
{
	freopen("����.txt","r",stdin);//ÿ������������Ҫ�޸ļ��� 
	char s[200]={0}; 
	while(gets(s)!=NULL)//��������� ÿ�����ʶ�������������ÿ�ζ���һ�У���Ҫ�Զ������м����ָ�������� 
	{
		if (ends(s)==1)
			continue;//��#��һ��
		//world�� hello 
		char *p=s;//p=!dlrow olleh\n
		while(*p!='\n')
		{
			//p����ո� 
			int flag=0;
			char string[100]={0};
			for(int i=0;*p!=' '&&*p!='\n';i++)
			{
				string[i]=*p; 
				p++;
				if (*p==' ')
				flag++;
			}
			//��ʱpָ��ո� 
			reverse(string);
			if (flag)//*p=' '������ѭ�� 
			printf("%s ",string);
			else//*p=='\n'ʱ������ѭ�� 
			printf("%s",string);
			if (*p=='\n')
			break;
			else
			p++; 
		 } 
		printf("\n"); //����������� 
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

