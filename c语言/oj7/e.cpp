#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct student{
	char name[105];
	int times;
}student;
int main()
{
//	freopen("data.txt","r",stdin);
	int num=0;
	while(scanf("%d",&num)==1)
	{
		//fflush(stdin);
	
		if (num==0)
		break;
			getchar(); 
		student list[1000]={{0},0};
		
		int count=0;//����num��Ԫ�� 
		int i=0;//��¼���ظ����ַ������� 
		
		for(i=0,count=0;count<num;count++)
		{
			char temp[105]={0};
			int flag=0;
			gets(temp);
			for(int j=0;j<i;j++)//j<i����Ϊ�˱����Ѿ����ڵ�i������ 
			{
				if (strcmp(temp,list[j].name)==0)//�Ѿ��У�ֱ��++���� 
				{
					list[j].times++;
					flag++;
					break; 
				}
			}
			if (flag==0)//˵��û��++�� ֱ�Ӽ��� 
			{
				strcpy(list[i].name,temp); 
				i++;
			}
			
		}
		int maxindex=0;
		int max=0;
		for(int q=0;q<i;q++)
		{
			if (list[q].times>=max)
			{
				max=list[q].times;
				maxindex=q;
			}
		}
		printf("%s\n",list[maxindex].name);
	}
	return 0;
 } 
