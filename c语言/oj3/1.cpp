#include <stdio.h>
int main()
{
	//freopen("oj1.txt","r",stdin); 
	int ch;
	int line=0;
	while((ch=getchar())!=EOF)
	{
		int flag=1;	//标志读到# 
		while(flag!=2)//读到第二个#说明本次循环结束 
		{
			ch=getchar();
			if (ch=='\n')//读到换行符，判断下一个是不是空格 
			{
				if ((ch=getchar())!=' '&&ch!=10&&ch!='#')//不是空格和起始结束符#就加1 
				line++;//漏洞在于：asdasdl\n  \n   dadas\n时，读到第一个\n，ch再读下一个仍是\n， 
				if (ch==10) 
			}//于是下次循环开始chgetchar就会变到dadas，从而少加一行 
			if (ch=='#')//因为刚才读到\n，需要判断当前是不是#这关系到下次要不要循环 
			flag++;
			if	(flag==2)//如果现在已经加到了2，就可以对一些标志量初始化 
			{
				flag=0;
				printf("%d\n",line);
				line=0;
			//fflush(stdin);
			}
		}
	}
	return 0;
}
