#include<stdio.h>
#include<stdlib.h>
int Smallest(int* p,int n){
	int sm=p[0];
	for(int i=1;i<n;i++){
		if(p[i]<sm)
			sm=p[i];
	}
	return sm;
}

void main(){
	int i,n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int sm=Smallest(a,n);
	printf("Smallest= %d",sm);
}

