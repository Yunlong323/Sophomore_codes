#include <stdio.h>
#include <string.h>
int main()
{
int s[5];
int *p=s;
	printf("%d\t",p-s);
		p=p+4;
		printf("%d\t,p��s[4]�ĵ�ַ��%o %o\n",p-s,p,&s[4]);
		p=s;
		printf("�ı��pָ��s��p�ĵ�ַ��s�ĵ�ַΪ��%o  %o",p,s); 

}
