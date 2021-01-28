#include <stdio.h> 
long mod(long a,long b,long m)
{   
    if(!b) 
		return 1;               
    if(b==1)
		return a%m;     
    long ans=mod(a,b/2,m);
    if(b&1) 
	ans=ans*ans*a%m; 
	else
	ans=ans*ans%m ; 
    return ans;             
}
int main()
{
	long a,b;
	while(scanf("%ld %ld",&a,&b)==2)
	{
		printf("%ld\n",mod(a,b,1012));
	 } 
	return 0;
}
