#include <stdio.h>
#define N 20 
#include <stdlib.h> 
#include <string.h> 

int main()
{
	int A1[N];
	int A2[N];
	char n1[N];
	char n2[N];
//���19+19,�õ�20λ���� 
	memset(n1,'\0',sizeof(n1));
	memset(n2,'\0',sizeof(n2));
	memset(A1,0,sizeof(A1));
	memset(A2,0,sizeof(A2));
//�ֱ��ʼ�� ����0Ϊ�˱��ڽ��� 
	while(scanf("%s %s",n1,n2)!=EOF)
	{
		int len1=strlen(n1);
	int len2=strlen(n2);
	int maxlen=len1>len2?len1:len2; 
//�õ����Եĳ��ȣ����ڱ���������������
//��¼maxlen���Ǽӵ������� 
	int k=0;
//k���ڴ��char��������������ȡ�� 
	for(int i=N-len1;i<=N-1;i++)
	{
		A1[i]=n1[k++]-'0';
	}
//�ܹ���len1�����֣�Ʃ��123  3  i��20-3=17��ʼ��17 18 19 ��� 1  2   3 

//���ʱlen2  ����12  ��20-2=18��ʼ 18 19���1 2	
 
	
//���Ŵ�����ֱ��ڴ���ļ��㣬��˴洢
//0000123
//0000012����ֱ�Ӽӣ�����Ҫ��λ�����С�˴洢������

//123
//12��Ӳ�û�ж�����λ 
	k=0;
//����Ϊ0����ڶ������� 
	for(int i=N-len2;i<=N-1;i++)
	{
		A2[i]=n2[k++]-'0';
	}
//��ʱA1[],A2[] ��δ��������part����0 
	int i=N-1;
//i�������һ����������λ��	

	
	for(;i>=N-maxlen;i--)//�Ӹ�λ��ʼ�ӣ�һֱ�����λ��N-maxlen��20-3=17�� 
	{
		A1[i]+=A2[i];
		if (A1[i]>=10)//��λ��Сλ+1,��λ-10 
		{
			A1[i-1]+=1; //������2��19��9��� ����ôA1[0]�ͻ���1������û���� 
			A1[i]-=10;
		}
	}
	int count=0;//count���ڱ�־0�������δ������λ����0Ӧ����������������λ�е�Ӧ���������� 
	for(int j=0;j<N;j++)
	{
		if (A1[j]==0&&count==0) //��0�����������Ŷ���һ������ 
		{
			continue;
		}
		else
		{
			count++;
			printf("%d",A1[j]);
		}
	}	
	if (count==0)
	{
		printf("0\n");//˵��0+0=0�� 
	}
	else
	{
		printf("\n"); 
	}
	memset(n1,'\0',sizeof(n1));
	memset(n2,'\0',sizeof(n2));
	memset(A1,0,sizeof(A1));
	memset(A2,0,sizeof(A2));
	}
	
 return 0;
}
