#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//把输出内容全部打入一个txt文档，然后逐行读出
//用fgets函数（行内容，length（每行只有30个字符），fp） 

char *getfileall(char *fname)//读取整个文件的内容 
{
	FILE *fp;
	char *str;
	char txt[1000];
	int filesize;
	if ((fp=fopen(fname,"r"))==NULL){
		printf("打开文件%s错误\n",fname);
		return NULL;
	}
 
	fseek(fp,0,SEEK_END); 
 
	filesize = ftell(fp);
	str=(char *)malloc(filesize);
	str[0]=0;
 
	rewind(fp);
	while((fgets(txt,1000,fp))!=NULL){
		strcat(str,txt);
	}
	fclose(fp);
	return str;
}




int main()
{
	FILE *fp=fopen("1.txt","w+");
	char storename[20];
	scanf("%s",storename);
	fputs(storename,fp);
	
	fputs("-------------------",fp);
	fputs("-----sajdaijdai---- o",fp);
	char string[20];
	while(feof(fp))//注意，读取结束时 feof ，判断是否文件是空的才是  ！feof 
	{
		fgets(string,20,fp);
		printf("%s\n",string);
	}
	fprintf(fp,"-print----sajdaijdai---- o\n");
	fprintf(fp,"gogogo\n");
	
	char *p=getfileall("1.txt");
	if (p!=NULL) puts(p);
	printf("已经打印了文件的全部内容");
		fclose(fp);
return 0;	
}


