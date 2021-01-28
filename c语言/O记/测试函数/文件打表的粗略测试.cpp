#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float findprice(char s[]); 
int main()
{
	char storename[30];
	char file[13][20];
	for(int i=0;i<13;i++)
		memset(file[i],0,30); 

	gets(storename);
		char food[21]; 
		int i=0; 
		while(1)
		{
			gets(food);
			if (strlen(food)==0) break; 
			strcpy(file[i],food);
			i++;
		}
	
		
	printf("        #1 MT Takeaway\n");
	printf("\n");
	
		int length=strlen(storename)+2;
		int linelength=(30-length)/2;
		if (length%2)
		{
			for(int m=0;m<linelength;m++)
			{
				printf("-");
			}
			printf(" ");
			printf("%s",storename);
			printf(" ");
			for(int m=0;m<=linelength;m++)
			{
				printf("-");
			}	
			printf("\n");
		}
		else
		{
			for(int m=0;m<linelength;m++)
				printf("-");
			printf(" ");
			printf("%s",storename);
			printf(" ");
			for(int m=0;m<linelength;m++)
				printf("-");
			printf("\n");
		} 
		float total=0;
		int number[2];
		int num=0;

		int j=0;
		while(j<i)
		{ 
			for(int i=strlen(file[j])-1;i>=strlen(file[j])-2;i--)
			{
				if (file[j][i]>='0'&&file[j][i]<='9')
				number[strlen(file[j])-i-1]=file[j][i]-'0';
				else
				number[strlen(file[j])-i-1]=0;
			}
			num=number[0]+number[1]*10;
			
			for(int i=0;i<20;i++)
			{
				if (file[j][i]>='a'&&file[j][i]<='z'||file[j][i]>='A'&&file[j][i]<='Z')
				putchar(file[j][i]);
				else
				putchar(' ');
			}
		
			char foodname[20]; 
			memset(foodname,'\0',20); 
			int i=0;
			while(1)
			{
				if (file[j][i]==' '&&!(file[j][i+1]>='a'&&file[j][i+1]<='z'))
					break; 
				else{
					foodname[i]=file[j][i];
				}
				i++;
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
			memset(food,' ',21);
			j++;
		} 

		printf("Delivery fees: 4\n");
		printf("------------------------------\n");
		
		for(int i=0;i<16;i++)
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
