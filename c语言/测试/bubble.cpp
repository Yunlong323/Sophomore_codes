#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print(int a[],int len);
void bubble(int a[],int len);
int main()
{
	int a[10]={1,6,9,8,3,4,2,6,7,0};
	print(a,10);
	printf("\n");
	bubble(a,10);
		print(a,10);
	printf("\n");
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
