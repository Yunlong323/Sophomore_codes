#include<stdio.h>
#include<math.h>
int main()
{
	int n=10000000001;
	int bool1;
	printf("%f %d",sqrt(n),(int)sqrt(n));
	if (sqrt(n)==(int)sqrt(n))//˫���ȵ����ֿ��Ժ�����ֱ�ӱȴ�С 
	{
		printf("����ȫƽ����\n");
	}
	else
	{
		printf("no\n");
	}
}
