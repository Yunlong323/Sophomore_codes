#include <stdio.h>
int main()
{
	//freopen("oj1.txt","r",stdin); 
	int ch;
	int line=0;
	while((ch=getchar())!=EOF)
	{
		int flag=1;	//��־����# 
		while(flag!=2)//�����ڶ���#˵������ѭ������ 
		{
			ch=getchar();
			if (ch=='\n')//�������з����ж���һ���ǲ��ǿո� 
			{
				if ((ch=getchar())!=' '&&ch!=10&&ch!='#')//���ǿո����ʼ������#�ͼ�1 
				line++;//©�����ڣ�asdasdl\n  \n   dadas\nʱ��������һ��\n��ch�ٶ���һ������\n�� 
				if (ch==10) 
			}//�����´�ѭ����ʼchgetchar�ͻ�䵽dadas���Ӷ��ټ�һ�� 
			if (ch=='#')//��Ϊ�ղŶ���\n����Ҫ�жϵ�ǰ�ǲ���#���ϵ���´�Ҫ��Ҫѭ�� 
			flag++;
			if	(flag==2)//��������Ѿ��ӵ���2���Ϳ��Զ�һЩ��־����ʼ�� 
			{
				flag=0;
				printf("%d\n",line);
				line=0;
			//fflush(stdin);
			}
		}
	}
	return 0;
}
