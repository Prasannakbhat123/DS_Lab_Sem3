#include<stdio.h>
int *twice(int *p){
	*p=*p*2;
	return p;
}

void main(){
	int *p , **q,a,n;
	printf("Enter a number: ");
	scanf("%d",&n);
	p=&n;
	q=&p;
	p=twice(p);
	printf("The edited number is: %d",*p);
	printf("\nThe number from pointer to pointer is :%d",**q);



}
