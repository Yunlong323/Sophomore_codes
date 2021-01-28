#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct num{
	char string[15];
	char number[15];
	int numberlen;
}num;
int main()
{
	freopen("data.txt","r",stdin);
	int i=0;
	num list[205]={{0},{0},0};
	while(scanf("%s",list[i].string)==1)//共i-1组数据 
	{
		
		int len=strlen(list[i].string);//Vzs56aA  7
		char *p=list[i].string;
		
		for(int j=len-1;*p!=0&&j>=0;j--,p++)//共有j个数据 
		{
			if (*p>='0'&&*p<='9')
			{
				list[i].number[j]=*p-'0';//直接用ascii码比较 
				list[i].numberlen++;
			}

			else if (*p>='a'&&*p<='z')
			{
				list[i].number[j]=*p-97;//25
				if (*p-97>=10)
				list[i].numberlen+=2; 
				else
				list[i].numberlen++;
			}
		
			else if (*p>='A'&&*p<='Z')
			{
				list[i].number[j]=*p-65;
				if (*p-65>=10)
				list[i].numberlen+=2; 
				else
				list[i].numberlen++;
			}
		}//由此，第一个字符串就已经完全存入并转化好了 
		i++;
	}//i个数据 
	
	
	
	//冒泡排序稳定性，为了让同等长度的先出现先打印，现在正是先出现在前，所以只需要冒泡排长度，排大小即可
	for(int m=0;m<i-1;m++)
	for(int l=0;l<i-1-m;l++)
	{
		if (list[l].numberlen<list[l+1].numberlen)
		{
			num temp=list[l];
			list[l]=list[l+1];
			list[l+1]=temp;
		}
	 } //排大小 
	 
	 
	 
	for(int m=0;m<i-1;m++)
	for(int l=0;l<i-1-m;l++)//左小  右大 
	{
		if (list[l].numberlen<=list[l+1].numberlen&&strcmp(list[l].number,list[l+1].number)<0)//同等长度比较 
		{
			num temp=list[l];
			list[l]=list[l+1];
			list[l+1]=temp;
		}
	 } //拍长度 
	
	for(int b=0;b<i;b++)
	{
		if (b==0)
		printf("%s,len:%d",list[b].string,list[b].numberlen);
		else
		printf(" %s,len:%d",list[b].string,list[b].numberlen);
	 }
	 printf("\n"); 
	
	return 0;
}

