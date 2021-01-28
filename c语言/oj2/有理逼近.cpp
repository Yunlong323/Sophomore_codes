//思路1：
/* 
筛选出所有的X,Y,U,V

sqer(37)=6.3
x/y=6  x/y一定小于6，即y无需继续循环 

for(x=1;x<N;x++)
 	for(y=1;y<N;y++)
 	{
	 	if	(x/y<(int)sqrt(n)||)
	 		break;可以停止对y的继续寻址 
	 		//因为就算你继续增大y，只会离sqrt（n）越来越远
			 //eg:37/6=6.2,37/7=5.6 break 
	 }

for(u=1;u<N;u++)
 	for(v=1;v<N;v++)
 	{
	 	if	(u/v>(int)sqrt(n))
	 		break;可以停止对v的继续寻 
	 }
//u/v=6.5 >6.3  7.6

在集合（X,Y）中筛选出最逼近sqrt（N）的那个
 在集合（U,V）中筛选出最逼近sqrt（N）的那个
X/Y ∈ [(int)sqrt(n)-1,sqrt(n)] 
sub1=sqrt(n)-X/Y if >0 store 
compare sub1 () min
if <,min=sub1,targetx=x,targety=y 


U/V ∈ [sqrt(n),(int)sqrt(n)+1] 

sub2=U/V-sqrt(n) if >0 store 
compare sub2 () min
if <,min=sub2,targetu=u,targetv=v




再打印 
 */
 
 
 
 
 
 
#include <stdio.h>
#include <math.h>
int main()
{
	int x,y,u,v,n,p;//sqrt(p)
	float result1,result2;
	int targetx,targety,targetu,targetv;
	while(scanf("%d %d",&p,&n)==2)
	{
		float min=1,max=1;
		for(x=1;x<=n;x++)
		{
			for(y=1;y<=n;y++)
			{
				result1=1.0*x/y;//result1 > (int)sqrt(n) ,  但一定小于sqrt 
				if (result1<(int)sqrt(p))
				break;
				if (result1-sqrt(p)>0)
				continue;
				//result1 > (int)sqrt(n) , 于sqrt 
				result1=sqrt(p)-result1;
				if (result1<min)
				{
					min=result1;
					targetx=x;
					targety=y;
				}//循环结束找到x/y 在int 和sqrt之间的最靠近sqrt的x/y 
			}
		} 
		printf("%d/%d ",targetx,targety); 
		
		
		for(u=1;u<=n;u++)
		{
			for(v=1;v<=n;v++)
			{
				result2=1.0*u/v;//result2 < (int)sqrt(n)+1 ,  但一定大于sqrt 
				if (result2<(int)sqrt(p))
				break;//u太小。直接下一层u 
				if (result2-sqrt(p)<0)
				break;//result2>int sqrt但仍然太小 ,u继续变大 
				//result1 > (int)sqrt(n) , 于sqrt 
				if (result2>(int)sqrt(p)+1)
				continue; 
				result2=result2-sqrt(p);
				if (result2<max)
				{
					max=result2;
					targetu=u;
					targetv=v;
				}//循环结束找到x/y 在int 和sqrt之间的最靠近sqrt的x/y 
			}
		} 
		printf("%d/%d\n",targetu,targetv); 
	}
	
	return 0;
 } 
