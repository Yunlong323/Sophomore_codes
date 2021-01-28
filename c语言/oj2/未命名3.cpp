#include <stdio.h>
#include <math.h>
int main() {
	double error=1;
	double n1=1;
	double n2=1;
	double qtpi=0;
	int count=1;
	while(fabs(error)>1e-6) {
		qtpi+=error;
		if (count%2==0) {
			n2=fabs(n2)+2;
			count++;
		} else {
			n2=-(fabs(n2)+2);
			count++;
		}
		error=n1/n2;
	}
	printf("%.6f\n",qtpi);
	return 0;
}
