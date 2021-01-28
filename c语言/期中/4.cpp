//输入一行数据
// 模式串为a个屏蔽词
//循环匹配a次， 
//每次对一行数据用BF算法匹配，如果匹配就说明含有屏蔽词，跳到下一次循环，不输出
// 总共循环读b次 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int match(char model[],char string[]);
int main() 
{
//	char model[]="xm";
//	char string[]="xml";
//	int flag=match(model,string);
//	printf("%d",flag);
freopen("data.txt","r",stdin);
	int a,b;
	while(1) 
	{
		if (scanf("%d %d",&a,&b)!=2)
		{
			printf("%d,%d\n",a,b);//仍然显示2，说明没有读入a,b 
			printf("end");
			break;
		}
//		else
//		printf("%d,%d\n",a,b);
		int flag=0;
		char model[20][100]={0};
		char string[400]={0};
		for(int i=0;i<a;i++)
		{
			scanf("%s",model[i]);//存入a个屏蔽词 
		}
		
		for(int i=0;i<b;i++)//读入b行需要匹配的string 
		{
			gets(string);
			for(int j=0;j<a;j++)//每个string都要和model匹配a次，意在找有没有包含这a个屏蔽词 
			{
				flag=match(model[j],string);
				if (flag==1)//若已经找到
				break; 
			}
			if (flag==1||strlen(string)==0)
			continue;
			else//正常结束，没有匹配成功
			{
				printf("%s\n",string);
			 } 
		}
	}

	return 0;
}
int match(char model[],char string[])
{
	int lenm=strlen(model);
	int lens=strlen(string);
	int flag=0;
	for(int i=0;i<lens;i++)
	{
		int oi=i;//匹配该次之前，先存放当前i的位置 
		for(int j=0;j<lenm;j++)
		{
			if (string[i]==model[j]||(string[i]>='a'&&string[i]<='z'&&string[i]==model[j]+32)||(string[i]>='A'&&string[i]<='Z'&&string[i]==model[j]-32))//这里增加AZaz判断即可加上大小写不区分 
			{
				i++;//j不要++，已经存在一个循环来控制j的变化 
				if (j==lenm-1)//成功匹配了lens次，说明存在 
				{
					flag=1;
				}
			}
			else//不匹配，i回到oi位置，++变成原来位置+1，重新匹配 
			{
				i=oi;
				break;
			 } 
		}
	}
	if (flag==1)
	return 1;
	else
	return 0;
	
}

 
