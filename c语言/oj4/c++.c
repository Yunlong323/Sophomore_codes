#include <stdio.h>
#include <string.h>
int main()
{
	freopen("data.txt","r",stdin); 
	char string[20][100]={0};
	int i=0,num=i;
	int k=0;
	int j=0; 
	while(gets(string[i]))
	{
		if(strlen(string[i])==0)
		break;
		i++;
	}
	num=i;
	for(k=0;k<=num-1;k++)
	{
		for(i=0;i<=num-1;i++)
		{
			if(strcmp(string[i],string[i+1])==1)
			{
				for(j=0;string[i][j]!=0||string[i+1][j]!=0;j++)
				{
					char temp=0;
					temp=string[i][j];
					string[i][j]=string[i+1][j];
					string[i+1][j]=temp;
				}
			}
		}
	}

	for(i=0;i<=num-1;i++)
	{
		printf("%s",string[i]);
		if(i!=0)
		printf("\n");
	}
	printf("%s",string[i]);
	
	return 0;
}


