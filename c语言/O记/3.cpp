#include <stdio.h>
int main()
{
 int m,n;
 int sw1,sw2,sw3;
 int re[1000]={0};
 while(scanf("%d %d",&m,&n)!=EOF)
 {
  for(int i=m;i<=n;i++)
  {
   int sw1=i%10;
   int sw2=(i/10)%10;
   int sw3=(i/100)%10;
   int result=sw1*sw1*sw1+sw2*sw2*sw2+sw3*sw3*sw3;
   if (i==result)
    re[i]++;
  }
  int index=0;
  for(int i=m;i<=n;i++)
  {
  
   if (re[i]&&index==0)
   {
    printf("%d",i);
    index=1;
   }
   else if (re[i]&&index==1)
   {
    printf(" %d",i);
    index=1;
   }
  }
  if (index==1)
  printf("\n");
  if (index==0)
  printf("no\n");
 }
 return 0;
}
