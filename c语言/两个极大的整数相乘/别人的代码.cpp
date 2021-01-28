#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 500
char a[N],b[N];
int s1[N],s2[N],s3[1000];
int main()
{
 int len1,len2,max,i,j;
 while(scanf("%s%s",a,b)!=EOF)
 {
 memset(s1,0,sizeof(s1));
 memset(s2,0,sizeof(s2));
 memset(s3,0,sizeof(s3));
 len1=strlen(a);
 len2=strlen(b);
 max=0;
 max=len1+len2;
 for(i=0,j=len1-1;i<len1;i++,j--)
 s1[i]=a[j]-'0';
 for(i=0,j=len2-1;i<len2;i++,j--)
 s2[i]=b[j]-'0';
 for(i=0;i<len1;i++)
 for(j=0;j<len2;j++)
 s3[i+j]+=s1[i]*s2[j];
 for(i=0;i<max;i++)
 {
 if(s3[i]>=10)
 {
 s3[i+1]+=s3[i]/10;
 s3[i]%=10;
 }
 }
 while(s3[max-1]==0)
 {
 if(s3[max-1]==0)
 max--;
 }
 if(max<1)
 printf("0");
 else
 for(i=max-1;i>=0;i--)
 printf("%d",s3[i]);
 printf("\n");
 }
 return 0;
}

