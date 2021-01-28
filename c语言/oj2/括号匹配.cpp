#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack {
	char *base;
	char *top;
	int size;
} stack;
int isempty(stack *s);
void init(stack *s);
void push(stack *s,char a);
char pop(stack *s);
void clear(stack *s); 
int main() {
	int num;
	stack s;
	init(&s);
	char string[100];
	while(scanf("%d %s",&num,string)!=EOF) {
		int amount1=0;
		int amount2=0;
		for(int i=0; i<num; i++) {
			if (string[i]=='(') {//2 ((
				amount1++;
				push(&s,string[i]);
				continue;
			} 
			else if (string[i]==')') //(())()
			{
				amount2++;
				if(pop(&s)==0&&i==num-1)//栈空了 
				{
					break;
				}
				continue;
			} 
			else
				continue;
		}
		if (amount1==amount2&&isempty(&s)==1) {//数量相等而且栈空了（（  ）） 
			printf("Yes\n");
		} else { //括号数量不相等肯定不匹配，栈不空肯定不匹配
			printf("No\n");
		}
		//一定要记得清空栈  
		clear(&s);
		
	}
	return 0;
}
void clear(stack *s)
{
	s->top=s->base;
}
int isempty(stack *s) {
	if (s->base==s->top)
		return 1;
	else
		return 0;
}
void init(stack *s) {
	s->base=(char *)malloc(100*sizeof(char));
	s->top=s->base;
	s->size=100;
}
void push(stack *s,char a) {
	*(s->top)=a;
	s->top++;
}
char pop(stack *s) {
	if (isempty(s)!=1)//栈不空 
	{
		s->top--;
	return *(s->top);
	}
	else//栈空了 
	{
		return 0;
	}
}
