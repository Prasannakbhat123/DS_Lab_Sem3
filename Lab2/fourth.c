#include<stdio.h>
void swap(int a[10],int i,int j){
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void SelectionSort(int a[10],int n,int i){
	if(i==n-1) return;
	int min_index=i;
	for (int j=i+1;j<n;j++){
		if(a[j]<a[min_index]){
			min_index=j;
		}
	}
	swap(a,i,min_index);
	SelectionSort(a,n,i+1);
}
void main(){
	int a[10],i,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	SelectionSort(a,n,0);
	printf("Array after sorting: ");
	for(i=0;i<n;i++) printf("%d \t",a[i]);
}
