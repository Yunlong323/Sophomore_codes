#include <stdio.h>
int main()
{
	char s;
	int a,b,c;
	scanf("%d%d%c%d",&a,&b,&s,&c);//输入 336 332\n32 
	printf("%d",s);//如果是 10，就说明没有读入字符，直接跳过到\n，如果是32就说明没有跳过空格字符 
	return 0;// 结果是读入10  
}
