#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//���������ȫ������һ��txt�ĵ���Ȼ�����ж���
//��fgets�����������ݣ�length��ÿ��ֻ��30���ַ�����fp�� 

char *getfileall(char *fname)//��ȡ�����ļ������� 
{
	FILE *fp;
	char *str;
	char txt[1000];
	int filesize;
	if ((fp=fopen(fname,"r"))==NULL){
		printf("���ļ�%s����\n",fname);
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
	while(feof(fp))//ע�⣬��ȡ����ʱ feof ���ж��Ƿ��ļ��ǿյĲ���  ��feof 
	{
		fgets(string,20,fp);
		printf("%s\n",string);
	}
	fprintf(fp,"-print----sajdaijdai---- o\n");
	fprintf(fp,"gogogo\n");
	
	char *p=getfileall("1.txt");
	if (p!=NULL) puts(p);
	printf("�Ѿ���ӡ���ļ���ȫ������");
		fclose(fp);
return 0;	
}


