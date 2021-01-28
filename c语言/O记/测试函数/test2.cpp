#include <stdio.h>
void int_to_char(int n[],int len,char mult[],int k,int len1);
void add(char s1[],char s2[],int len1,int len2);
void print_arr(char s[],int n);
int strlen(char s1[]);


void *(memset) (void *s,int c,size_t n)
{
	const unsigned char uc = c;
	unsigned char *su;
	for(su =(unsigned char *) s;0 < n;++su,--n)
		*su = uc;
	return s;
}


int main()
{
	char mul1[501];
	char mul2[501];
	char result[500][1002];
	memset(result[0],'0',sizeof(result));
	scanf("%s %s",mul1,mul2);
	char mult1[501];
	memset(mult1,'0',sizeof(mult1));
	char mult2[501];
	memset(mult2,'0',sizeof(mult2));
	int len1=strlen(mul1);
	int len2=strlen(mul2);
	int k1=len1-1;
	int k2=len2-1;
	for(int i=500;i>=0&&k1>=0;i--)
	{
		mult1[i]=mul1[k1--];
	}
	for(int i=500;i>=0&&k2>=0;i--) 
	{
		mult2[i]=mul2[k2--];
	}
	int n1[501]={0};
	int n2[501]={0};
	int temp[501]={0};
	for(int i=500;i>500-len1;i--)
		n1[i]=mult1[i]-'0';
	for(int i=500;i>500-len2;i--)
		n2[i]=mult2[i]-'0';
	for(int k=0;k<len2;k++) 
	{
		for(int i=500;i>=0;i--)
		{
			temp[i]+=n2[500-k]*n1[i];
			if (temp[i]>=10)
			{
				temp[i-1]+=(temp[i]/10);
				temp[i]=temp[i]-(temp[i]/10)*10;
			}	
		} 
		int_to_char(temp,501,result[k],k,len1);
		memset(temp,0,sizeof(temp));		
		
	} 
	for(int k=0;k<len2-1;k++) 
	{
		add(result[k],result[k+1],1002,1002);
	}
	print_arr(result[len2-1],1002); 
	return 0; 
} 
void int_to_char(int n[],int l,char *mult,int k,int len1)
{  
	 int j; 
 	 for(j=1000;j>1000-k;j--)
	 {
	 	mult[j]='0'; 
	  } 
	for(;j>1000-k-len1-1;j--)
	{
		mult[j]=n[l-1]+'0';
		l--; 
	 }  
 }
 
 void add(char s1[],char s2[],int len1,int len2)
{
	int n1[len1-1]={0};
	int n2[len2-1]={0};
	for(int i=len1-2;i>=0;i--)
	{
		n1[i]=s1[i]-'0';
		n2[i]=s2[i]-'0'; 
	 } 
	for(int i=len1-2;i>=0;i--) 
	{
		n2[i]+=n1[i];
		if (n2[i]>=10)
		{
			n2[i-1]+=1;
			n2[i]-=10;
		}
		s2[i]=n2[i]+'0';
	}	
}
void print_arr(char s[],int n)
{
	int count=0;
	for(int i =0;i<n-1;i++)
	{
		if (s[i]!='0') count++;
		
		if (count==0&&s[i]=='0')
		{
			continue;
		}
		else 
		{
			printf("%c",s[i]);
		} 
	}
	printf("\n");
}

int strlen(char s1[])
{
	int length=0;
	while(*(s1+length)!='\0')
	{
		length++;
	}
	return length;
}
