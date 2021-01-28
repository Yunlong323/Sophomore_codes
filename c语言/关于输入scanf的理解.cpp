#include <stdio.h>
int main()
{
	char str1[10],str2[10],str3[10];
//	scanf("%3s%2s%3s",str1,str2,str3); //123456789
//	printf("str1:%s",str1);
//	printf("str2:%s",str2);
//	printf("str3:%s",str3);

//	scanf("%s",str1);// i lobe you
//	printf("%s\n",str1);
//	scanf("%s",str2);//不需要你在输入，你输完上面的我爱你，自动会读取下面的，scanf是对buffer的scan，扫描。 
//	scanf("%s",str3);
//		printf("%s\n",str2);
//		printf("%s\n",str3);

//	scanf("%s",str1);//scnaf没有%m.ns 
//	//最少输出5个字符，默认右对齐；
////但最多只能输出9个字符 ，多的截断 不读入str1 ,
//	printf("%5.9s\n",str1);//123    12345    1234567  123456789  1234567890   123456789987456321
//	//多于9的输入字符是否还再buffer?不在，多的部分直接删除。 
//	scanf("%s",str2);//此处不做输入 是不行的，说明buffer中已经没有东西了，所以printf中%m.ns有清空buffer的功能 
//	printf("%s",str2); 
//	


//	//下面介绍正则%[]输入
//	scanf("%[12345678980]",str1) ;
//	printf("%s\n",str1);//1234567890safawfawd56464
//	scanf("%s",str2);
//	printf("%s",str2); 
	//因为只允许读入数字，所以到了s，scanf就不再读入字符，直接切断 .不过不同于%m.ns这个printf的特殊删除操作，字母部分还在buffer
	//所以str2可以正常读入字符部分
	
	//下面介绍fflush
	 //清空buffer
//	int a;
//	char c;
//	scanf("%d%c",&a,&c);//2（huiche） 
//	printf("a=%d,c=%c/ascii:%d",a,c,c);//结果：2(\n)ascii：10
	
	//fflush是把buufer清空，分开做：
//	int a;
//	char c;
//	scanf("%d",&a);
//	//fflush(stdin);
//	c=getchar();
//	printf("a=%d,c=%c/ascii:%d",a,c,c);//如果把fflush注释掉就同上一个程序，去掉注释，c就可以正常读入了
//	//例程如下：先读入2
	//此时你按了回车，回车传递指令，让2给a
	//同时\n入队列buffer
	//此时scanf执行完毕
	//fflush，清空了buffer，所以\n不再存在
	//故c需要重新加入 

	return 0;
 } 
