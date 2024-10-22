#include<stdio.h>
void Reverse(int* ptr,int n){
	int start=0;
	int end=n-1;
	while(start<end){
		int temp=ptr[start];
		ptr[start]=ptr[end];
		ptr[end]=temp;
		start++;
		end--;
	}
}
void main(){
	int i,a[100],n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	Reverse(a,n);
	printf("After reversing: ");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
}

