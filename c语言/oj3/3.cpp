#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int stunum=0;
	scanf("%d",&stunum);
	int num=1;
	while(num<=stunum)
	{
		char info[200];
		gets(info);
		char *p=info;
		int judge=0;
		for(p+=2;*p;)//�����⣬�����judgeЭ��һ��
		{//4 abc def 3dh hi!
			char *pp=p;
			for(;*pp!=' '||*pp;pp++)//pָ��a,d,3,h��Ԫ�أ�pp��ʼ��abc������� 
			{
				if (pp-p==0&&!(*pp>='a'&&*pp<='z'||*pp>='A'&&*pp<='Z'||*pp=='_'))//��һ���ַ��Ƿ�Ϸ�
					judge++;//abc ȫ���Ϸ������� 
				else if (pp-p!=0&&!(*pp>='a'&&*pp<='z'||*pp>='A'&&*pp<='Z'||*pp=='_'||*p>='0'&&*p<='9'))//���ǵ�һ�� ��
					judge++;//������ĸ�жϣ��ǵ������Ӹ����� 
			}//����ʱ��*ppΪ�ո� ��p��ʱͬpp������p++,��һ��pָ��������d 
			if (!judge&&p-info==2)//��һ���ַ����ж� 
				printf("0");
			else if (!judge&&p-info!=2)
				printf(" 0");
			else if (judge!=0&&p-info==2) //��һ���ַ����ж� 
				printf("1");
			else if (judge!=0&&p-info!=2) 
				printf(" 1");
			p=pp;//��ʱp������Ϊ�ո� 
			if (*p)
			p++;//������ǿգ������Ƶ�����ĸ 
		}
		printf("\n");
		num++;
	}
	return 0;
}
