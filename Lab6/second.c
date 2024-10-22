#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
typedef struct{
	char data[MAX];
	int top;
}stack;
void init(stack *s){
	s->top=-1;
}
int empty(stack *s){
	return s->top==-1;
}
int full(stack *s){
	return s->top==MAX-1;
}
void push(stack *s,char val){
	if(full(s))
		printf("Stack Overflow\n");
	else s->data[++(s->top)]=val;
}
char pop(stack *s){
	if(empty(s)){
		printf("Stack Underflow\n");
		exit(1);
	}
	return s->data[(s->top)--];
}
int prec(char op){
	switch(op){
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3;
		default:return 0;
	}
}
void rev(char *str){
	int i,j;
	char temp;
	for(i=0,j=strlen(str)-1;i<j;i++,j--){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}
int isOperator(char ch) {
    char operators[] = "+-*/^";
    for (int i = 0; i < sizeof(operators) - 1; i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0; 
}
void infixToPrefix(char *infix, char *prefix){
	stack s;
	init(&s);
	rev(infix);
	int i,k=0;
	for(i=0;i<strlen(infix);i++){
		if(isalnum(infix[i])){
			prefix[k++]=infix[i];
		}
		else if(infix[i]==')'){
			push(&s,infix[i]);
		}
		else if(infix[i]=='('){
			while(!empty(&s)&&s.data[s.top]!=')'){
				prefix[k++]=pop(&s);
			}
			pop(&s);
		}
		else if(isOperator(infix[i])){
			while(!empty(&s)&&prec(s.data[s.top])>prec(infix[i])){
					prefix[k++]=pop(&s);
			}
			push(&s,infix[i]);
		}
	}
	while(!empty(&s)){
		prefix[k++]=pop(&s);
	}
	prefix[k]='\0';
	rev(prefix);
}
int main(){
	char infix[MAX],prefix[MAX];
	printf("Enter an infix expression:");
	scanf("%s",infix);
	infixToPrefix(infix,prefix);
	printf("Prefix expression:%s\n",prefix);
	return 0;
}

