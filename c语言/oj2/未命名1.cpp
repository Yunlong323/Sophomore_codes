#include <stdio.h> 
long mod(long a,long b,long m)
{   
    if(!b) return 1;                //边界处理
    if(b==1) return a%m;     //边界处理
    long ans=mod(a,b/2,m); //进入下一层
    ans=ans*ans%m;     //返回值ans代表ab/2
    if(b&1) ans=ans*a%m; //奇数情况处理
    return ans;             //返回ans代表abmodm
}
int main()
{
	printf("2^1000000mod1012=%ld",mod(2,1,1));
	return 0;
}
