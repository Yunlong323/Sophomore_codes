//˼·1��
/* 
ɸѡ�����е�X,Y,U,V

sqer(37)=6.3
x/y=6  x/yһ��С��6����y�������ѭ�� 

for(x=1;x<N;x++)
 	for(y=1;y<N;y++)
 	{
	 	if	(x/y<(int)sqrt(n)||)
	 		break;����ֹͣ��y�ļ���Ѱַ 
	 		//��Ϊ�������������y��ֻ����sqrt��n��Խ��ԽԶ
			 //eg:37/6=6.2,37/7=5.6 break 
	 }

for(u=1;u<N;u++)
 	for(v=1;v<N;v++)
 	{
	 	if	(u/v>(int)sqrt(n))
	 		break;����ֹͣ��v�ļ���Ѱ 
	 }
//u/v=6.5 >6.3  7.6

�ڼ��ϣ�X,Y����ɸѡ����ƽ�sqrt��N�����Ǹ�
 �ڼ��ϣ�U,V����ɸѡ����ƽ�sqrt��N�����Ǹ�
X/Y �� [(int)sqrt(n)-1,sqrt(n)] 
sub1=sqrt(n)-X/Y if >0 store 
compare sub1 () min
if <,min=sub1,targetx=x,targety=y 


U/V �� [sqrt(n),(int)sqrt(n)+1] 

sub2=U/V-sqrt(n) if >0 store 
compare sub2 () min
if <,min=sub2,targetu=u,targetv=v




�ٴ�ӡ 
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
				result1=1.0*x/y;//result1 > (int)sqrt(n) ,  ��һ��С��sqrt 
				if (result1<(int)sqrt(p))
				break;
				if (result1-sqrt(p)>0)
				continue;
				//result1 > (int)sqrt(n) , ��sqrt 
				result1=sqrt(p)-result1;
				if (result1<min)
				{
					min=result1;
					targetx=x;
					targety=y;
				}//ѭ�������ҵ�x/y ��int ��sqrt֮������sqrt��x/y 
			}
		} 
		printf("%d/%d ",targetx,targety); 
		
		
		for(u=1;u<=n;u++)
		{
			for(v=1;v<=n;v++)
			{
				result2=1.0*u/v;//result2 < (int)sqrt(n)+1 ,  ��һ������sqrt 
				if (result2<(int)sqrt(p))
				break;//u̫С��ֱ����һ��u 
				if (result2-sqrt(p)<0)
				break;//result2>int sqrt����Ȼ̫С ,u������� 
				//result1 > (int)sqrt(n) , ��sqrt 
				if (result2>(int)sqrt(p)+1)
				continue; 
				result2=result2-sqrt(p);
				if (result2<max)
				{
					max=result2;
					targetu=u;
					targetv=v;
				}//ѭ�������ҵ�x/y ��int ��sqrt֮������sqrt��x/y 
			}
		} 
		printf("%d/%d\n",targetu,targetv); 
	}
	
	return 0;
 } 
