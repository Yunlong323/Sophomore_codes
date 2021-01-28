#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>//ip地址是4个八位2进制数，所以上限就是255 
int main()
{
   	char string[100]={0};
   	while(scanf("%s",string)==1)
   	{
   		int num1,num2,num3,num4;
   		num1=num2=num3=num4=0;
   		char *p=string;

   		while(*p>='0'&&*p<='9')//192.
   		{
   			num1=10*num1+(*p-'0');
			p++;   			
		}
		if (*p!='.')
		{
			printf("NO\n");
			continue;
		}
		else
		p++;
		
		while(*p>='0'&&*p<='9')//192.180.
   		{
   			num2=10*num2+(*p-'0');
			p++;   			
		}
		if (*p!='.')
		{
			printf("NO\n");
			continue;
		}
		else
		p++;
		
		while(*p>='0'&&*p<='9')//192.180.191.
   		{
   			num3=10*num3+(*p-'0');
			p++;   			
		}
		if (*p!='.')
		{
			printf("NO\n");
			continue;
		}
		else
		p++;
		
		while(*p>='0'&&*p<='9')//192.180.191.66
   		{
   			num4=10*num4+(*p-'0');
			p++;   			
		}
		if (*p=='.')
		{
			printf("NO\n");
			continue;
		}
		
		if (num1>=0&&num1<=255&&num2>=0&&num2<=255&&num3>=0&&num3<=255&&num4>=0&&num4<=255)
		{
			printf("YES\n");
			continue;
		}
		else
		{
			printf("NO\n");
			continue;
		}
		
		
	}
	return 0;
 } 
