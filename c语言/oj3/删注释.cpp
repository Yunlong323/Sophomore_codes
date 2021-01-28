#include <stdio.h> 
#include <string.h>//67%
int main()
{
	char string[300];
	freopen("data.txt","r",stdin);
	int times=0;
	int sit=0;//sit=0,表示不在注释中  
	int note2=0;//   无//类注释 
	int next=1;
	while(gets(string)!=NULL)
	{
		
		if (strlen(string)==0)
		continue; 
		if (strcmp(string,"###")==0)
		{
			times++;
			if (times%2==0)
			{
				note2=0;
				sit=0;
			}
			continue;
		}
		char *p=string;
		while(*p)
		{
			if (*p=='/'&&*(p+1)=='/')
			{
				note2=1;
			}
			else if (*p=='/'&&*(p+1)=='*'||*p=='*'&&*(p+1)=='/')///*  
			{
				sit++;
				//说明这行有/* 需要输出string的/*前内容
				if (sit==1)
				{
					int output=0; 
					char *p2=string;
					while(*p2!='/'&&*(p2+1)!='*')
					{
						putchar(*p2);
						p2++;
						output++;
					}
					if (output!=0)
					printf("\n");
				}
			}
			p++;
			
			if (sit==2)
			{
				p++;//*p=='/'后的一个char 
				if (*p)//    */结束后还有内容 
				{
					while(*p)
					{
						putchar(*p);
						p++;
					 } 
				}
				
				//没字符了，改为非注释部分，继续读 
				sit=0;
				note2=0; 
				next=0;//  出现*/这一行的内容已经完全输出 跳到下一行 
			}
		 } 
		 
		 if (next==0)
		 {
		 	next=1;
		 	continue;
		 }
		 
		 
		if(sit==0)//若不再/**/类注释中 输出string内容 
		{
		
			if (note2==1)//含有//注释 
			{
				int output=0;
				char *p1=string;
				while(*p1)
				{
					if (*p1=='/')
					break;
					else
					putchar(*p1);
					p1++;
					output=1;
				}
				if (output==1)
				{
					printf("\n");
					output=0;
				}
			}
			else
			{
				puts(string);
			 } 
		}
	}
	return 0;
}
//
///* 
//
//1.// 之后不显示
//2./* 之后的状态不显示
//3. /*之前的先显示
//4.*/之后的内容要显
//
//
//
//
//
//1.第一次遍历  是不是在大注释中，确定有没有大小注释，没有 输出
//3.在大注释中，不输出，continue，继续读入判断big的值
//2.若有小注释，没有 大注释，不在大注释中，删去小注释，输出
//4.不在大注释中，有大注释，先输出大注释前的所有字符，再判断大注释是否在本行结束，如果结束
//输出大注释后的内荣。若不再本行结束，就设置标志big 
//
//
//
//
//
//例子：
//int main()//dfsf
///* */{
//	
//int /*skdjajd*/x;
//
//int y=0;/*
//
//printf(zheshizhushi);
//dfgsdg*/    printf("%d\n",x+y);//含有注释
//
///*
//dfgsdg*/    printf("%d\n",x+y);/*asdas*/ int z; //dada 
///*
//dfgsdg*/    printf("%d\n",x+y);/*asdas
//asdad
//*/
//
//return 0; 
//
//} 
//
//1.判断一行内容必须用函数，否则 可以无限嵌套，用递归判断*/之后的内容是否合法，不合法又要递归运算 
// 
//dfgsdg*/    printf("%d\n",x+y);/*asdas*/ int z; /*asdas*/ int z; /*asdas*/ int z; /*asdas*/ int z; 
//*/
//

