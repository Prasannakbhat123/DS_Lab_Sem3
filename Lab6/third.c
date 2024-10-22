#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
	int data[MAX];
	int top1,top2;
}twoStacks;
void init(twoStacks *s){
	s->top1=-1;
	s->top2=MAX;
}
int isFull(twoStacks *s){
	return s->top1==s->top2;
}
int isEmpty1(twoStacks *s){
	return s->top1==-1;
}
int isEmpty2(twoStacks *s){
	return s->top2==MAX;
}
void push1(twoStacks *s,int val){
	if(isFull(s)){
		printf("Stack Overflow");
	}
	s->data[++(s->top1)]=val;
	printf("Pushed %d into stack-1\n",val);
}
void push2(twoStacks *s,int val){
	if(isFull(s))
		printf("Stack Overflow");
	s->data[--(s->top2)]=val;
	printf("Pushed %d into stack-2\n",val);
}
int pop1(twoStacks *s){
	if(isEmpty1(s)){
		printf("Stack-1 Underflow");
		return -1;
	}
	int val=s->data[(s->top1)--];
	printf("Popped %d from stack-1\n",val);
	return val;
}
int pop2(twoStacks *s){
	if(isEmpty2(s)){
		printf("Stack 2 underflow\n");
		return -1;
	}
	int val=s->data[(s->top2)++];
	printf("Popped %d from stack-2\n",val);
	return val;
}
void display1(twoStacks *s){
	if(isEmpty1(s)){
		printf("Stack 1 is empty\n");
	}
	else{
		printf("Stack 1: ");
		for(int i=0;i<=s->top1;i++){
			printf("%d",s->data[i]);
		}
	}
}
void display2(twoStacks *s){
	if(isEmpty2(s))
		printf("Stack 2 is empty\n");
	else{
		printf("Stack 2: ");
		for(int i=MAX-1;i>=s->top2;i--)
			printf("%d",s->data[i]);
	}
}
int main(){
	twoStacks s;
	init(&s);
	int choice,val;
	while(1){
		printf("Menu:\n");
		printf("1.Push to Stack 1\n2.Push to stack 2\n3.Pop from stack 1\n4.Pop fron stack 2\n5.Display stack 1\n6.Display stack 2\n7.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter value to push into stack 1:");
			       scanf("%d",&val);
			       push1(&s,val);
			       break;
			case 2:printf("Enter value to push into stack 2:");
			       scanf("%d",&val);
			       push2(&s,val);
			       break;
			case 3:pop1(&s);
			       break;
			case 4:pop2(&s);
			       break;
			case 5:display1(&s);
			       break;
			case 6:display2(&s);
			       break;
			case 7:printf("Exiting....");
			       exit(0);
			default:printf("Invalid Choice");
		}
	}
	return 0;
}
