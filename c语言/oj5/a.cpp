#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int pipei(char str1[],char str2[],int pos); //��str1��posλ�ÿ�ʼƥ�� 
int arr_max(int a[],int len,int *flag);
void plongstr(char str1[],char str2[],int maxindex) ;
int main()
{
	char str1[1002],str2[1002];
	while(scanf("%s %s",str1,str2)==2)
	{
		int len1=strlen(str1),len2=strlen(str2);
		int match[1001]={0};//��¼str1��i��λ����ƥ�䵽�������ַ����� 
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
		if (flag==0)//˵��û��ƥ�� 
		printf("#\n"); 
		else 
		plongstr(str1,str2,maxindex);//��str1��maxindex����ʼprint����ĺ�str2ƥ��Ĵ� 
		
		memset(str1,0,1002);
		memset(str2,0,1002);
	} 

	return 0; 
 }
 int arr_max(int a[],int len,int *flag)//a�����������len���Ǳ����� 
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
int pipei(char str1[],char str2[],int pos)//�����ַ� 
{
	//abcefccc
	// bcdqccc
	// |
	int times[1000]={0};//���ÿ�δ�Ϻ�֮ǰ�������ַ��� �ж೤ 
	int j=0;  
	if (str1[pos]==str2[0])
	times[j]++;
	for(int i=pos+1,k=1;i<pos+strlen(str2);i++,k++)
	{
		if (str1[i]==str2[k]&&str1[i-1]==str2[k-1])
		{
			times[j]++;
		}
		else if (str1[i]!=str2[k]&&str1[i-1]==str2[k-1])//ͻȻ��ƥ�䣬������һ��times��� 
		{
			j++;
		}
		else if (str1[i]==str2[k]&&str1[i-1]!=str2[k-1])//��ʼ��һ��ƥ�䣬ֱ�Ӽ��� 
		{
			times[j]++;
		}
		else//��δƥ�䵽�������ƶ� 
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
		maxpos[i]=pipei(p,str2,i);//�ǵ�i��λ�ú�������ַ����� 
	}
	int i=0;
	for(i=0;i<strlen(str2);i++)//��i��λ�ñ�Ȼ�����������Ӵ��ʵ��˲���ȵĵط�����˵���ó�������Ӵ������� 
	{
		if (maxpos[i]>maxpos[i])
		break;
	}//ע�⣬i��p��ƫ���� 
	for(int m=i;m<strlen(str2);m++)
	{
		if (*(p+m)==str2[m])
		printf("%c",str2[m]);
		else
		break;//�������ȣ���˵����ӡ��� 
	 } 
	 printf("\n");
}
