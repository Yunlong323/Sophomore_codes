#include <stdio.h>
int main()
{
 char s[10000];
 int count=0;
 while(scanf("%s",s)!=EOF)
 {
 
   printf("%s",s);
   count++;
  if (count%3==0)
  printf("\n");
 else 
 printf(" ");
 }
 return 0;
}
