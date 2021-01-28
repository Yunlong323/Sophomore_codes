#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int A;//想引用第一个file 的A变量 
int main()
{
	int b=10;//a*b
	printf("%d",A*b);
	return 0;
}
//定义变量：为变量分配存储空间
//声明：在这里用一下，不分配空间，不涉及空间分配
/*

定义和声明 只针对全局变量和外部变量
局部变量作用域都在函数内，用完就没了，所以是不会用到声明（除了extern） 
 main{
extern int a,b;//可以使用下面的a,b 
maxint=max(); //去掉extern，就没办法进行了 
}
int a,b;
max()
{
	return a>b?a:b;
}



malloc和free都是在堆中申请的空间（动态内存分配） 
作用域是局部的，生存期由我决定，但如果不free，就会内存泄漏 ，最后申请过多的内存，却没有free
最后内存直接用完，OS直接终结程序
point都是存的地址 4个字节是因为是32位地址（4*8）  
 
*/ 
