#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print(int a[],int len);
void bubble(int a[],int len);
int main()
{
	//freopen("data.txt","r",stdin);
	int count;
	int num[25]={0};
	int odd[25]={0};
	int even[25]={0};
	while(scanf("%d",&count)==1)
	{
		int oddindex=0;
		int evenindex=0;
		for(int i=0;i<count;i++)
		{
			scanf("%d",&num[i]);
			if (num[i]%2)
			{
				even[evenindex]=num[i];
				evenindex++;
			}
			else
			{
				odd[oddindex]=num[i];
				oddindex++;
			}
		}
		bubble(even,evenindex);
		bubble(odd,oddindex);
		
		
//			print(odd,oddindex);
//			printf(" ");
//			print(even,evenindex);
//			printf("\n");
				
		
			print(even,evenindex);
			printf(" ");
			print(odd,oddindex);
			printf("\n");
		
	}
	return 0;
 } 
 
 void print(int a[],int len)
 {
 	for(int i=0;i<len;i++)
 	{
 		if (i==0)
 		printf("%d",a[i]);
 		else
 		printf(" %d",a[i]);//1 3 5
	 }
 }
void bubble(int a[],int len)
{
	for(int i=1;i<len;i++)
		for(int j=0;j<len-i;j++)
		{
			if (a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
}
