#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float findprice(char s[]);
int main()
{
	char storename[30];
	
	while(gets(storename)!=NULL)//����޷����뷵�ؿ�ָ�룬��ȷ���뷵��storename ���׵�ַ 
	{
		FILE *fp=fopen("data.txt","w+");//�����ļ� 
		freopen("data.txt","a+",fp);//׷��ģʽ
		printf("        #1 MT Takeaway\n");
		printf("\n");
		float total=0;
		char food[21];//20���ַ� ���� 
		int number[2];
		int num=0;
		int length=strlen(storename)+2;
		int linelength=(30-length)/2;
		if (length%2)//����,�Ҳ��һ�� 
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
		//���ˣ�ͷ�Ѿ���ϣ�������Ҫѭ�������� 
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
			num=number[0]+number[1]*10;//������ȡ 
			
			
			
			 
			for(int i=0;i<20;i++)//20
			{
				if (food[i]>='a'&&food[i]<='z'||food[i]>='A'&&food[i]<='Z')//���ǰ20���ַ�����food��� 
				putchar(food[i]);
				else//��ʱ������\0Ҳ��ӡ���ո��ܹ�20�� 
				putchar(' ');
			}
			//��������û������

			//food=Dried bean curd 1\0
			//Ҫ��ȡDried bean curd
			char foodname[18]; 
			memset(foodname,'\0',18); //һ��Ҫ�ǵ����������Ӱ���´�ѭ�� 
			int i=0;
			while(1)
			{
				if (food[i]==' '&&!(food[i+1]>='a'&&food[i+1]<='z'))
				{
					break;
				}
				else{//�����Rice  foodname �ͻ��� Rice ����ո� 
					foodname[i]=food[i];
				}
				i++;
			}//�Ӵ� foodname���food 
			float price=findprice(foodname);//�����bug����ȥ��food�еĺ������ֺͿո�
			
			total+=price*num;//numû���⣬food�Ѿ���ӡ������û���⣬��Ҫ�Ǽ۸� 
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
			//n*price  5λ  113.5  11.2  1.2    0  1.2  
			printf("%-5.1f",num*price);//����� 
			printf("\n");
			memset(food,' ',20);
		}//ȫ��������� 
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
