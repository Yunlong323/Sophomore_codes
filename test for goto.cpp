#include <stdio.h>
int main()
{
	int a=1,b=3;
	while(a+b<40)
	{
		a+=b;
		b+=a;
		goto DONE;
	}
	DONE:
		printf("%d\t%d",a,b);
		return 0;
	//don't use this in noraml situation.
}
