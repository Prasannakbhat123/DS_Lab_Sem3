#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct stack{
	int top;
	int arr[max];
}stack;
void push(stack *s,int val){
	if(s->top==max-1){
		printf("Stack overflow");
		return;
	}
	else
		s->arr[++(s->top)]=val;
}
int pop(stack *s){
	if(s->top==-1){
		printf("Stack Underflow");
		return -1;
	}
	else
		return s->arr[(s->top)--];
}
int isEmpty(stack *s){
	if(s->top==-1)
		return 1;
	return 0;
}
void deleteElements(int arr[],int n,int k){
	stack s;
	s.top=-1;
	int count=0;
	for(int i=0;i<n;i++){
		while(!isEmpty(&s)&&s.arr[s.top]<arr[i]&&count<k){
			pop(&s);
			count++;
		}
		push(&s,arr[i]);
	}
	int size=s.top+1;
	int result[size];
	for(int i=size-1;i>=0;i--){
		result[i]=pop(&s);
	}
	for(int i=0;i<size;i++){
		printf("%d\t",result[i]);
	}
}
int main(){
	int n,k;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the number of deletions:");
	scanf("%d",&k);
	if(k>=n){
		printf("K should be less than number of elements ");
		return 1;
	}
	deleteElements(arr,n,k);
	return 0;
}
