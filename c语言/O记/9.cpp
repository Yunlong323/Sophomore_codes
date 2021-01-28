#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float findprice(char s[]);
int main()
{
	char storename[30];
	
	while(gets(storename)!=NULL)//如果无法读入返回空指针，正确读入返回storename 的首地址 
	{
		FILE *fp=fopen("data.txt","w+");//创建文件 
		freopen("data.txt","a+",fp);//追加模式
		printf("        #1 MT Takeaway\n");
		printf("\n");
		float total=0;
		char food[21];//20个字符 菜名 
		int number[2];
		int num=0;
		int length=strlen(storename)+2;
		int linelength=(30-length)/2;
		if (length%2)//奇数,右侧多一个 
		{
			for(int i=0;i<linelength;i++)
			{
				printf("-");
			}
			printf(" ");
			printf("%s",storename);
			printf(" ");
			for(int i=0;i<=linelength;i++)
			{
				printf("-");
			}	
			printf("\n");
		}
		else
		{
			for(int i=0;i<linelength;i++)
				printf("-");
			printf(" ");
			printf("%s",storename);
			printf(" ");
			for(int i=0;i<linelength;i++)
				printf("-");
			printf("\n");
		}
		//至此，头已经完毕，下面是要循环的内容 
		while(gets(food)!=NULL)
		{//scanf("%s %d",food,num)!=EOF 
			// rice  strlen()==4  
			for(int i=strlen(food)-1;i>=strlen(food)-2;i--)
			{
				if (food[i]>='0'&&food[i]<='9')
				number[strlen(food)-i-1]=food[i]-'0';//12   0-2  1-1
				else
				number[strlen(food)-i-1]=0;//2   0-2  1-0
			}
			num=number[0]+number[1]*10;//数量获取 
			
			
			
			 
			for(int i=0;i<20;i++)//20
			{
				if (food[i]>='a'&&food[i]<='z'||food[i]>='A'&&food[i]<='Z')//输出前20个字符，把food输出 
				putchar(food[i]);
				else//及时遇到了\0也打印出空格，总共20个 
				putchar(' ');
			}
			//以上内容没有问题

			//food=Dried bean curd 1\0
			//要获取Dried bean curd
			char foodname[18]; 
			memset(foodname,'\0',18); //一定要记得清除，否则影响下次循环 
			int i=0;
			while(1)
			{
				if (food[i]==' '&&!(food[i+1]>='a'&&food[i+1]<='z'))
				{
					break;
				}
				else{//如果是Rice  foodname 就会变成 Rice 多个空格 
					foodname[i]=food[i];
				}
				i++;
			}//从此 foodname替代food 
			float price=findprice(foodname);//这里的bug在于去掉food中的后面数字和空格。
			
			total+=price*num;//num没问题，food已经打印出来，没问题，主要是价格 
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
			//n*price  5位  113.5  11.2  1.2    0  1.2  
			printf("%-5.1f",num*price);//左对齐 
			printf("\n");
			memset(food,' ',20);
		}//全部输入完毕 
		printf("Delivery fees: 4\n");
		printf("------------------------------\n");
		for(int i=0;i<15;i++)
		putchar(' ');
		printf("Total:%-6.1f",total+4.0);
	}
	return 0;
}
float findprice(char s[])
{
	if (strcmp(s,"Dried bean curd")==0)
		return 3.0;
	if (strcmp(s,"Potato")==0)
		return 2.5;
	if (strcmp(s,"Sauteed lettuce")==0)
		return 2.5;
	if (strcmp(s,"Rice")==0)
		return 1.0;
	if (strcmp(s,"Lotus root soup")==0)
		return 4.0;
	if (strcmp(s,"Fried beef pepper")==0)
		return 7.0;
}
