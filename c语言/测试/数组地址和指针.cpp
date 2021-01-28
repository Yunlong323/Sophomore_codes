#include <stdio.h>
#include <string.h>
int main()
{
int s[5];
int *p=s;
	printf("%d\t",p-s);
		p=p+4;
		printf("%d\t,p和s[4]的地址：%o %o\n",p-s,p,&s[4]);
		p=s;
		printf("改变后p指向s，p的地址和s的地址为：%o  %o",p,s); 

}
