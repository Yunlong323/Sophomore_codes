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
//	scanf("%s",str2);//����Ҫ�������룬������������Ұ��㣬�Զ����ȡ����ģ�scanf�Ƕ�buffer��scan��ɨ�衣 
//	scanf("%s",str3);
//		printf("%s\n",str2);
//		printf("%s\n",str3);

//	scanf("%s",str1);//scnafû��%m.ns 
//	//�������5���ַ���Ĭ���Ҷ��룻
////�����ֻ�����9���ַ� ����Ľض� ������str1 ,
//	printf("%5.9s\n",str1);//123    12345    1234567  123456789  1234567890   123456789987456321
//	//����9�������ַ��Ƿ���buffer?���ڣ���Ĳ���ֱ��ɾ���� 
//	scanf("%s",str2);//�˴��������� �ǲ��еģ�˵��buffer���Ѿ�û�ж����ˣ�����printf��%m.ns�����buffer�Ĺ��� 
//	printf("%s",str2); 
//	


//	//�����������%[]����
//	scanf("%[12345678980]",str1) ;
//	printf("%s\n",str1);//1234567890safawfawd56464
//	scanf("%s",str2);
//	printf("%s",str2); 
	//��Ϊֻ����������֣����Ե���s��scanf�Ͳ��ٶ����ַ���ֱ���ж� .������ͬ��%m.ns���printf������ɾ����������ĸ���ֻ���buffer
	//����str2�������������ַ�����
	
	//�������fflush
	 //���buffer
//	int a;
//	char c;
//	scanf("%d%c",&a,&c);//2��huiche�� 
//	printf("a=%d,c=%c/ascii:%d",a,c,c);//�����2(\n)ascii��10
	
	//fflush�ǰ�buufer��գ��ֿ�����
//	int a;
//	char c;
//	scanf("%d",&a);
//	//fflush(stdin);
//	c=getchar();
//	printf("a=%d,c=%c/ascii:%d",a,c,c);//�����fflushע�͵���ͬ��һ������ȥ��ע�ͣ�c�Ϳ�������������
//	//�������£��ȶ���2
	//��ʱ�㰴�˻س����س�����ָ���2��a
	//ͬʱ\n�����buffer
	//��ʱscanfִ�����
	//fflush�������buffer������\n���ٴ���
	//��c��Ҫ���¼��� 

	return 0;
 } 
