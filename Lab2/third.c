#include<stdio.h>
void tower(int n,char source,char auxiliary,char destination){
	if(n==1){
		printf("Move disk 1 from %c to %c \n",source,destination);
		return;
	}
	tower(n-1,source,destination,auxiliary);
	printf("Move disk %d from %c to %c \n",n,source,destination);
        tower(n-1,auxiliary,source,destination);
}

void main(){
	int n;
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	tower(n,'A','B','C');
}
