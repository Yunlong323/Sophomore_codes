#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int A;//����staticֻ�ǲ��ܱ�extern���ã�����ȫ�ֱ�����Ȼ�Ǿ�̬�洢��  extern ֻ�Ǹı���������� 
//static A ������ �����������
//��һ�����������Σ��洢���static extern auto register�� +�������ͣ�int char�� +������
//��extern A���ǶԵģ��ǰѱ���A���Ѷ��壩�������������������Ƕ��� 
int main() 
{
	int b=10;//a*b
	int m;
	scanf("%d %d",&A,&m);
	printf("%d\n",A*m);
	return 0;
}



