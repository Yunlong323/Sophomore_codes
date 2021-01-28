#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int num_of_hw=0;
	//freopen("data.txt","r",stdin); 
	while(scanf("%d",&num_of_hw)==1)
	{
		for(int j=0;j<num_of_hw;j++)
		{
			int num=0;
			scanf("%d",&num);
			for(int i=0;i<num;i++)
			{
				char string[100];
				scanf("%s",string);
				int flag=0;
				char *p=string;
				if (!(*p=='_'||*p>='A'&&*p<='Z'||*p>='a'&&*p<='z'))//第一个字符是否合法 
				{
					if (i==0) 
						printf("0");
					else
						printf(" 0");
					continue;
				}
				else//之后的字符合法 
				{
					while(*p)
					{
						if (!(*p=='_'||*p>='0'&&*p<='9'||*p>='A'&&*p<='Z'||*p>='a'&&*p<='z'))
						{
							flag=1;
							break;
						}
						p++;
					}
				
						if (flag==1)
						{
							if (i==0)
								printf("0");
							else 
								printf(" 0");
						}	
						else//flag==0 说明没有不合法的 
						{
							if (i==0)
								printf("1");
							else
								printf(" 1");
						}
					
				}
			}
			printf("\n");
		 } 
	}
	return 0;
 } 
