#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void	reverse(int *result,int len);
void	jinwei(int *result,int len,int sign);
int sign(char a[],char b[]);
void	print(int *result,int len);
int main()
{
	char a[105],b[105];
	while(scanf("%s%s",a,b==2))
	{
		int lena=strlen(a);
		int lenb=strlen(b); 
		int result[105]={0};
		int j=0;
		for(int i=lena;i>=0;i--)
		{
			result[j]=a[i]-b[lenb];//���Ŵ��� 
			lenb--;
			j++;
			if (lenb<0&&i>0)//lenb�ȵ�0 
			result[j]=a[i]-'0';
			else if (i==0&&lenb>=0)//b ����ֵ
			result[j]=0-(b[i]-'0');
			else if (lenb==-1&&i==0)//ͬʱ����
			break; 
		}//j-1������Ч���� 
		reverse(result,j);//
		jinwei(result,j,sign(a,b));
		print(result,j);
		
		memset(a,0,105);
		memset(b,0,105);
	}
	return 0;
}

void	reverse(int *result,int len)
{
	for(int i=0;i<len/2;i++)
	{
		int temp=result[i];
		result[i]=result[len-i-1];
		result[len-i-1]=temp;
	}
}
void	jinwei(int *result,int len,int sign)
{
	//��ȷ������ 
	int flag=0;
	if (sign==0)//���Ϊ�� 
	{
		
	}
	else if (sign==1)//���Ϊ�� 
	{
		for(int i=len-1;i>=0;i--)
		{
			if (flag==1)//˵����λ�����ģ����Խ�λ
			{
				result[i]-=1;
				flag=0;
			 } 
			 else
			 {
			 	if (result)
			 }
			if (result[i]<0)//˵���н�λ
			{
				if (result[i-1]<=0)
				{
					flag=-1;//��־��ǰһλ��λ�Ǹ���/0
					result[i]=-result[i]; 
				}
				else//�н�λ������ǰһλ������
				{
					flag=1;
					result[i]=-result[i];
				 } 
			 } 
		 } 
	}
}
void	print(int *result,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d",result[i]);
	}
	printf("\n");
}
int sign(char a[],char b[])//0 +    1 - 
{
	int flag=0;
	int lena=strlen(a);
	int lenb=strlen(b);
	if (lena>lenb)
	return 0;
	else if (lena<lenb)
	return 1;
	else if (a[0]>b[0])
	return 0;
	else if (a[0]<b[0])
	return 1;
	else//a,bλ��һ�����Ƚϴ�С 
	{
		for(int i=0;i<lena;i++)
		{
			if (a[i]==b[i]) 
				continue;
			else if (a[i]>b[i])
				return 0;
			else
				return 1;
		}
	}
}

