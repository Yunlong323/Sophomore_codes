#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char string[20];
	//while(strcmp(string,"\n")!=0)
	while(1)
	{
		gets(string);
		if(strlen(string)==0) break;
		puts(string);
		printf("string�ĳ��ȣ�%d\n",strlen(string)); //�س���ʱ��string��len����0�����������ж��Ƿ���Ҫ�������� 
}//��ʵ֤�����������洢��\n�������ᱻgets��ȡ�����һֱ�س��������Ķ��ǿ��ַ�
// 
	return 0;
}



























