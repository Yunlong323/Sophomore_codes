#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char D[10][5]={{0},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','Q','R','S'},{'T','U','V'},{'W','X','Y','Z'}}; 
int isdigit(char a)
{
	if (a>='0'&&a<='9')
		return 1;
	else if (a>='a'&&a<='z')
		return 2;
	else if (a>='A'&&a<='Z')
		return 3;
	else 
		return 0;
}
int main()
{
	char str[55];
	while(scanf("%[^-]",str)==1)
	{
		int flag1=0;
		int flag2=0;
		char *p=str;
		while(*p)
		{
			if (isdigit(*p)==1)
				flag1=1;
			else 
				flag2=1;
			p++; 
		}
		if (flag1==1&&flag2==0) //˵��ֻ������
		printf("%s",str); 
		else if (flag1==0&&flag2==1)//ֻ���ַ� 
		
		else //�������������ַ� ����ֱ��������ַ�ת��Ϊ������� 
		
		
		
//800-45D6-dE3
	}
	return 0;
}
