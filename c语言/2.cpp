#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct out{
	char na[1005];
	int len;
}out;
int main()
{
	char str1[1005],str2[1005];
	while(scanf("%s %s",str1,str2)==2)
	{
		getchar();
		out string={{0},0};
		char *p1=str1,*p2=str2;
		int flag=0;
		while(p1-str1!=strlen(str1)-strlen(str2)+1)
		{
			int length=0;
			char *origin=p1;
			
			while(p2-str2!=strlen(str2)) 
			{
				char* org=p2;//¼ÇÂ¼³õÊ¼Î»ÖÃ 
				while(*p2==*p1)
				{
					p2++;
					p1++;
					length++;
				}
				if (length>string.len)
				{
					string.len=length;
					p2=org;
					int i=0;
					while(p2-org!=length)
					{
						string.na[i++]=*p2;
						p2++;
					}
					string.na[i]=0;
				}
				p2=p2+length;
			}
			
			p2=str2;
			p1=origin;
			
			
			if (length>string.len)
			{
				flag=1;
				int i=0;
				for(i=0;i<length;i++)
				{
					string.na[i]=*p1;
					p1++;
				}
				string.na[i]=0;
				string.len=length;
			}
			p1=origin+1;
		}
		if (flag!=0)
			puts(string.na);
		else
			printf("#\n");
	}
	return 0;
}
