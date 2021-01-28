//char s1[]   char s2[]add  


void add(char s1[],char s2[],int len1,int len2)
{
	int n1[len1-1]={0};
	int n2[len2-1]={0};//不需要\0，少一位即可  4-1=3 取0 1 2 
	for(int i=len1-2;i>=0;i--)//i=4-1-1=2 
	{
		n1[i]=s1[i]-'0';
	}
	for(int i=len2-2;i>=0;i--)
	{
		n2[i]=s2[i]-'0';
	}
	for(int i=len1-2;i>=0;i--)
	{
		n2[i]+=n1[i];//i=4-2=2 
		if (n2[i]>=10)
		{
			n2[i-1]+=1;
			n2[i]-=10;
		}
		s2[i]=n2[i]+'0';//s[len1-1=3]是\0   s2[i+1=3]  =\0;s2[2]=n2[2]+0 
	}
	
}

void print_arr(char s[],int n)
{
	for(int i =0;i<n;i++)
	{
		printf("%c",s[i]);
	}
	printf("\n");
}


void int_to_char(int n[],int len,char *mult)
 {
 	for(int i=0;i<len;i++)
 	{
 		mult[i]=n[i]+'0';
	 }
 }
