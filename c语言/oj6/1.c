#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct info{
	char content[10];
	int times;
}info;

int in(char auxilary[],info list[],int listlen)
{
	int i; 
	for(i=0;i<listlen;i++)
	{
		if (strcmp(auxilary,list[i].content)==0)
		{
			return 1;
		}
	}
	return -1;//否则，不存在
}
void join(char *auxilary,int listlen,info list[])
{
	strcpy(list[listlen].content,auxilary);
	list[listlen].times=1;
}

int main()
{
	//freopen("data.txt","r",stdin);
	char string[1005]={0};
	while(gets(string)!=NULL)
	{
		info list[100]={{0},0};
		char auxilary[10]={0};
		char *p=string;
		int listlen=0;
		
		int times=0;
		while(*p) //直到遍历完这组数据
		{
			times++;
			int i=0;
			while(*p!=' '&&*p!=0)//每次都存入一个单词 到auxilary
			{
				auxilary[i]=*p;
				i++;
				p++;
			}//最后p指向空或0 
			//meng haha haha kaka kaka

			
			int flag=in(auxilary,list,listlen);
			if (flag!=-1)//说明这次读入的auxilary已在里面
			{
				list[listlen-1].times++;//对应索引位置的次数++
			}
			else //不在，新加入
			{
				join(auxilary,listlen,list);
				listlen++;
			}
			
			if (*p==0)
			break;
			else
			p++;
		}//此时遍历完整个数据
		
		int i,j;
		for(i=0;i<listlen-1;i++)//先对字符进行排序
		 {
		 	for(j=0;j<listlen-i;j++)
		 	{
		 		if (strcmp(list[j].content,list[j+1].content)<0)
		 		{                                            
		 			info temp=list[j];
		 			list[j]=list[j+1];
		 			list[j+1]=temp;
				 }
			 }
		  }
		 
		int m=0,n=0;
		for(m=0;m<listlen-1;m++)//再对数字进行排序，利用冒泡排序的稳定性
		{
			for(n=0;n<listlen-m;n++)
			{
				if (list[n].times<list[n+1].times)//不能是<=，等于会破坏稳定性
				{
					info temp=list[n];
					list[n]=list[n+1];
					list[n+1]=temp;
				}
			}
		 }
		
		int a;
		for(a=0;a<listlen;a++)
		{
			if (a==0)
			printf("%s(%d)",list[a].content,list[a].times);
			else
			printf(" %s(%d)",list[a].content,list[a].times);
		}
		printf("\n");
	}
	
	return 0;
}
