#include <stdio.h> 
#include <string.h>//67%
int main()
{
	char string[300];
	freopen("data.txt","r",stdin);
	int times=0;
	int sit=0;//sit=0,��ʾ����ע����  
	int note2=0;//   ��//��ע�� 
	int next=1;
	while(gets(string)!=NULL)
	{
		
		if (strlen(string)==0)
		continue; 
		if (strcmp(string,"###")==0)
		{
			times++;
			if (times%2==0)
			{
				note2=0;
				sit=0;
			}
			continue;
		}
		char *p=string;
		while(*p)
		{
			if (*p=='/'&&*(p+1)=='/')
			{
				note2=1;
			}
			else if (*p=='/'&&*(p+1)=='*'||*p=='*'&&*(p+1)=='/')///*  
			{
				sit++;
				//˵��������/* ��Ҫ���string��/*ǰ����
				if (sit==1)
				{
					int output=0; 
					char *p2=string;
					while(*p2!='/'&&*(p2+1)!='*')
					{
						putchar(*p2);
						p2++;
						output++;
					}
					if (output!=0)
					printf("\n");
				}
			}
			p++;
			
			if (sit==2)
			{
				p++;//*p=='/'���һ��char 
				if (*p)//    */������������ 
				{
					while(*p)
					{
						putchar(*p);
						p++;
					 } 
				}
				
				//û�ַ��ˣ���Ϊ��ע�Ͳ��֣������� 
				sit=0;
				note2=0; 
				next=0;//  ����*/��һ�е������Ѿ���ȫ��� ������һ�� 
			}
		 } 
		 
		 if (next==0)
		 {
		 	next=1;
		 	continue;
		 }
		 
		 
		if(sit==0)//������/**/��ע���� ���string���� 
		{
		
			if (note2==1)//����//ע�� 
			{
				int output=0;
				char *p1=string;
				while(*p1)
				{
					if (*p1=='/')
					break;
					else
					putchar(*p1);
					p1++;
					output=1;
				}
				if (output==1)
				{
					printf("\n");
					output=0;
				}
			}
			else
			{
				puts(string);
			 } 
		}
	}
	return 0;
}
//
///* 
//
//1.// ֮����ʾ
//2./* ֮���״̬����ʾ
//3. /*֮ǰ������ʾ
//4.*/֮�������Ҫ��
//
//
//
//
//
//1.��һ�α���  �ǲ����ڴ�ע���У�ȷ����û�д�Сע�ͣ�û�� ���
//3.�ڴ�ע���У��������continue�����������ж�big��ֵ
//2.����Сע�ͣ�û�� ��ע�ͣ����ڴ�ע���У�ɾȥСע�ͣ����
//4.���ڴ�ע���У��д�ע�ͣ��������ע��ǰ�������ַ������жϴ�ע���Ƿ��ڱ��н������������
//�����ע�ͺ�����١������ٱ��н����������ñ�־big 
//
//
//
//
//
//���ӣ�
//int main()//dfsf
///* */{
//	
//int /*skdjajd*/x;
//
//int y=0;/*
//
//printf(zheshizhushi);
//dfgsdg*/    printf("%d\n",x+y);//����ע��
//
///*
//dfgsdg*/    printf("%d\n",x+y);/*asdas*/ int z; //dada 
///*
//dfgsdg*/    printf("%d\n",x+y);/*asdas
//asdad
//*/
//
//return 0; 
//
//} 
//
//1.�ж�һ�����ݱ����ú��������� ��������Ƕ�ף��õݹ��ж�*/֮��������Ƿ�Ϸ������Ϸ���Ҫ�ݹ����� 
// 
//dfgsdg*/    printf("%d\n",x+y);/*asdas*/ int z; /*asdas*/ int z; /*asdas*/ int z; /*asdas*/ int z; 
//*/
//

