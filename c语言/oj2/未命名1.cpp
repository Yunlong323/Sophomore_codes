#include <stdio.h> 
long mod(long a,long b,long m)
{   
    if(!b) return 1;                //�߽紦��
    if(b==1) return a%m;     //�߽紦��
    long ans=mod(a,b/2,m); //������һ��
    ans=ans*ans%m;     //����ֵans����ab/2
    if(b&1) ans=ans*a%m; //�����������
    return ans;             //����ans����abmodm
}
int main()
{
	printf("2^1000000mod1012=%ld",mod(2,1,1));
	return 0;
}
