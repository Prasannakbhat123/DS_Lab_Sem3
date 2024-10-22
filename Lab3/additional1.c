#include<stdio.h>
void main(){
	int *p,i,a[100],n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Pointer in forward: ");
	p=a;
	for(i=0;i<n;i++)
		printf("%d\t",*(p+i));
	printf("\nPointers in reverse: ");
	for(i=0;i<n;i++)
		printf("%d\t",*(p+(n-i-1)));
}
