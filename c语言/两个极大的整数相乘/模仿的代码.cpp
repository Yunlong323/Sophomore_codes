#include <stdio.h>
#include <string.h> 
int main()
{
	int a[500],b[500];
	char n1[500],n2[500];
	int result[1000]={0};
	while(scanf("%s %s",n1,n2)!=EOF)
	{
		int len1=strlen(n1);
		int len2=strlen(n2);
		int maxlen=len1+len2;
		
		int k=len1-1;
		for(int i=0;i<=len1-1;i++)
		a[i]=n1[k--]-'0';
		k=len2-1;
		for(int j=0;j<=len2-1;j++)
		b[j]=n2[k--]-'0';
		
		if (maxlen==2&&a[0]==0||b[0]==0)
		{
			printf("0\n");
			continue;
		}
		
		for(int i=0;i<=len2-1;i++)
			for(int j=0;j<=len1-1;j++)
				result[i+j]+=a[j]*b[i];
		
		for(int i=0;i<maxlen;i++)
		{
			if (result[i]>=10)
			{
				int m=result[i];
				result[i]=result[i]%10;
				result[i+1]+=(m/10);
			}
		}
		for(int i=maxlen-1;i>=0;i--)
		{
			if (result[i]==0&&i==maxlen-1)//如果没进位，maxlen就多了1位，去掉这个0 
			continue;
			printf("%d",result[i]);
		 } 
		printf("\n");
		memset(result,0,sizeof(result));
		memset(n1,0,sizeof(n1));
		memset(n2,0,sizeof(n2));
	}
	return 0;
}






