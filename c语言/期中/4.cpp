//����һ������
// ģʽ��Ϊa�����δ�
//ѭ��ƥ��a�Σ� 
//ÿ�ζ�һ��������BF�㷨ƥ�䣬���ƥ���˵���������δʣ�������һ��ѭ���������
// �ܹ�ѭ����b�� 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int match(char model[],char string[]);
int main() 
{
//	char model[]="xm";
//	char string[]="xml";
//	int flag=match(model,string);
//	printf("%d",flag);
freopen("data.txt","r",stdin);
	int a,b;
	while(1) 
	{
		if (scanf("%d %d",&a,&b)!=2)
		{
			printf("%d,%d\n",a,b);//��Ȼ��ʾ2��˵��û�ж���a,b 
			printf("end");
			break;
		}
//		else
//		printf("%d,%d\n",a,b);
		int flag=0;
		char model[20][100]={0};
		char string[400]={0};
		for(int i=0;i<a;i++)
		{
			scanf("%s",model[i]);//����a�����δ� 
		}
		
		for(int i=0;i<b;i++)//����b����Ҫƥ���string 
		{
			gets(string);
			for(int j=0;j<a;j++)//ÿ��string��Ҫ��modelƥ��a�Σ���������û�а�����a�����δ� 
			{
				flag=match(model[j],string);
				if (flag==1)//���Ѿ��ҵ�
				break; 
			}
			if (flag==1||strlen(string)==0)
			continue;
			else//����������û��ƥ��ɹ�
			{
				printf("%s\n",string);
			 } 
		}
	}

	return 0;
}
int match(char model[],char string[])
{
	int lenm=strlen(model);
	int lens=strlen(string);
	int flag=0;
	for(int i=0;i<lens;i++)
	{
		int oi=i;//ƥ��ô�֮ǰ���ȴ�ŵ�ǰi��λ�� 
		for(int j=0;j<lenm;j++)
		{
			if (string[i]==model[j]||(string[i]>='a'&&string[i]<='z'&&string[i]==model[j]+32)||(string[i]>='A'&&string[i]<='Z'&&string[i]==model[j]-32))//��������AZaz�жϼ��ɼ��ϴ�Сд������ 
			{
				i++;//j��Ҫ++���Ѿ�����һ��ѭ��������j�ı仯 
				if (j==lenm-1)//�ɹ�ƥ����lens�Σ�˵������ 
				{
					flag=1;
				}
			}
			else//��ƥ�䣬i�ص�oiλ�ã�++���ԭ��λ��+1������ƥ�� 
			{
				i=oi;
				break;
			 } 
		}
	}
	if (flag==1)
	return 1;
	else
	return 0;
	
}

 
