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
//最高19+19,得到20位整数 
	memset(n1,'\0',sizeof(n1));
	memset(n2,'\0',sizeof(n2));
	memset(A1,0,sizeof(A1));
	memset(A2,0,sizeof(A2));
//分别初始化 ，置0为了便于结束 
	while(scanf("%s %s",n1,n2)!=EOF)
	{
		int len1=strlen(n1);
	int len2=strlen(n2);
	int maxlen=len1>len2?len1:len2; 
//得到各自的长度，便于遍历存入整数数组
//记录maxlen就是加的最大次数 
	int k=0;
//k用于存放char数的索引，用于取数 
	for(int i=N-len1;i<=N-1;i++)
	{
		A1[i]=n1[k++]-'0';
	}
//总共有len1个数字，譬如123  3  i从20-3=17开始，17 18 19 存放 1  2   3 

//如果时len2  就是12  从20-2=18开始 18 19存放1 2	
 
	
//倒着存放数字便于待会的计算，大端存储
//0000123
//0000012可以直接加，不需要移位，如果小端存储不方便

//123
//12相加并没有对齐数位 
	k=0;
//重置为0，存第二个加数 
	for(int i=N-len2;i<=N-1;i++)
	{
		A2[i]=n2[k++]-'0';
	}
//此时A1[],A2[] 的未填入数字part都是0 
	int i=N-1;
//i就是最后一个索引（个位）	

	
	for(;i>=N-maxlen;i--)//从个位开始加，一直到最高位，N-maxlen（20-3=17） 
	{
		A1[i]+=A2[i];
		if (A1[i]>=10)//进位，小位+1,本位-10 
		{
			A1[i-1]+=1; //最大就是2个19个9相加 ，那么A1[0]就会变成1，所以没问题 
			A1[i]-=10;
		}
	}
	int count=0;//count用于标志0，如果还未到数字位都是0应该跳过，但是数字位中的应该正常读入 
	for(int j=0;j<N;j++)
	{
		if (A1[j]==0&&count==0) //是0就跳过，接着读下一个数字 
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
		printf("0\n");//说明0+0=0； 
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
