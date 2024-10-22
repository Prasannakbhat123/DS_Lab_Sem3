#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct{
	int top;
	int items[max];
}stack;
void push(stack *s,int val){
	if(s->top==max-1)
		printf("Stack Overflow");
	else{
		s->items[++(s->top)]=val;
	}
}
int pop(stack *s){
	if(s->top==-1)
		printf("Underflow");
	return s->items[(s->top)--];
}
void decimalToBinary(int decimal){
	stack s;
	s.top=-1;
	while(decimal>0){
		int rem=decimal%2;
		push(&s,rem);
		decimal/=2;
	}
	while(s.top!=-1){
		printf("%d",pop(&s));
	}
}
int main(){
	int decimal;
	printf("Enter a decimal number:");
	scanf("%d",&decimal);
	printf("Binary representation of %d is:",decimal);
	decimalToBinary(decimal);
	return 0;
}
