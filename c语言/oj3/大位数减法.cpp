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
			result[j]=a[i]-b[lenb];//倒着存结果 
			lenb--;
			j++;
			if (lenb<0&&i>0)//lenb先到0 
			result[j]=a[i]-'0';
			else if (i==0&&lenb>=0)//b 还有值
			result[j]=0-(b[i]-'0');
			else if (lenb==-1&&i==0)//同时结束
			break; 
		}//j-1就是有效索引 
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
	//先确定正负 
	int flag=0;
	if (sign==0)//结果为正 
	{
		
	}
	else if (sign==1)//结果为负 
	{
		for(int i=len-1;i>=0;i--)
		{
			if (flag==1)//说明本位是正的，可以借位
			{
				result[i]-=1;
				flag=0;
			 } 
			 else
			 {
			 	if (result)
			 }
			if (result[i]<0)//说明有借位
			{
				if (result[i-1]<=0)
				{
					flag=-1;//标志，前一位借位是负数/0
					result[i]=-result[i]; 
				}
				else//有借位，但是前一位是正的
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
	else//a,b位数一样，比较大小 
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

