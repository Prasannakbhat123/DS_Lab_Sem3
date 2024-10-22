#include<stdio.h>
void isPallindrome(int *p,int n){
	int i;
	for(i=0;i<=n/2;i++){
		if(*(p+i)!=*(p+(n-i-1))){
			printf("It is not a pallindrome");
			return;
		}
	}
	printf("It is a pallindrome");
}

void main(){
	int i,a[100],n;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	isPallindrome(a,n);
}
