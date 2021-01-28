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
		while(n)//对n个排序，每次输出先序 ,从当前这个人开始喊，所以只需要移动m-1步 
		{//1 2 0 4 5 m=3
			if (begin!=0)
				printf(" ");
			int count=0; //count:下次移动指针的次数 
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
					} //此出口出来必定是p为非空 
				}
				else 
				{
					if (p-num==times-1)//1 2 0 0 5
					{
						count++;//2->5 count=2 到了5 count变成3，要先输出5，再改为num 
						
						if (count==m-1)
						break;
						
						while(*p==0)
						{
							if (p-num==times-1)
							p=num;
							p++;
						}//保证指向下一个非空元素 
					}//到了第一个为止可能为空 
					else
					{
						p++;
						count++;
						while(*p==0)
						{
							if (p-num==times-1)
							p=num;
							p++;//保证count后p移动到下一个非空元素 
						 } 
					}
				}												
			}//这样保证每一个出来的p都是非空的 
			printf("%d",*p);// 0 0 0 0 0
			begin=1;
			*p=0;//置0，后移p，同样，保证这个p移动到非0的位置 
			while(*p==0)
			{
				if (p-num==times-1) 
				p=num;
				p++;//若是最后一个，n必定为1，break即可
				if  (n==1)
				break;
			 }  
			n--;
		}
		printf("\n");
	}
	return 0;
}
