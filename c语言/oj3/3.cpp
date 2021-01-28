#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int stunum=0;
	scanf("%d",&stunum);
	int num=1;
	while(num<=stunum)
	{
		char info[200];
		gets(info);
		char *p=info;
		int judge=0;
		for(p+=2;*p;)//有问题，必须和judge协调一下
		{//4 abc def 3dh hi!
			char *pp=p;
			for(;*pp!=' '||*pp;pp++)//p指向a,d,3,h首元素，pp开始对abc进行审查 
			{
				if (pp-p==0&&!(*pp>='a'&&*pp<='z'||*pp>='A'&&*pp<='Z'||*pp=='_'))//第一个字符是否合法
					judge++;//abc 全部合法，不走 
				else if (pp-p!=0&&!(*pp>='a'&&*pp<='z'||*pp>='A'&&*pp<='Z'||*pp=='_'||*p>='0'&&*p<='9'))//不是第一个 ，
					judge++;//非首字母判断，非的条件加个数字 
			}//结束时，*pp为空格 ，p此时同pp，由于p++,下一轮p指的内容是d 
			if (!judge&&p-info==2)//第一个字符的判断 
				printf("0");
			else if (!judge&&p-info!=2)
				printf(" 0");
			else if (judge!=0&&p-info==2) //第一个字符的判断 
				printf("1");
			else if (judge!=0&&p-info!=2) 
				printf(" 1");
			p=pp;//此时p的内容为空格 
			if (*p)
			p++;//如果不是空，就下移到首字母 
		}
		printf("\n");
		num++;
	}
	return 0;
}
