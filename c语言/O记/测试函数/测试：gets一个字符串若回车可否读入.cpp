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
		printf("string的长度：%d\n",strlen(string)); //回车的时候，string的len就是0，可以用于判断是否需要继续输入 
}//事实证明，缓冲区存储的\n，并不会被gets读取，如果一直回车，读到的都是空字符
// 
	return 0;
}



























