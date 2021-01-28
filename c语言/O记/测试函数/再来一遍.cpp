#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float findprice(char s[]); 
int main()
{
	char file[13][20];
	for(int i=0;i<13;i++)
		memset(file[i],0,30); 
	int i=0; //读入数据的行数 
	while(1)
	{
		gets(file[i]);
		if (strlen(file[i])==0) break; 
		i++;
	}
	printf("        #1 MT Takeaway\n");
	printf("\n");
	int length=strlen(file[0])+2;
	int linelength=(30-length)/2;   
	if (length%2) 
		{
			int m=0;
			for(;m<linelength;m++)
			{
				printf("-");
			}
			printf(" ");
			printf("%s",file[0]);
			printf(" ");
			int n=0;
			for(;n<=linelength;n++)
			{
				printf("-");
			}	
			printf("\n");
		}
		else
		{
			int m=0;
			for(;m<linelength;m++)
				printf("-");
			printf(" ");
			printf("%s",file[0]);
			printf(" ");
			int n=0;
			for(;n<linelength;n++)
				printf("-");
			printf("\n");
		}
		
		
		float total=0;
		int num=0;
		int j=1; //从第一个菜开始  Dried bean curd 13: file[j]
		while(j<i)
		{ 
			int o=strlen(file[j])-1;
		
			if (file[j][o-1]>='0'&&file[j][o-1]<='9')//两位数 
			{
				num+=(file[j][o]-'0')+(file[j][o-1]-'0')*10;
			}
			else
			{
				num=file[j][o]-'0';
			}
			
			
			int m1=0;
			for(;m1<20;m1++)
			{
				if (file[j][m1]>='a'&&file[j][m1]<='z'||file[j][m1]>='A'&&file[j][m1]<='Z')
				putchar(file[j][m1]);
				else
				putchar(' ');
			}
		
			char foodname[20]; 
			memset(foodname,'\0',20); 
			int q=0;
			while(1)
			{
				if (file[j][q]==' '&&!(file[j][q+1]>='a'&&file[j][q+1]<='z'))
					break; 
				else{
					foodname[q]=file[j][q];
				}
				q++;
			} 
			
			float price=findprice(foodname);
			total+=price*num; 
			
			printf("x");
			if(num>9)
			{
				printf("%d",num);
			}
			else
			{
				printf("%d",num);
				putchar(' ');
			}
			
			printf("%5.1f",num*price); 
			printf("\n");
			j++;
		} 
		
		printf("Delivery fees: 4\n");
		printf("------------------------------\n");
		int b=0;
		for(;b<16;b++)
		putchar(' ');
		printf("Total:%6.1f",total+4.0);
	return 0;
 } 


float findprice(char s[])
{
	if (strcmp(s,"Dried bean curd")==0)
		return 3.0;
	else if (strcmp(s,"Potato")==0)
		return 2.5;
	else if (strcmp(s,"Sauteed lettuce")==0)
		return 2.5;
	else if (strcmp(s,"Rice")==0)
		return 1.0;
	else if (strcmp(s,"Lotus root soup")==0)
		return 4.0;
	else if (strcmp(s,"Fried beef pepper")==0)
		return 7.0; 
}

















