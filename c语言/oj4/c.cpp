#include <stdio.h>
#include <string.h>
int main()
{
	//freopen("data.txt","r",stdin);
	char string[200][105];
	int i=0;
	while(1)
	{
		if (gets(string[i++])==NULL)
		break;
	}//先存好，现在i-1都有内容
	
	 for(int m=0;m<i-1-1;m++)//冒泡排序 
	 for(int n=0;n<i-2-m;n++)
	 {
	 	if (strcmp(string[n],string[n+1])==1)
	 	{
	 		char s[105]={0};
	 		strcpy(s,string[n]);
	 		strcpy(string[n],string[n+1]);
	 		strcpy(string[n+1],s);
		 }
	 }
	 for(int l=0;l<i-1;l++)//输出 
		puts(string[l]); 

	return 0;
 } 
