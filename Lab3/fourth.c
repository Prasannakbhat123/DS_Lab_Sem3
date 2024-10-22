#include<stdio.h>
#include<stdlib.h>
void mul(int **m1,int **m2,int **m3,int r1, int c1,int r2,int c2){
	int i,j,k;
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			for(k=0;k<r2;k++){
				*(*(m3+i)+j)+=(*(*(m1+i)+k)* *(*(m2+k)+j));
}
}
}
}

void main(){
	int r1,c1,r2,c2,i,j;
	printf("Enter the row and column size of first matrix: ");
	scanf("%d %d",&r1,&c1);
	printf("Enter the row and column size of second matrix: ");
	scanf("%d %d",&r2,&c2);
	if(c1!=r2){
		printf("Multiplication not possible!");
		return;
	}
	int **mat1=(int**)malloc(r1*sizeof(int*));
	for(i=0;i<r1;i++)
		mat1[i]=(int*)malloc(c1*sizeof(int));
	printf("Enter the first matrix element: ");
	for(i=0;i<r1;i++)
	       for(j=0;j<c1;j++)
	       		scanf("%d",&mat1[i][j]);
	int **mat2=(int**)malloc(r2*sizeof(int*));
	for(i=0;i<r2;i++)
		mat2[i]=(int*)malloc(c2*sizeof(int));
	printf("Enter the second array elements: ");
	for(i=0;i<r2;i++)
		for(j=0;j<c2;j++)
			scanf("%d",&mat2[i][j]);
	int **mat3=(int**)malloc(r1*sizeof(int*));
	for(i=0;i<r1;i++)
		mat3[i]=(int*)malloc(c2*sizeof(int));
	mul(mat1,mat2,mat3,r1,c1,r2,c2);
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			printf("%d\t",mat3[i][j]);
		}
		printf("\n");
	}
}
