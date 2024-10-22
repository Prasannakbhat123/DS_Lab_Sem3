#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct stack{
	int top;
	char items[max];
}stack;
void initialize(stack *s){
	s->top=-1;
}
int isFull(stack *s){
	if(s->top==max-1)
		return 1;
	else 
		return 0;
}
void push(stack *s,char ch){
	if(isFull(s)){
		printf("Stack Overflow");
	}
	else{
		s->items[++(s->top)]=ch;
		printf("Pushed %c to stack",ch);
	}
}
int isEmpty(stack *s){
	if(s->top==-1)
		return 1;
	else 
		return 0;
}
void pop(stack *s){
	if(isEmpty(s))
		printf("Stack Underflow!");
	else{
		char popped_char=s->items[(s->top)--];
		printf("\nPopped %c from Stack",popped_char);
	}
}
void display(stack *s){
	if(isEmpty(s))
		printf("\nStack is empty");
	else{
		printf("Stack elements from top to bottom:\n");
		for(int i=s->top;i>=0;i--)
			printf("%c\t",s->items[i]);
	}
}
int menu(){
	int choice;
	printf("\n Stack Operations menu:\n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	printf("Chose an operation:");
	scanf("%d",&choice);
	return choice;
}
int main(){
	stack s;
	initialize(&s);
	while(1){
		int choice =menu();
		char ch;
		switch(choice){
			case 1:
			       printf("Enter the character to push");
			       getchar();
		       	       scanf("%c",&ch);	   
		       	       printf("%c",ch);	       
			       push(&s,ch);
			       break;
			case 2:pop(&s);
			       break;
			case 3:display(&s);
			       break;
			case 4:printf("Exiting from the loop");
			       exit(0);
			default:printf("Enter a valid option!");
}

}
return 0;		
}
