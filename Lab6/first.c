#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
typedef struct{
	int data[MAX];
	int top;
}stack;
void initStack(stack *s){
	s->top=-1;
}
int isEmpty(stack *s){
	return s->top==-1;
}
int isFull(stack *s){
	return s->top==MAX-1;
}
void push(stack *s,int val){
	if(isFull(s)){
		printf("Stack Overflow\n");
		return;
	}
	s->data[++(s->top)]=val;
}
int pop(stack *s){
	if(isEmpty(s)){
		printf("Stack Underflow\n");
		exit(1);
	}
	return s->data[(s->top)--];
}
int evaluatePrefix(char*expr){
	stack s;
	initStack(&s);
	int i;
	for(i=strlen(expr)-1;i>=0;i--){
		if(isdigit(expr[i]))
			push(&s,expr[i]-'0');
		else if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'){
			int operand1=pop(&s);
			int operand2=pop(&s);
			switch(expr[i]){
				case '+':push(&s,operand1+operand2);
					 break;
				case '-':push(&s,operand1-operand2);
					 break;
				case '*':push(&s,operand1*operand2);
					 break;
				case '/':if(operand2==0){
						 printf("Division by zer error\n");
						 exit(1);
					 }
					 push(&s,operand1/operand2);
					 break;
			}
		}
	}
	return pop(&s);
}
int main(){
	char expr[MAX];
	printf("Enter a prefix expression: ");
	scanf("%s",expr);
	int result=evaluatePrefix(expr);
	printf("The result is:%d\n",result);
	return 0;
}


