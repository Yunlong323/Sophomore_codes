#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int isprime(int a) { //return 1 ËØÊı
	if (a==1)
		return 0;
	else if (a==2)
		return 1;
	int flag=0;
	for(int i=2; i<sqrt(a)+1; i++) {
		if (a%i==0)
		{
			flag=1;
			break;
		}
	}
	if (flag==1)
		return 0;
	else
		return 1;
}
int main() {
	int a;
	int d;
	int n;
	long long es[100000];
	while(scanf("%d %d %d",&a,&d,&n)==3) {
		int flag=0;
		long long number=0;
		while(flag!=n) {
			for(int i=0; i<100000; i++) {
				es[i]=a+d*i;
				if (isprime(es[i]))
					flag++;
				if (flag==n) {
					number=es[i];
					break;
				}
			}
		}
		printf("%ld\n",number);
		memset(es,0,100000);
	}
	return 0;
}

