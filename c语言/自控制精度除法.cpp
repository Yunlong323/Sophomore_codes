#include <stdio.h>
#include <string.h>
int main()
{
	long long int a;
	long long int b;
	int c;
	long long int store[101]={0};
	while(scanf("%lld %lld %d",&a,&b,&c)!=EOF)
	{
		memset(store,0,sizeof(store));
			long long int remain=a%b; 
			long long int intpart=a/b; 
			a=remain*10;
			if (c==0)
			{
				if (remain*10/b>4)
				{
					printf("%lld\n",intpart+1);
					continue;
				}
				else
				{
					printf("%lld\n",intpart);
					continue;
				}
			 } 
			else   //(c>0) 
			{
				int forward=0;
				for(int i=1;i<=c;i++) 
				{
					store[i]=a/b;//�洢ÿ�εĽ�� 
					remain=a%b;
					a=remain*10;
					if (remain*10/b>4&&i==c) //��С����Ҫ�������� 
					{
						forward=1;//��־�Ѿ������λ��֧ 
						if (store[i]!=9)//���һλ��λ��Ӱ��ǰ���λ 
						{
							store[i]+=1;
							printf("%lld.",intpart);
							for(int l=1;l<=c;l++)
							printf("%lld",store[l]); 
							printf("\n");
							break;
						}
						else if (store[i]==9&&c==1)
						{
							int flag=0;
							if (a/b>4)//Ҫ��λ
							{
								printf("%lld.",intpart+1);
								printf("%lld\n",0);
								break;
							 } 
							 else
							 {
							 	printf("%lld.",intpart);
								printf("%lld\n",store[1]);
								break;
							 }
						}
						else//���һλ��9��Ӱ��ǰ��Ľ�λ,����������һλ 
						{
							int flag=1;//flag==1˵��ǰ��Ҫ��һλ 
							store[c]=0;
							for(int j=c-1;j>=1;j--)//c=1Ҫ���⿼�� 
							{
								if (flag==1)
								{
									store[j]+=1;
								}
								if (store[j]==10)
								{
									store[j]-=10;
									flag=1;
								}
								else
								{
									flag=0;
								}
								 if (j==1&&flag!=1)//˵���ǲ�Ӱ���������ֵĽ�λ 
									break;
								 if (j==1&&flag==1)
								{
									//store[j]=0;
									intpart+=1;
									break;
								}
							 }
							 
							 printf("%lld.",intpart);//��Щ��Ӱ��ǰ���λ�����ֵĴ�ӡ 
							 for(int k=1;k<=c;k++)
							{
								printf("%lld",store[k]);
							} 
							printf("\n");
							break;
						}
					}
				}
				if (forward==0)//˵������Ҫ��λ
				{
						printf("%lld.",intpart);
						for(int k=1;k<=c;k++)
						{
							printf("%lld",store[k]);
						}
						printf("\n"); 
				}
		}
	}
	return 0;
}



