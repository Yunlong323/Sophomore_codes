#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	//freopen("data.txt","r",stdin);
	char string[100];
	while(gets(string)) 
	{
		if (strlen(string)==0)
		break;
		int ISBN[10]={0};
		ISBN[0]=string[0]-'0';
		ISBN[1]=string[2]-'0';
		ISBN[2]=string[3]-'0';
		ISBN[3]=string[4]-'0';
		ISBN[4]=string[6]-'0';
		ISBN[5]=string[7]-'0';
		ISBN[6]=string[8]-'0';
		ISBN[7]=string[9]-'0';
		ISBN[8]=string[10]-'0';//存好了 
		if (string[12]=='X') 
		ISBN[9]=-1;
		else
		ISBN[9]=string[12]-'0';
		
		int sum=0;
		for(int i=0;i<9;i++)
		{
			sum=sum+ISBN[i]*(i+1);
		} 
		sum%=11;//sum中必然是正确的末尾结果 
		
		if (sum==ISBN[9])//算对了,一定不是10的情况 
		printf("Right\n");
		else if (sum==10&&ISBN[9]==-1)//算对了,是10的情况 
		{
			printf("Right\n");
		}
		else if (ISBN[9]!=-1&&sum==10)//算错了而且末尾是10 
		{
			for(int i=0;i<=9;i++)
			{
				if (i==1||i==4||i==9)
				{
					if (i!=9)
					{
						printf("-"); 
						printf("%d",ISBN[i]) ;
					}
					else
					{
						printf("-X");
					}
				}
				else
				{
					printf("%d",ISBN[i]);
				 } 
			}
			printf("\n");	
		 }
		 else if (sum!=ISBN[9]&&sum!=10)//只是算错了 
		 {
		 	ISBN[9]=sum;
			for(int i=0;i<=9;i++)
			{
				if (i==1||i==4||i==9)
				{
					printf("-"); 
					printf("%d",ISBN[i]) ;
				}
				else
				{
					printf("%d",ISBN[i]);
				 } 
			}
			printf("\n");
		  } 
		
	}
	return 0;
} 
