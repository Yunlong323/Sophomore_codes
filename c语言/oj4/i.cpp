#include <stdio.h>
#include <string.h>
int main()
{
	freopen("data.txt","r",stdin);
	int n=0,m=0;
	while(scanf("%d %d",&n,&m)==2)
	{
		int num[1000]={0};
		for(int i=0;i<n;i++)
			num[i]=i+1;
		int begin=0;//end-> [n-1]
		int *p=num;
		int times=n; 
		while(n)//��n������ÿ��������� ,�ӵ�ǰ����˿�ʼ��������ֻ��Ҫ�ƶ�m-1�� 
		{//1 2 0 4 5 m=3
			if (begin!=0)
				printf(" ");
			int count=0; //count:�´��ƶ�ָ��Ĵ��� 
			while(count!=m-1)
			{
				if (*p==0)//0 2 0 4 0
				{
					while(*p==0)
					{
						if (p-num==times-1)
						{
							p=num;	
						}
						p++;
					} //�˳��ڳ����ض���pΪ�ǿ� 
				}
				else 
				{
					if (p-num==times-1)//1 2 0 0 5
					{
						count++;//2->5 count=2 ����5 count���3��Ҫ�����5���ٸ�Ϊnum 
						
						if (count==m-1)
						break;
						
						while(*p==0)
						{
							if (p-num==times-1)
							p=num;
							p++;
						}//��ָ֤����һ���ǿ�Ԫ�� 
					}//���˵�һ��Ϊֹ����Ϊ�� 
					else
					{
						p++;
						count++;
						while(*p==0)
						{
							if (p-num==times-1)
							p=num;
							p++;//��֤count��p�ƶ�����һ���ǿ�Ԫ�� 
						 } 
					}
				}												
			}//������֤ÿһ��������p���Ƿǿյ� 
			printf("%d",*p);// 0 0 0 0 0
			begin=1;
			*p=0;//��0������p��ͬ������֤���p�ƶ�����0��λ�� 
			while(*p==0)
			{
				if (p-num==times-1) 
				p=num;
				p++;//�������һ����n�ض�Ϊ1��break����
				if  (n==1)
				break;
			 }  
			n--;
		}
		printf("\n");
	}
	return 0;
}
