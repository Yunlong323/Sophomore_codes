#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	FILE *fp=fopen("test4.txt","w+");
	char a[]="puts in file";
	fputs(a,fp);
	//fputc('\n',fp);
	char b[100]="hello  world";
	fputs(b,fp);
	fclose(fp);
	char result[109];
	printf("display content in the file:\n");
	FILE *fpread=fopen("test4.txt","r");//reason:为什么之前用w+的fp指针不能直接读取，还必须用一个fpread单独读取 

	//fgets(result,100,fpread);
	//puts(result);
	//puts遇到换行就会停止读取，那么换行的内容怎么办？
	//在存的时候可以选择30个30个一个单位，一次读取30个（一行），然后手动增加\n，然后再读取30个。 
	while(!feof(fpread))
	{
		fgets(result,13,fpread);//12个字符的数据，必须用13个读取，自带一个\0必须读入 
		puts(result);//自带换行 
		//putchar('\n');
		
		
		//helloworld 为什么会打印两次呢？
		//feof读取到EOF就退出该循环可能是读取13个字符，最后读到的是\0,还不是EOF
		//所以又读取了，但为什么是helloworld呢，不应该是\0之后的10个元素吗 
	}
	
	
	
	
	
	printf("over\n");
fclose(fp);
	return 0;
}
