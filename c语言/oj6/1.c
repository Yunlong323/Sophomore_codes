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
	return -1;//���򣬲�����
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
		while(*p) //ֱ����������������
		{
			times++;
			int i=0;
			while(*p!=' '&&*p!=0)//ÿ�ζ�����һ������ ��auxilary
			{
				auxilary[i]=*p;
				i++;
				p++;
			}//���pָ��ջ�0 
			//meng haha haha kaka kaka

			
			int flag=in(auxilary,list,listlen);
			if (flag!=-1)//˵����ζ����auxilary��������
			{
				list[listlen-1].times++;//��Ӧ����λ�õĴ���++
			}
			else //���ڣ��¼���
			{
				join(auxilary,listlen,list);
				listlen++;
			}
			
			if (*p==0)
			break;
			else
			p++;
		}//��ʱ��������������
		
		int i,j;
		for(i=0;i<listlen-1;i++)//�ȶ��ַ���������
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
		for(m=0;m<listlen-1;m++)//�ٶ����ֽ�����������ð��������ȶ���
		{
			for(n=0;n<listlen-m;n++)
			{
				if (list[n].times<list[n+1].times)//������<=�����ڻ��ƻ��ȶ���
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
