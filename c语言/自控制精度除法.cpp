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
					store[i]=a/b;//存储每次的结果 
					remain=a%b;
					a=remain*10;
					if (remain*10/b>4&&i==c) //有小数且要四舍五入 
					{
						forward=1;//标志已经进入进位分支 
						if (store[i]!=9)//最后一位进位不影响前面进位 
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
							if (a/b>4)//要进位
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
						else//最后一位是9，影响前面的进位,但不包含第一位 
						{
							int flag=1;//flag==1说明前面要进一位 
							store[c]=0;
							for(int j=c-1;j>=1;j--)//c=1要特殊考虑 
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
								 if (j==1&&flag!=1)//说明是不影响整数部分的进位 
									break;
								 if (j==1&&flag==1)
								{
									//store[j]=0;
									intpart+=1;
									break;
								}
							 }
							 
							 printf("%lld.",intpart);//这些是影响前面进位的数字的打印 
							 for(int k=1;k<=c;k++)
							{
								printf("%lld",store[k]);
							} 
							printf("\n");
							break;
						}
					}
				}
				if (forward==0)//说明不需要进位
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



