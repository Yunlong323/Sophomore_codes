#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float findprice(char s[]); 
int main()
{
	char storename[30];
	char file[13][20];
	int k=0; 
	for(;k<13;k++)
		memset(file[k],0,30); 

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
			int q=0;
			for(;q<linelength;q++)
			{
				printf("-");
			}
			printf(" ");
			printf("%s",storename);
			printf(" ");
			int b=0;
			for(;b<=linelength;b++)
			{
				printf("-");
			}	
			printf("\n");
		}
		else
		{
			int c=0;
			for(;c<linelength;c++)
				printf("-");
			printf(" ");
			printf("%s",storename);
			printf(" ");
			int z=0;
			for(;z<linelength;z++)
				printf("-");
			printf("\n");
		} 
		float total=0;
		int number[2];
		int num=0;

		int j=0;
		while(j<i)
		{ 
			int w=strlen(file[j])-1;
			for(;w>=strlen(file[j])-2;w--)
			{
				if (file[j][w]>='0'&&file[j][w]<='9')
				number[strlen(file[j])-w-1]=file[j][w]-'0';
				else
				number[strlen(file[j])-w-1]=0;
			}
			num=number[0]+number[1]*10;
			
			int s=0;
			for(;s<20;s++)
			{
				if (file[j][s]>='a'&&file[j][s]<='z'||file[j][s]>='A'&&file[j][s]<='Z')
				putchar(file[j][s]);
				else
				putchar(' ');
			}
		
			char foodname[20]; 
			memset(foodname,'\0',20); 
			int h=0;
			while(1)
			{
				if (file[j][h]==' '&&!(file[j][h+1]>='a'&&file[j][h+1]<='z'))
					break; 
				else{
					foodname[h]=file[j][h];
				}
				h++;
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
		
		int o=0;
		for(;o<16;o++)
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
