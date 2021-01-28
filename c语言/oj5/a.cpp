#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int pipei(char str1[],char str2[],int pos); //从str1的pos位置开始匹配 
int arr_max(int a[],int len,int *flag);
void plongstr(char str1[],char str2[],int maxindex) ;
int main()
{
	char str1[1002],str2[1002];
	while(scanf("%s %s",str1,str2)==2)
	{
		int len1=strlen(str1),len2=strlen(str2);
		int match[1001]={0};//记录str1第i个位置起，匹配到的连续字符个数 
		//abcdd len=5
		//bc len=2 
		for(int i=0;i<=len1-len2;i++)
		{
			match[i]=pipei(str1,str2,i);
		}
		int flag=0;
		int maxindex=0;
		for(int i=0;i<=len1-len2;i++)
		{
			maxindex=arr_max(match,len1-len2,&flag);
		}
		if (flag==0)//说明没有匹配 
		printf("#\n"); 
		else 
		plongstr(str1,str2,maxindex);//从str1的maxindex处开始print出最长的和str2匹配的串 
		
		memset(str1,0,1002);
		memset(str2,0,1002);
	} 

	return 0; 
 }
 int arr_max(int a[],int len,int *flag)//a的最大索引是len，是闭区间 
 {
 	int max=-1;
 	int maxindex=0;
 	for(int i=0;i<=len;i++)
 	{
 		if (a[i]>max)
 		{
 			max=a[i];
 			maxindex=i;
		 }
		 if (a[i]!=0)
		 *flag=1;
	 }
	 return maxindex;
  } 
int pipei(char str1[],char str2[],int pos)//连续字符 
{
	//abcefccc
	// bcdqccc
	// |
	int times[1000]={0};//存放每次打断后，之前连续的字符串 有多长 
	int j=0;  
	if (str1[pos]==str2[0])
	times[j]++;
	for(int i=pos+1,k=1;i<pos+strlen(str2);i++,k++)
	{
		if (str1[i]==str2[k]&&str1[i-1]==str2[k-1])
		{
			times[j]++;
		}
		else if (str1[i]!=str2[k]&&str1[i-1]==str2[k-1])//突然不匹配，换到下一个times求解 
		{
			j++;
		}
		else if (str1[i]==str2[k]&&str1[i-1]!=str2[k-1])//开始第一个匹配，直接计数 
		{
			times[j]++;
		}
		else//尚未匹配到，继续移动 
		continue;
	}
	int emptyflag=0;
	int num=arr_max(times,j,&emptyflag);
	return num;
 } 
void plongstr(char str1[],char str2[],int maxindex) 
{
		//mnbjhjklcacsssdegmls 
		//        aabsssc 
	//maxindex    8 
	char *p=str1+maxindex;
	int maxpos[1000];
	for(int i=0;i<strlen(str2);i++)
	{
		maxpos[i]=pipei(p,str2,i);//记第i个位置后的连续字符个数 
	}
	int i=0;
	for(i=0;i<strlen(str2);i++)//第i个位置必然包含后面的最长子串故到了不相等的地方，就说明该出就是最长子串的索引 
	{
		if (maxpos[i]>maxpos[i])
		break;
	}//注意，i是p的偏移量 
	for(int m=i;m<strlen(str2);m++)
	{
		if (*(p+m)==str2[m])
		printf("%c",str2[m]);
		else
		break;//如果不相等，那说明打印完毕 
	 } 
	 printf("\n");
}
