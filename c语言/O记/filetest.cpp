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
	FILE *fpread=fopen("test4.txt","r");//reason:Ϊʲô֮ǰ��w+��fpָ�벻��ֱ�Ӷ�ȡ����������һ��fpread������ȡ 

	//fgets(result,100,fpread);
	//puts(result);
	//puts�������оͻ�ֹͣ��ȡ����ô���е�������ô�죿
	//�ڴ��ʱ�����ѡ��30��30��һ����λ��һ�ζ�ȡ30����һ�У���Ȼ���ֶ�����\n��Ȼ���ٶ�ȡ30���� 
	while(!feof(fpread))
	{
		fgets(result,13,fpread);//12���ַ������ݣ�������13����ȡ���Դ�һ��\0������� 
		puts(result);//�Դ����� 
		//putchar('\n');
		
		
		//helloworld Ϊʲô���ӡ�����أ�
		//feof��ȡ��EOF���˳���ѭ�������Ƕ�ȡ13���ַ�������������\0,������EOF
		//�����ֶ�ȡ�ˣ���Ϊʲô��helloworld�أ���Ӧ����\0֮���10��Ԫ���� 
	}
	
	
	
	
	
	printf("over\n");
fclose(fp);
	return 0;
}
