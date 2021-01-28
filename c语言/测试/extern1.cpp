#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int A;//加了static只是不能被extern引用，本身全局变量仍然是静态存储的  extern 只是改变变量作用域 
//static A ；不对 ，必须加类型
//对一个变量的修饰：存储类别（static extern auto register） +数据类型（int char） +变量名
//而extern A；是对的，是把变量A（已定义）再声明，是声明，不是定义 
int main() 
{
	int b=10;//a*b
	int m;
	scanf("%d %d",&A,&m);
	printf("%d\n",A*m);
	return 0;
}



