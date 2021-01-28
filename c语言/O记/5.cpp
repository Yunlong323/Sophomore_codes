#include <stdio.h>
#include <string.h>
#include <math.h>
int square(int n);
int main()
{
 int year,month;
 int temp;
 while(scanf("%d",&year)!=EOF)
 {
  //得是闰年才有闰日
  if (year%4==0&&year%100!=0||year%400==0)
  {
  	int times=0;
   for(month=1;month<=12;month++)
   {
   	if (times!=0) break;
   	temp=0;//每次循环temp先清空 
   	switch (month)
   	{
   		case 4:{
   		for(int i=1;i<=30;i++)
   		{
   			temp=year+month*31+i;
   			if (square(temp)==1)
   			{
   				times++;
   				printf("%d %d %d\n",year,month,i);
			   }
		   }
		break;
	   }
	case 6:{
   		for(int i=1;i<=30;i++)
   		{
   			temp=year+month*31+i;
   			if (square(temp)==1)
   			{
   				times++;
   				printf("%d %d %d\n",year,month,i);
			   }
		   }
		break;
	   }
	case 9:{
   		for(int i=1;i<=30;i++)
   		{
   			temp=year+month*31+i;
   			if (square(temp)==1)
   			{
   				times++;
   				printf("%d %d %d\n",year,month,i);
			   }
		   }
		break;
	   }
	case 11:{
   		for(int i=1;i<=30;i++)
   		{
   			temp=year+month*31+i;
   			if (square(temp)==1)
   			{   			times++;

   				printf("%d %d %d\n",year,month,i);
			   }
		   }
		break;
	   }
	case 2:{
   		for(int i=1;i<=29;i++)
   		{
   			temp=year+month*31+i;
   			if (square(temp)==1)
   			{   			times++;

   				printf("%d %d %d\n",year,month,i);
			   }
		   }
		break;
	   }
	default:{
   		for(int i=1;i<=31;i++)
   		{
   			temp=year+month*31+i;
   			if (square(temp)==1)
   			{   			times++;

   				printf("%d %d %d\n",year,month,i);
			   }
		   }
		break;
	   }
	   }
   }
  }
  else
  {
   printf("no leap day\n");
   continue;
  }
 }
 return 0;
}
int square(int n)
{
	int flag=0;
	if (sqrt(n)==(int)sqrt(n))
	return 1;
	else
	return 0;
}
